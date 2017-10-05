/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#include <unistd.h>

#include "engine/db/ObjectDatabaseManager.h"

#include "TaskWorkerThread.h"

#include "TaskManagerImpl.h"

#include "TaskScheduler.h"

#include "system/lang/Math.h"

#define BASECLIENT_WORKER_THREADS 8

int TaskManagerImpl::DEFAULT_WORKER_QUEUES = 0;
int TaskManagerImpl::DEFAULT_WORKER_THREADS_PER_QUEUE = 0; //
int TaskManagerImpl::DEFAULT_SCHEDULER_THREADS = 0;
int TaskManagerImpl::DEFAULT_IO_SCHEDULERS = 0;

TaskManagerImpl::TaskManagerImpl() : Mutex("TaskManager"), Logger("TaskManager") {
	shuttingDown = false;

#ifdef WITH_STM
	serialWorker = NULL;
#endif

	setInfoLogLevel();
}

TaskManagerImpl::~TaskManagerImpl() {
	for (int i = taskQueues.size() - 1; i >= 0 ; --i) {
		delete taskQueues.get(i);
	}
}

void TaskManagerImpl::initialize() {
	initialize(DEFAULT_WORKER_QUEUES, DEFAULT_SCHEDULER_THREADS, DEFAULT_IO_SCHEDULERS);

#ifdef LOCKFREE_BCLIENT_BUFFERS
	initializeCustomQueue("_baseclient", BASECLIENT_WORKER_THREADS, true, false);
#endif
}

void TaskManagerImpl::initializeCustomQueue(const String& queueName, int numberOfThreads, bool blockDuringSaveEvent, bool start) {
	Locker locker(this);

	int maxCpus = Math::max(1, (int) sysconf(_SC_NPROCESSORS_ONLN));

	TaskQueue* queue = new TaskQueue(queueName.toCharArray());
	queue->setLogLevel(getLogLevel());
	taskQueues.add(queue);

	Vector<TaskWorkerThread*> localWorkers;

	for (int i = 0; i < numberOfThreads; ++i) {
		TaskWorkerThread* worker = new TaskWorkerThread("TaskWorkerThread-" + queueName + String::valueOf(i), queue, workers.size() % maxCpus, blockDuringSaveEvent);
		worker->setLogLevel(getLogLevel());
		workers.add(worker);
		localWorkers.add(worker);
	}

	customQueues.put(queueName, taskQueues.size() - 1);

	if (!start)
		return;

	for (int i = 0; i < localWorkers.size(); ++i) {
		localWorkers.get(i)->start();
	}
}

void TaskManagerImpl::initialize(int workerCount, int schedulerCount, int ioCount) {
	ObjectDatabaseManager::instance()->setLogLevel(getLogLevel());

	Locker locker(this);

	int maxCpus = Math::max(1, (int) sysconf(_SC_NPROCESSORS_ONLN));

	if (workerCount == 0) {
		workerCount = Math::max(8, maxCpus + 2);
		DEFAULT_WORKER_QUEUES = workerCount;
	}

	if (DEFAULT_WORKER_THREADS_PER_QUEUE < 1) {
		DEFAULT_WORKER_THREADS_PER_QUEUE = 1;
	}

	if (schedulerCount == 0) {
		schedulerCount = workerCount;
	}

	if (ioCount == 0) {
		ioCount = schedulerCount / 2;
	}

	for (int j = 0; j < workerCount; ++j) {
		TaskQueue* queue = new TaskQueue();
		queue->setLogLevel(getLogLevel());
		taskQueues.add(queue);

		for (int i = 0; i < DEFAULT_WORKER_THREADS_PER_QUEUE; ++i) {
			TaskWorkerThread* worker = new TaskWorkerThread("TaskWorkerThread" + String::valueOf(j), queue,
															(j + i) % maxCpus, true);
			worker->setLogLevel(getLogLevel());
			workers.add(worker);
		}
	}

#ifdef WITH_STM
	serialWorker = new TaskWorkerThread("TaskSerialWorkerThread", &serialTaskQueue);

	workers.add(serialWorker);
#endif

	for (int i = 0; i < schedulerCount; ++i) {
		TaskScheduler* scheduler = new TaskScheduler("TaskScheduler" + String::valueOf(i));
		scheduler->setTaskManager(this);
		scheduler->setLogLevel(getLogLevel());

		schedulers.add(scheduler);
	}

	for (int i = 0; i < ioCount; ++i) {
		TaskScheduler* scheduler = new TaskScheduler("IoTaskScheduler" + String::valueOf(i));
		scheduler->setTaskManager(this);
		scheduler->setLogLevel(getLogLevel());

		ioSchedulers.add(scheduler);
	}
	
	StringBuffer msg;
	msg << "initialized";
	debug(msg);
}

