target_sources(engine3
	PRIVATE
		CommitMasterTransactionThread.cpp
		DistributedObjectDirectory.cpp
		DOBObjectManager.cpp
		ObjectDatabaseGarbageCollector.cpp
		UpdateModifiedObjectsThread.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		CommitMasterTransactionThread.h
		DestroyFromRamObjectsTask.h
		DistributedObjectDirectory.h
		DistributedObjectMap.h
		DOBObjectManager.h
		ObjectDatabaseGarbageCollector.h
		UpdateModifiedObjectsTask.h
		UpdateModifiedObjectsThread.h
)


