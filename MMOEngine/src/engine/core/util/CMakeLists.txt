generate_idl("ManagedVector.idl" engien3)

target_include_directories(engine3 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_sources(engine3
	PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}/ManagedVector.cpp"
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS 
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_BINARY_DIR}/src
	FILES
		ManagedSortedVector.h
		${CMAKE_CURRENT_BINARY_DIR}/ManagedVector.h
		ManagedVector.idl
		ManagedVectorMap.h
)