void TaskManagerImpl::start() {
	Locker locker(this);

	for (int i = 0; i < workers.size(); ++i) {
		TaskWorkerThread* worker = workers.get(i);
		worker->start();
	}

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);
		scheduler->start();
	}

	for (int i = 0; i < ioSchedulers.size(); ++i) {
		TaskScheduler* scheduler = ioSchedulers.get(i);
		scheduler->start();
	}

	StringBuffer msg;
	msg << "started";
	debug(msg);
}

void TaskManagerImpl::setLogLevel(int level) {
	Logger::setLogLevel(static_cast<Logger::LogLevel>(level));
}

void TaskManagerImpl::shutdown() {
	shuttingDown = true;

	while (!schedulers.isEmpty()) {
		lock();

		Reference<TaskScheduler*> scheduler = schedulers.remove(0);

		unlock();

		scheduler->stop();
	}

	while (!ioSchedulers.isEmpty()) {
		lock();

		Reference<TaskScheduler*> scheduler = ioSchedulers.remove(0);

		unlock();

		scheduler->stop();
	}

	Vector<TaskQueue*> queues;

	while (!taskQueues.isEmpty()) {
		TaskQueue* taskQueue = taskQueues.remove(0);
		taskQueue->flush();

		queues.add(taskQueue);
	}

	while (!workers.isEmpty()) {
		lock();

		Reference<TaskWorkerThread*> worker = workers.remove(0);

		unlock();

		worker->stop();
	}

	for (int i = 0; i < queues.size(); ++i) {
		delete queues.get(i);
	}

	debug("stopped");
}

Vector<Locker*>* TaskManagerImpl::blockTaskManager() {
	//Locker locker(this);

	Vector<Locker*>* lockers = new Vector<Locker*>();

	for (int i = 0; i < workers.size(); ++i) {
//		if (i == 9 || i == 7) //mysql and bas packet handler workers should continue
//			continue;
			
		TaskWorkerThread* worker = workers.get(i);

		if (!worker->doBlockWorkerDuringSave())
			continue;

		worker->setPause(true);
	}

	for (int i = 0; i < workers.size(); ++i) {
		TaskWorkerThread* worker = workers.get(i);

		if (!worker->doBlockWorkerDuringSave())
			continue;

		Mutex* blockMutex = worker->getBlockMutex();

		Locker* locker = new Locker(blockMutex);
		lockers->add(locker);

		worker->setPause(false);
	}

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);

		scheduler->setPause(true);
	}

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);

		Mutex* blockMutex = scheduler->getBlockMutex();

		Locker* locker = new Locker(blockMutex);
		lockers->add(locker);

		scheduler->setPause(false);
	}

//#ifndef VERSION_PUBLIC
	for (int i = 0; i < ioSchedulers.size(); ++i) {
		TaskScheduler* scheduler = ioSchedulers.get(i);

		scheduler->setPause(true);
	}

	for (int i = 0; i < ioSchedulers.size(); ++i) {
		TaskScheduler* scheduler = ioSchedulers.get(i);

		Mutex* blockMutex = scheduler->getBlockMutex();

		Locker* locker = new Locker(blockMutex);
		lockers->add(locker);

		scheduler->setPause(false);
	}
//#endif

	return lockers;
}

void TaskManagerImpl::unblockTaskManager(Vector<Locker*>* lockers) {
	for (int i = 0; i < lockers->size(); ++i)
		delete lockers->get(i);

	lockers->removeAll();
}

