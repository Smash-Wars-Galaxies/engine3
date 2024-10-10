target_sources(engine3
	PRIVATE
		Lua.cpp
		LuaFunction.cpp
		LuaObject.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		Lua.h
		LuaCallbackException.h
		LuaFunction.h
		LuaObject.h
		LuaPanicException.h
		Luna.h
		Lunar.h
)

# Add lua includes
find_package(Lua "5.3" REQUIRED)
target_include_directories(engine3 PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(engine3 PUBLIC ${LUA_LIBRARIES})