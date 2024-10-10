target_sources(engine3
	PRIVATE
		DistributedObjectBroker.cpp
		NamingDirectoryService.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		DistributedObjectBroker.h
		DistributionException.h
		NameAlreadyBoundException.h
		NamingDirectoryService.h
		ObjectBroker.h
)

add_subdirectory(control)
add_subdirectory(db)
add_subdirectory(messages)
add_subdirectory(object)
