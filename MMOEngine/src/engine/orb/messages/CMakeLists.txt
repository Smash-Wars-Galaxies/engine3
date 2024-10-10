target_sources(engine3
	PRIVATE
		DeployObjectMessage.cpp
		DOBMessage.cpp
		DOBMessageFactory.cpp
		DOBServiceClient.cpp
		DOBServiceHandler.cpp
		GetNextFreeObjectIDMessage.cpp
		InvokeMethodMessage.cpp
		RemoteObjectBroker.cpp
		RequestServantMessage.cpp
		SendObjectDataMessage.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		DeployObjectMessage.h
		DOBMessage.h
		DOBMessageFactory.h
		DOBServiceClient.h
		DOBServiceHandler.h
		GetNextFreeObjectIDMessage.h
		InvokeMethodMessage.h
		LoadPersistentObjectMessage.h
		LookUpObjectByIDMessage.h
		LookUpObjectMessage.h
		RemoteObjectBroker.h
		RequestServantMessage.h
		SendObjectDataMessage.h
		UndeployObjectMessage.h
		UpdatePersistentObjectMessage.h
)


