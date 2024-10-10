target_sources(engine3
    PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}/src
    FILES
        lang.h
        platform.h
)

add_subdirectory(io)
add_subdirectory(lang)
add_subdirectory(mm)
add_subdirectory(net)
add_subdirectory(security)
add_subdirectory(thread)
add_subdirectory(util)