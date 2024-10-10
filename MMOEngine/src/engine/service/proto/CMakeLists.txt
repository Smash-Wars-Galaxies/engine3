target_sources(engine3
	PRIVATE
		BaseClient.cpp
		BaseClientProxy.cpp
		BaseFragmentedPacket.cpp
		BaseMultiPacket.cpp
		BasePacket.cpp
		BasePacketHandler.cpp
		BaseProtocol.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AbstractProtocol.h
		BaseClient.h
		BaseClientProxy.h
		BaseClientStats.h
		BaseFragmentedPacket.h
		BaseMessage.h
		BaseMultiPacket.h
		BasePacket.h
		BasePacketHandler.h
		BaseProtocol.h
		PacketHandler.h
		StandaloneBaseMessage.h
)

add_subdirectory(events)
add_subdirectory(packets)
