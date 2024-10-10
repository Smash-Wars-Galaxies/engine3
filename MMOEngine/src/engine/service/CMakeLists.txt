target_sources(engine3
	PRIVATE
		DatagramServiceClient.cpp
		DatagramServiceClientProxy.cpp
		DatagramServiceThread.cpp
		MessageQueue.cpp
		ServiceClient.cpp
		ServiceMessageHandlerThread.cpp
		ServiceThread.cpp
		StreamServiceClient.cpp
		StreamServiceThread.cpp
		SynchronizedMessageQueue.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		DatagramServiceClient.h
		DatagramServiceClientProxy.h
		DatagramServiceThread.h
		Message.h
		MessageQueue.h
		ServiceClient.h
		ServiceClientMap.h
		ServiceException.h
		ServiceFilter.h
		ServiceHandler.h
		ServiceMessageHandlerThread.h
		ServiceProcessor.h
		ServiceThread.h
		StreamServiceClient.h
		StreamServiceClientProxy.h
		StreamServiceThread.h
		SynchronizedMessageQueue.h
)

add_subdirectory(proto)
