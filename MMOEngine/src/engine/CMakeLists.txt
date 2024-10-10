target_sources(engine3
    PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}/src
    FILES
        engine.h
)

add_subdirectory(core)
add_subdirectory(db)
add_subdirectory(dbo)
add_subdirectory(log)
add_subdirectory(lua)
add_subdirectory(orb)
add_subdirectory(service)
add_subdirectory(stm)
add_subdirectory(util)

# # Handle library linking
target_link_libraries(engine3 PUBLIC ${GCCLIBATOMIC_LIBRARY} ZLIB::ZLIB OpenSSL::Crypto)

option(ENABLE_LOCKFREE_BCLIENT_BUFFERS "Enables lock free base client buffers, requires boost thread" OFF)
if (ENABLE_LOCKFREE_BCLIENT_BUFFERS)
	find_package(Boost REQUIRED COMPONENTS thread)

	set(Boost_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)

	target_compile_definitions(engine3 PUBLIC LOCKFREE_BCLIENT_BUFFERS)
	target_link_libraries(engine3 PUBLIC Boost::thread)
endif()
