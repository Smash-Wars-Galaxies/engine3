# Copyright (C) 2007-2019 SWGEmu
# See file COPYING for copying conditions.

cmake_minimum_required(VERSION 3.13)
project(engine3 VERSION 1.0 LANGUAGES CXX C)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(doc)
  endif()
endif()

include(CheckCXXSourceCompiles)
include(CheckCXXCompilerFlag)

option(ENABLE_ASAN "Enables address sanitizer compiling" OFF)
option(ENABLE_TSAN "Enables thread sanitizer compiling" OFF)
option(ENABLE_UBSAN "Enables undefined behavior sanitizer compiling" OFF)
option(ENABLE_NATIVE "Enables -march=native compiler option" ON)
option(ENABLE_ODB_REFERENCES "Enables ODB_REFERENCES define" ON)
option(ENABLE_OMIT_FRAMEPOINTER "Enables -fno-omit-frame-pointer compiler option" ON)

# Set cmake find moudles path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

find_package(Java 1.5 COMPONENTS Runtime REQUIRED)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


if (ENABLE_ODB_REFERENCES)
	add_definitions(-DODB_REFERENCES)
endif()

function(check_working_cxx_atomics varname)
	set(OLD_CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS})
	set(CMAKE_REQUIRED_FLAGS "-std=c++11")
	CHECK_CXX_SOURCE_COMPILES("
	#include <atomic>
	struct test_type { float x[3]; };
	std::atomic<test_type> atom;
	test_type old;
	test_type newval;
	int main() {
	newval.x[2] = 3;
	return atom.compare_exchange_strong(old, newval);
	}
	" ${varname})
	set(CMAKE_REQUIRED_FLAGS ${OLD_CMAKE_REQUIRED_FLAGS})
endfunction(check_working_cxx_atomics)

check_working_cxx_atomics(HAVE_CXX_ATOMICS_WITHOUT_LIB)

if (NOT HAVE_CXX_ATOMICS_WITHOUT_LIB)
	find_package(GccAtomic REQUIRED)
endif()

add_definitions(-DDEFAULT_DYNAMIC_CAST)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Define global build gcc compatible flags to check and add if available
    set(GCCEXTRAFLAGS -Wall
	-Wextra
	-Wno-unused
	-Wno-sign-compare
	-Wno-multichar
	-Wno-unused-parameter
	-Wno-overloaded-virtual
	-Wno-missing-declarations
	-Wno-return-std-move
	-Wno-implicit-fallthrough
	-Wno-class-memaccess
	-fcolor-diagnostics
	-Wno-deprecated-copy)

    foreach(flag_comp ${GCCEXTRAFLAGS})
	CHECK_CXX_COMPILER_FLAG(${flag_comp} CxxFlag${flag_comp})

	if (CxxFlag${flag_comp})
		set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag_comp}")
	endif()
    endforeach(flag_comp)

    if (ENABLE_ASAN)
	   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
	   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -fsanitize=address")

	   message(STATUS "Adress sanitizer enabled")
    endif(ENABLE_ASAN)

    if (ENABLE_TSAN)
	   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
	   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -fsanitize=thread")

	   message(STATUS "Thread sanitizer enabled")
    endif(ENABLE_TSAN)

    if (ENABLE_UBSAN)
	   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
	   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -fsanitize=undefined")

	   message(STATUS "Undefined behavior sanitizer sanitizer enabled")
    endif(ENABLE_UBSAN)

    if (ENABLE_NATIVE)
	   CHECK_CXX_COMPILER_FLAG(-march=native CxxFlagMnative)

	   if (CxxFlagMnative)
	        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
	   endif (CxxFlagMnative)
    endif(ENABLE_NATIVE)

    if (ENABLE_OMIT_FRAMEPOINTER)
	   CHECK_CXX_COMPILER_FLAG(-fno-omit-frame-pointer CxxFlagFramePointer)

	   if (CxxFlagFramePointer)
           	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
	   endif (CxxFlagFramePointer)
    endif()
endif()

# Define build flags for public or private engine builds
if (ENGINE_TYPE EQUAL 2)
	message(STATUS "Building public engine")

	add_definitions(-DVERSION_PUBLIC)
else ()
	message(STATUS "Building private engine")
endif ()

add_library(engine3)
add_library(Engine3::engine3 ALIAS engine3)

add_subdirectory(src)
add_subdirectory(testsuite3)

add_dependencies(engine3 generate-idl)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    Engine3ConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
	EXPORT 
	Engine3Targets
	FILE Engine3Targets.cmake
	NAMESPACE Engine3::
	DESTINATION lib/cmake/Engine3
)