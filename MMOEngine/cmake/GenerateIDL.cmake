add_custom_target(generate-idl)

function(generate_idl file target)
    cmake_path(SET IDL_PATH ${file})
    cmake_path(ABSOLUTE_PATH IDL_PATH NORMALIZE)
    cmake_path(RELATIVE_PATH IDL_PATH BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src")
    cmake_path(GET IDL_PATH STEM FILE_NAME)

    add_custom_command(
        DEPENDS ${IDL_ROOT}
        COMMAND 
            ${Java_JAVA_EXECUTABLE} -cp ${PROJECT_SOURCE_DIR}/lib/idlc.jar org.sr.idlc.compiler.Compiler -sourcedir ${PROJECT_SOURCE_DIR}/src -od "../build/src" ${IDL_PATH}
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.cpp ${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.h
    )

    set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.h DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} PROPERTIES GENERATED TRUE)
    set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.cpp DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} PROPERTIES GENERATED TRUE)
    
    #set_property(SOURCE <source> APPEND PROPERTY OBJECT_DEPENDS <files>...)

    add_custom_target("${FILE_NAME}-generate" DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.h ${CMAKE_CURRENT_BINARY_DIR}/${FILE_NAME}.cpp)
	add_dependencies(generate-idl "${FILE_NAME}-generate")
endfunction()