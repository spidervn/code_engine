cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

project( code_engine  )

include_directories(CodeEngine/)
include_directories(lib/inja-master/src/)

file(GLOB SOURCES "CodeEngine/*.cpp" )

add_executable( code_engine ${SOURCES} )
