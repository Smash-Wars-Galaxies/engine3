#include "Core.h"

#include "engine/db/ObjectDatabaseManager.h"

#include "engine/stm/TransactionalMemoryManager.h"

#include "TaskScheduler.h"

#include "Task.h"

#include "TaskManager.h"

Task::Task() : PriorityQueueEntry() {
	initialize();
}

Task::Task(uint64 mtime) : PriorityQueueEntry() {
	initialize();

	nextExecutionTime.addMiliTime(mtime);
}

Task::Task(Time& time) : PriorityQueueEntry() {
	initialize();

	nextExecutionTime = time;
}

Task::~Task() {
	if (isQueued()) {
		System::out << "ERROR: scheduled task deleted\n";
		raise(SIGSEGV);
	}

#ifdef TRACE_TASKS
	if (scheduleTrace != NULL) {
		delete scheduleTrace;
		scheduleTrace = NULL;
	}
#endif
}

void Task::initialize() {
	taskManager = Core::getTaskManager();

	priority = 3;
	period = 0;

#ifdef TRACE_TASKS
	scheduleTrace = NULL;
#endif
}

void Task::execute() {
#ifdef WITH_STM
	Reference<engine::stm::Transaction*> transaction = engine::stm::Transaction::currentTransaction();
	//engine::stm::Transaction* transaction = engine::stm::Transaction::currentTransaction();

	try {
		if (!transaction->start(this))
			return;

		transaction->commit();
	} catch (Exception& e) {
		Logger::console.error("exception caught while running a task");
		e.printStackTrace();
	} catch (TransactionAbortedException& e) {
		Logger::console.error("in TASK");
	}


#else
	ObjectDatabaseManager::instance()->startLocalTransaction();

	try {
		run();

	} catch (Exception& e) {
		Logger::console.error("exception caught while running a task");
		e.printStackTrace();
	} catch (...) {
		Logger::console.error("unreported exception caught while running a task");
	}

	ObjectDatabaseManager::instance()->commitLocalTransaction();
#endif
}


bool Task::isScheduled() {
	return taskManager->isTaskScheduled(this);
}

bool Task::cancel() {
	return taskManager->cancelTask(this);
}

bool Task::cancelNonTransactionally() {
#ifdef WITH_STM
	return TransactionalMemoryManager::instance()->getTaskManager()->getTaskManagerImpl()->cancelTask(this);
#else
	return cancel();
#endif
}

void Task::schedule(uint64 delay) {
	taskManager->scheduleTask(this, delay);
}

void Task::scheduleNonTransactionally(uint64 delay) {
#ifdef WITH_STM
	TransactionalMemoryManager::instance()->getTaskManager()->getTaskManagerImpl()->scheduleTask(this, delay);
#else
	schedule(delay);
#endif

}

void Task::schedule(Time& time) {
	taskManager->scheduleTask(this, time);
}

void Task::schedulePeriodic(uint64 delay, uint64 period) {
	setPeriod(period);

	taskManager->scheduleTask(this, delay);
}

void Task::schedulePeriodic(Time& time, uint64 period) {
	setPeriod(period);

	taskManager->scheduleTask(this, time);
}

void Task::reschedule(uint64 delay) {
	taskManager->rescheduleTask(this, delay);
}

void Task::rescheduleNonTransactionally(uint64 delay) {
#ifdef WITH_STM
	TransactionalMemoryManager::instance()->getTaskManager()->getTaskManagerImpl()->rescheduleTask(this, delay);
#else
	reschedule(delay);
#endif
}

void Task::reschedule(Time& time) {
	taskManager->rescheduleTask(this, time);
}

