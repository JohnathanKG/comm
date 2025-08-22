cmake_minimum_required(VERSION 4.1)
project(intergen)

include_directories(
    ${CMAKE_PROJ}/include
    ${CMAKE_PROJ}/include/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/
)

add_executable(intergen
    ifc.h
    ifc.js.h
    ifc.lua.h
    ig-arg.cpp
    ig-class.cpp
    ig-lexer.cpp
    ig-method.cpp
    ig.h
    intergen.cpp
    lua_utils.h
    rl-method.cpp
)

target_link_libraries(intergen comm)

set(INTERGEN_EXECUTABLE_PATH ${PROJECT_BINARY_DIR}/intergen.exe PARENT_SCOPE)
set(INTERGEN_TEMPLATES_PATH ${CMAKE_CURRENT_LIST_DIR}/metagen/ PARENT_SCOPE)