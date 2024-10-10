target_sources(engine3
	PRIVATE
		BerkeleyDatabase.cpp
		BTransaction.cpp
		Cursor.cpp
		DatabaseEntry.cpp
		Environment.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		BerkeleyDatabase.h
		BTransaction.h
		CheckpointConfig.h
		Cursor.h
		CursorConfig.h
		DatabaseConfig.h
		DatabaseEntry.h
		Environment.h
		EnvironmentConfig.h
		TransactionConfig.h
)


# Find berkeley includes
find_package(Berkeley REQUIRED)
target_include_directories(engine3 PRIVATE ${DB_INCLUDE_DIR})
target_link_libraries(engine3 PUBLIC ${DB_LIBRARIES})