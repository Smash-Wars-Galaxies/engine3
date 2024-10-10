target_sources(engine3
	PRIVATE
		Crypto.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		Crypto.h
)


