target_sources(engine3
	PRIVATE
		Transaction.cpp
		TransactionalMemoryManager.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		Transaction.h
		TransactionAbortedException.h
		TransactionalMemoryManager.h
		TransactionalObjectHandle.h
		TransactionalObjectHeader.h
		TransactionalReference.h
		TransactionalWeakReference.h
)

add_subdirectory(algos)
add_subdirectory(mm)
add_subdirectory(orb)
add_subdirectory(service)
add_subdirectory(task)
