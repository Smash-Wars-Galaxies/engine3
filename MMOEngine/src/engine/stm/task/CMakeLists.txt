target_sources(engine3
	PRIVATE
		LocalTaskManager.cpp
		TransactionalTaskManager.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		LocalTaskManager.h
		TransactionalTaskManager.h
)