TaskScheduler* TaskManagerImpl::getIoTaskScheduler() {
	//Locker locker(this);

	if (ioSchedulers.isEmpty()) {
		if (!shuttingDown)
			throw Exception("No schedulers available");
		else
			return NULL;
	}

	int index = currentTaskScheduler.increment() % ioSchedulers.size();

	return ioSchedulers.get(index);
}

TaskScheduler* TaskManagerImpl::getTaskScheduler() {
	//Locker locker(this); no need for this all is atomic

	if (schedulers.isEmpty()) {
		if (!shuttingDown)
			throw Exception("No schedulers available");
		else
			return NULL;
	}

	int index = currentTaskScheduler.increment() % schedulers.size();

	return schedulers.get(index);
}

void TaskManagerImpl::setTaskScheduler(Task* task, TaskScheduler* scheduler) {
	if (!task->setTaskScheduler(scheduler))
		throw IllegalArgumentException("task is already scheduled");
}

void TaskManagerImpl::executeTask(Task* task) {
	if (shuttingDown)
		return;

	const String& custQueue = task->getCustomTaskQueue();

	if (custQueue.length()) {
		executeTask(task, custQueue);
	} else {
		taskQueues.get(currentTaskQueue.increment() % DEFAULT_WORKER_QUEUES)->push(task);
	}
}

void TaskManagerImpl::executeTask(Task* task, int taskqueue) {
	if (shuttingDown)
		return;

	taskQueues.get(taskqueue)->push(task);
}

void TaskManagerImpl::executeTask(Task* task, const String& customTaskQueue) {
	if (shuttingDown)
		return;

	int find = customQueues.find(customTaskQueue);

	if (find == -1) {
		throw Exception("custom queue " + customTaskQueue + " not found");
	}

	int val = customQueues.elementAt(find).getValue();

	taskQueues.get(val)->push(task);
}

void TaskManagerImpl::executeTaskFront(Task* task) {
	if (shuttingDown)
		return;

	const String& custQueue = task->getCustomTaskQueue();

	if (custQueue.length()) {
		executeTask(task, custQueue);
	} else {
		taskQueues.get(currentTaskQueue.increment() % DEFAULT_WORKER_QUEUES)->pushFront(task);
	}
}

void TaskManagerImpl::executeTaskRandom(Task* task) {
	if (shuttingDown)
		return;

	const String& custQueue = task->getCustomTaskQueue();

	if (custQueue.length()) {
		executeTask(task, custQueue);
	} else {
		taskQueues.get(currentTaskQueue.increment() % DEFAULT_WORKER_QUEUES)->pushRandom(task);
	}
}

void TaskManagerImpl::executeTasks(const Vector<Task*>& taskList) {
	if (shuttingDown)
		return;

	taskQueues.get(currentTaskQueue.increment() % DEFAULT_WORKER_QUEUES)->pushAll(taskList);
}

bool TaskManagerImpl::getNextExecutionTime(Task* task, Time& nextExecutionTime) {
	nextExecutionTime = task->getNextExecutionTime();

	return true;
}

bool TaskManagerImpl::isTaskScheduled(Task* task) {
	return task->getTaskScheduler() != NULL;
}

void TaskManagerImpl::scheduleIoTask(Task* task, uint64 delay) {
	if (shuttingDown)
		return;

	Locker locker(this);

	if (task->isScheduled()) {
#ifdef TRACE_TASKS
		task->printScheduleTrace();
#endif

		throw IllegalArgumentException("task is already scheduled");
	}

	TaskScheduler* scheduler = getIoTaskScheduler();
	if (scheduler == NULL)
		return;

#ifdef LOCKFREE_BCLIENT_BUFFERS
	task->setCustomTaskQueue("_baseclient");
#endif

	locker.release();

	if (!scheduler->scheduleTask(task, delay))
		throw IllegalArgumentException("Task was invalid for scheduling");
}

void TaskManagerImpl::scheduleIoTask(Task* task, Time& time) {
	if (shuttingDown)
		return;

	Locker locker(this);

	if (task->isScheduled()) {
#ifdef TRACE_TASKS
		task->printScheduleTrace();
#endif

		throw IllegalArgumentException("task is already scheduled");
	}

	TaskScheduler* scheduler = getIoTaskScheduler();
	if (scheduler == NULL)
		return;

#ifdef LOCKFREE_BCLIENT_BUFFERS
	task->setCustomTaskQueue("_baseclient");
#endif

	locker.release();

	if (!scheduler->scheduleTask(task, time))
		throw IllegalArgumentException("Task was invalid for scheduling");
}

