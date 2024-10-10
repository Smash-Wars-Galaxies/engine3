target_sources(engine3
	PRIVATE
		DistributedMethod.cpp
		DistributedObject.cpp
		DistributedObjectServant.cpp
		DistributedObjectStub.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		DistributedMethod.h
		DistributedObject.h
		DistributedObjectAdapter.h
		DistributedObjectClassHelper.h
		DistributedObjectClassHelperMap.h
		DistributedObjectPOD.h
		DistributedObjectServant.h
		DistributedObjectStub.h
		ObjectAlreadyDeployedException.h
		ObjectNotDeployedException.h
		ObjectNotLocalException.h
)


