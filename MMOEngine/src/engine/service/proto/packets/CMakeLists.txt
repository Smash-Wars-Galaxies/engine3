target_sources(engine3
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AcknowledgeMessage.h
		AcknowledgeOkMessage.h
		ConnectionServerMessage.h
		DisconnectMessage.h
		ErrorMessage.h
		LoginServerMessage.h
		NetStatusRequestMessage.h
		NetStatusResponseMessage.h
		OutOfOrderMessage.h
		PingMessage.h
		SessionIDRequestMessage.h
		SessionIDResponseMessage.h
)


