generate_idl("ManagedObject.idl" engine3)
generate_idl("ManagedService.idl" engine3)

target_include_directories(engine3 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_sources(engine3
	PRIVATE
		Core.cpp
		${CMAKE_CURRENT_BINARY_DIR}/ManagedObject.cpp
		ManagedObjectImplementation.cpp
		ManagedProcess.cpp
		${CMAKE_CURRENT_BINARY_DIR}/ManagedService.cpp
		MetricsManager.cpp
		ObjectUpdateToDatabaseTask.cpp
		RunStatistics.cpp
		Task.cpp
		TaskManagerImpl.cpp
		TaskQueue.cpp
		TaskScheduler.cpp
		TaskWorkerThread.cpp
		TimedTaskQueue.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS 
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_BINARY_DIR}/src
	FILES
		Core.h
		LambdaFunction.h
		${CMAKE_CURRENT_BINARY_DIR}/ManagedObject.h
		ManagedObject.idl
		ManagedProcess.h
		ManagedReference.h
		${CMAKE_CURRENT_BINARY_DIR}/ManagedService.h
		ManagedService.idl
		ManagedWeakReference.h
		MetricsManager.h
		ObjectUpdateToDatabaseTask.h
		RunStatistics.h
		Task.h
		TaskManager.h
		TaskManagerImpl.h
		TaskPriorityQueue.h
		TaskQueue.h
		TaskScheduler.h
		TaskWorkerThread.h
		TimedTaskQueue.h
)

add_subdirectory(util)
