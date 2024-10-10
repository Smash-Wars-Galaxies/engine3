target_sources(engine3
	PRIVATE
		Chunk.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		Chunk.h
)

add_subdirectory(data)
add_subdirectory(form)
