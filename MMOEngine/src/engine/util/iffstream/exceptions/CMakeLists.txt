target_sources(engine3
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		IffStreamException.h
		InvalidChunkTypeException.h
		InvalidFileTypeException.h
		NoChunksException.h
		NoOpenedChunkException.h
)


