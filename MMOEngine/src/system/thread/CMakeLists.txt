target_sources(engine3
	PRIVATE
		ChildProcess.cpp
		Lockable.cpp
		Mutex.cpp
		Process.cpp
		ReadWriteLock.cpp
		Thread.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		ChildProcess.h
		Condition.h
		DeadlockException.h
		Lockable.h
		Locker.h
		Mutex.h
		Process.h
		ReadLocker.h
		ReadWriteLock.h
		Thread.h
		ThreadLocal.h
)

add_subdirectory(atomic)
add_subdirectory(gdb)