void TaskManagerImpl::scheduleTask(Task* task, uint64 delay) {
	if (shuttingDown)
		return;

	Locker locker(this);

	if (task->isScheduled()) {
	#ifdef TRACE_TASKS
		task->printScheduleTrace();
	#endif

		throw IllegalArgumentException("task is already scheduled");
	}

	TaskScheduler* scheduler = getTaskScheduler();
	if (scheduler == NULL)
		return;

	locker.release();

	if (!scheduler->scheduleTask(task, delay))
		throw IllegalArgumentException("Task was invalid for scheduling");
}

void TaskManagerImpl::scheduleTask(Task* task, Time& time) {
	if (shuttingDown)
		return;

	Locker locker(this);

	if (task->isScheduled()) {
	#ifdef TRACE_TASKS
		task->printScheduleTrace();
	#endif

		throw IllegalArgumentException("task is already scheduled");
	}

	TaskScheduler* scheduler = getTaskScheduler();
	if (scheduler == NULL)
		return;

	locker.release();

	if (!scheduler->scheduleTask(task, time))
		throw IllegalArgumentException("Task was invalid for scheduling");
}

void TaskManagerImpl::rescheduleIoTask(Task* task, uint64 delay) {
	task->acquire();

	cancelTask(task);

	scheduleIoTask(task, delay);

	task->release();
}

void TaskManagerImpl::rescheduleIoTask(Task* task, Time& time) {
	task->acquire();

	cancelTask(task);

	scheduleIoTask(task, time);

	task->release();
}

void TaskManagerImpl::rescheduleTask(Task* task, uint64 delay) {
	task->acquire();

	cancelTask(task);

	scheduleTask(task, delay);

	task->release();
}

void TaskManagerImpl::rescheduleTask(Task* task, Time& time) {
	task->acquire();

	cancelTask(task);

	scheduleTask(task, time);

	task->release();
}

bool TaskManagerImpl::cancelTask(Task* task) {
	Locker locker(this);

	if (!task->isScheduled())
		return false;

	TaskScheduler* scheduler = task->getTaskScheduler();
	//assert (scheduler != NULL);

	locker.release();

	if (scheduler == NULL)
		return false;

	return scheduler->cancelTask(task);
}

void TaskManagerImpl::flushTasks() {
	Locker locker(this);

	//tasks.flush();
	
	for (int i = 0; i < taskQueues.size(); ++i) {
		taskQueues.get(i)->flush();
	}

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);

		scheduler->flushTasks();
	}

}

template<class M, class S>
uint64 orderStatistics(M& ordered, S& tasksCount) {
	auto iterator = tasksCount.iterator();
	uint64 totalRuntime = 0;

	while (iterator.hasNext()) {
		typename S::key_type* name;
		typename S::value_type* count;

		iterator.getNextKeyAndValue(name, count);

		ordered.put(*count, *name);
		totalRuntime += count->totalRunTime;
	}

	return totalRuntime;
};

uint64 orderStatisticsMap(VectorMap<RunStatistics, String>& ordered, const VectorMap<String, RunStatistics>& tasksCount) {
	uint64 totalRuntime = 0;

	for (const auto& entry : tasksCount) {
		const auto& count = entry.getValue();
		const auto& name = entry.getKey();

		ordered.put(count, name);

		totalRuntime += count.totalRunTime;
	}

	return totalRuntime;
};

String formatDots(uint64 n)  {
	int c;
	char buf[128];
	char *p;
	char outBuf[128];
	char *out;

	sprintf(buf, "%llu", n);
	c = 2 - strlen(buf) % 3;
	for (p = buf, out = outBuf; *p != 0; p++) {
		*out++ = *p;
		if (c == 1) {
			*out++ = '.';
		}
		c = (c + 1) % 3;
	}
	*--out = 0;

	return String(outBuf);
}

