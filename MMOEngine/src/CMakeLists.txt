# Copyright (C) 2007-2019 SWGEmu
# See file COPYING for copying conditions.

# Setup CXX standard
set_target_properties(engine3
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

# Enable PIC
set_property(TARGET engine3 PROPERTY POSITION_INDEPENDENT_CODE ON)

add_subdirectory(engine)
add_subdirectory(system)
	
# Handle Installation
install(
	TARGETS engine3
	EXPORT Engine3Targets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	FILE_SET public_headers
)

install(PROGRAMS ../lib/idlc.jar DESTINATION bin)