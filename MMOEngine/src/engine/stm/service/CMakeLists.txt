target_sources(engine3
	PRIVATE
		TransactionalBaseClientManager.cpp
		TransactionalSocketManager.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		TransactionalBaseClientManager.h
		TransactionalSocketManager.h
)


