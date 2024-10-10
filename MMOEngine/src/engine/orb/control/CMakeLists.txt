target_sources(engine3
	PRIVATE
		ObjectBrokerAgent.cpp
		ObjectBrokerDirector.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		ControlMessage.h
		ObjectBrokerAgent.h
		ObjectBrokerDirector.h
		ObjectBrokerTable.h
		StateUpdateMessage.h
)


