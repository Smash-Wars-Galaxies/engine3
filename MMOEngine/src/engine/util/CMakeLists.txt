generate_idl("Facade.idl" engine3)
generate_idl("Observable.idl" engine3)
generate_idl("Observer.idl" engine3)

target_include_directories(engine3 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_sources(engine3
	PRIVATE
		${CMAKE_CURRENT_BINARY_DIR}/Facade.cpp
		json_utils.cpp
		${CMAKE_CURRENT_BINARY_DIR}/Observable.cpp
		${CMAKE_CURRENT_BINARY_DIR}/Observer.cpp
		ObserverEventMap.cpp
		ObserverImplementation.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS 
		${PROJECT_SOURCE_DIR}/src
		${PROJECT_BINARY_DIR}/src
	FILES
		bytell_hash_map.hpp
		Command.h
		${CMAKE_CURRENT_BINARY_DIR}/Facade.h
		Facade.idl
		flat_hash_map.hpp
		json.hpp
		json_utils.h
		JSONSerializationType.h
		ObjectContainer.h
		ObjectFactory.h
		${CMAKE_CURRENT_BINARY_DIR}/Observable.h
		Observable.idl
		${CMAKE_CURRENT_BINARY_DIR}/Observer.h
		Observer.idl
		ObserverEventMap.h
		ResourcePool.h
		Singleton.h
		unordered_map.hpp
)

add_subdirectory(iffstream)
add_subdirectory(lru)
add_subdirectory(u3d)
