target_sources(engine3
	PRIVATE
		IffStream.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		exceptions.h
		IffStream.h
)

add_subdirectory(chunks)
add_subdirectory(exceptions)