template<class M>
void printStatistics(StringBuffer& msg4, M& ordered, bool demangle) {
	for (int i = 0, j = ordered.size() - 1; i < 5 && (j - i) >= 0; ++i) {
		int index = j - i;
		auto& entry = ordered.elementAt(index);
		auto& stats = entry.getKey();
		auto& name = entry.getValue();
		uint64 averageTime = 0;

		if (stats.totalRunCount) {
			averageTime = stats.totalRunTime / stats.totalRunCount;
		}

		String taskName = name;

		if (demangle) {
#if GCC_VERSION >= 40100
			int stat;
			char* demangled = abi::__cxa_demangle(taskName.toCharArray(), 0, 0, &stat);

			if (stat == 0) {
				taskName = demangled;

				free(demangled);
			}
#endif
		}

		msg4 << "\t" << taskName << ": totalRunTime = " << formatDots(stats.totalRunTime / 1000000000) <<  "s averageTime = " << formatDots(averageTime)
			 << "ns maxRunTime = " << formatDots(stats.maxRunTime)
			 << "ns totalRunCount = " << formatDots(stats.totalRunCount) << " minRunTime = " << formatDots(stats.minRunTime) << "ns" << endl;
	}
};


String TaskManagerImpl::getInfo(bool print) {
	Locker guard(this);

	StringBuffer msg;
//	msg << "executing tasks - " << getExecutingTaskSize();

	for (int i = 0; i < taskQueues.size(); ++i) {
		msg << "executing tasks in queue" << i << " " << taskQueues.get(i)->size() << endl;
	}

	if (print)
		info(msg);

	StringBuffer msg2;
	msg2 << "scheduled tasks: " << getScheduledTaskSize() << endl;

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);

		HashTable<const char*, uint64> tasksCount = scheduler->getTasksCount();

		//lets order them
		VectorMap<uint64, const char*> ordered;

		HashTableIterator<const char*, uint64> iterator = tasksCount.iterator();

		while (iterator.hasNext()) {
			const char* name;
			uint64 count;

			iterator.getNextKeyAndValue(name, count);

			ordered.put(count, name);
		}

		msg2 << "scheduled tasks in scheduler " << i << ": " << scheduler->getQueueSize();
		msg2 << " pushed: " << scheduler->getPushedTasks() << " popped: " << scheduler->getPoppedTasks() << " removed: " << scheduler->getRemovedTasks() << endl;

		//lets print top 5
		for (int i = 0, j = ordered.size() - 1; i < 5 && (j - i) >= 0; ++i) {
			int index = j - i;
			msg2 << "\t" << ordered.elementAt(index).getValue() << ":" << ordered.elementAt(index).getKey() << endl;
		}
	}

	if (print)
		info(msg2);

	StringBuffer msg3;
	msg3 << "io scheduled tasks - " << getIoScheduledTaskSize();

	if (print)
		info(msg3);

	StringBuffer msg4;

#ifdef COLLECT_TASKSTATISTICS
	for (int i = 0; i < workers.size(); ++i) {
		TaskWorkerThread* worker = workers.get(i);

		HashTable<const char*, RunStatistics> tasksCount = worker->getTasksStatistics();
		VectorMap<RunStatistics, const char*> ordered(tasksCount.size(), 2);
		VectorMap<RunStatisticsOrderedByMaxTime, const char*> orderedByMaxTime(tasksCount.size(), 2);

		//lets order them
		auto totalRuntimeTasks = orderStatistics(ordered, tasksCount);

		msg4 << "total runtime: " << totalRuntimeTasks / 1000000000 << "s distinct tasks recorded in worker " << worker->getLoggingName() << ": " << tasksCount.size() << endl;

		//lets print top 5
		printStatistics(msg4, ordered, true);

		msg4 << endl;

		//order by max time
		orderStatistics(orderedByMaxTime, tasksCount);
		printStatistics(msg4, orderedByMaxTime, true);

		//now lets print lua tasks
		auto luaTasksCount = worker->getLuaTasksStatistics();
		VectorMap<RunStatistics, String> luaOrdered(luaTasksCount.size(), 2);

		auto totalRuntimeLua = orderStatisticsMap(luaOrdered, luaTasksCount);

		msg4 << "lua total runtime: " << totalRuntimeLua / 1000000000 <<  "s distinct lua tasks recorded in worker " << i << ": " << luaTasksCount.size() << endl;

		//lets print top 5
		printStatistics(msg4, luaOrdered, false);

		//now lets print bdb read latency
		auto bdbTasksCount = worker->getBDBReadStatistics();
		VectorMap<RunStatistics, String> bdbOrdered(bdbTasksCount.size(), 2);

		auto totalRuntimeBDB = orderStatisticsMap(bdbOrdered, bdbTasksCount);

		msg4 << "bdb read total runtime: " << totalRuntimeBDB / 1000000000 <<  "s distinct bdb databases in worker " << i << ": " << bdbTasksCount.size() << endl;

		//lets print top 5
		printStatistics(msg4, bdbOrdered, false);

		//now lets print mysql stats
		auto mysqlTasksCount = worker->getMysqlStatistics();
		VectorMap<RunStatistics, String> mysqlOrdered(mysqlTasksCount.size(), 2);

		auto totalRuntimeMysql = orderStatisticsMap(mysqlOrdered, mysqlTasksCount);

		msg4 << "mysql total runtime: " << totalRuntimeMysql / 1000000000 <<  "s distinct mysql queries in worker " << i << ": " << mysqlTasksCount.size() << endl;

		//lets print top 5
		printStatistics(msg4, mysqlOrdered, false);


		msg4 << endl;
	}

	if (print)
		info(msg4);
