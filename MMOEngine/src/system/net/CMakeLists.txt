target_sources(engine3
	PRIVATE
		InetAddress.cpp
		NetworkInterface.cpp
		Packet.cpp
		Socket.cpp
		SocketAddress.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		InetAddress.h
		NetworkInterface.h
		Packet.h
		PacketIndexOutOfBoundsException.h
		Socket.h
		SocketAddress.h
		SocketException.h
		TCPServerSocket.h
		TCPSocket.h
		UDPServerSocket.h
		UDPSocket.h
)


