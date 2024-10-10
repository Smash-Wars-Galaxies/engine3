target_sources(engine3
	PRIVATE
		BasePacketChekupEvent.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AcknowledgeTask.h
		BaseClientCleanupEvent.h
		BaseClientEvent.h
		BaseClientHealthEvent.h
		BaseClientNetStatusCheckupEvent.h
		BaseClientNetStatusRequestEvent.h
		BasePacketChekupEvent.h
		DisconnectTask.h
		NetStatusResponseTask.h
		OutOfOrderTask.h
		SessionResponseTask.h
		SessionStartTask.h
)


