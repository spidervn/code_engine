cmake_minimum_required(VERSION 2.8)

project( code_engine  )

include_directories(CodeEngine/)
file(GLOB SOURCES "CodeEngine/*.cpp" )

add_executable( code_engine ${SOURCES} )
