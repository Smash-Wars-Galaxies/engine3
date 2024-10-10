target_sources(engine3
	PRIVATE
		BinaryData.cpp
		DatabaseManager.cpp
		IndexDatabase.cpp
		LocalDatabase.cpp
		ObjectDatabase.cpp
		ObjectDatabaseManager.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		BinaryData.h
		Database.h
		DatabaseException.h
		DatabaseManager.h
		IndexDatabase.h
		LocalDatabase.h
		ObjectDatabase.h
		ObjectDatabaseManager.h
		ResultSet.h
)

add_subdirectory(berkeley)
add_subdirectory(mysql)
