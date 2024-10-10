# Copyright (C) 2007-2019 SWGEmu
# See file COPYING for copying conditions.

# Create testsuite3 binary
add_executable(testsuite3 TestSuite3.cpp)
add_executable(Engine3::testsuite3 ALIAS testsuite3)

add_subdirectory(tests)

# Handle linking library
target_link_libraries(testsuite3 PUBLIC engine3)

install(
	TARGETS testsuite3
	EXPORT Engine3Targets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	FILE_SET public_headers
)