#endif

	msg << endl << msg2.toString() << endl << msg3.toString() << endl << msg4.toString();
	return msg.toString();
}

void TaskManagerImpl::clearWorkersTaskStats() {
#ifdef COLLECT_TASKSTATISTICS
	for (int i = 0; i < workers.size(); ++i) {
		TaskWorkerThread* worker = workers.get(i);

		worker->clearTaskStatistics();
	}
#endif
}

void TaskManagerImpl::setStatsDTaskSampling(int val) {
#ifdef COLLECT_TASKSTATISTICS
	for (int i = 0; i < workers.size(); ++i) {
		TaskWorkerThread* worker = workers.get(i);

		worker->setStatsDSamplingRate(val);
	}
#endif
}

class TestTask : public Task {
	int value;

public:
	TestTask(int val) {
		value = val;
	}

	void run() {
		System::out.println("test" + String::valueOf(value));
	}
};

void TaskManagerImpl::testScheduler() {
	for (int i = 0; i < 20; ++i) {
		uint32 shift = System::random(100);

		Task* task = new TestTask(i);

		scheduleTask(task, 100 + shift);
		rescheduleTask(task, shift - 50);

		Thread::sleep(System::random(5) + 5);
	}

	/*Task* task = new ReentrantTestTask(1);
	scheduleTask(task, 1000);*/
}

int TaskManagerImpl::getScheduledTaskSize() {
	int sum = 0;

	for (int i = 0; i < schedulers.size(); ++i) {
		TaskScheduler* scheduler = schedulers.get(i);

		sum += scheduler->getQueueSize();
	}

	return sum;
}

int TaskManagerImpl::getIoScheduledTaskSize() {
	int sum = 0;

	for (int i = 0; i < ioSchedulers.size(); ++i) {
		TaskScheduler* scheduler = ioSchedulers.get(i);

		sum += scheduler->getQueueSize();
	}

	return sum;
}

Task* TaskManagerImpl::getCurrentThreadTask() {
	Thread* thread = Thread::getCurrentThread();

	if (thread == NULL) {
		return NULL;
	}

	TaskWorkerThread* worker = thread->asTaskWorkerThread();

	if (worker == NULL) {
		return NULL;
	}

	return worker->getCurrentTask();
}

int TaskManagerImpl::getExecutingTaskSize() {
//	return tasks.size();

	int count = 0;
	for (int i = 0; i < taskQueues.size(); ++i) {
		count += taskQueues.get(i)->size();
	}

#ifdef WITH_STM
	count += serialTaskQueue.size();
#endif
	
	return count;
}

#ifdef WITH_STM
void TaskManagerImpl::retryTaskInSerial(Task* task) {
	//serialWorker->pushToRetryQueue(task);
	serialTaskQueue.push(task);
}

Thread* TaskManagerImpl::getSerialWorker() {
	return serialWorker;
}
#endif
