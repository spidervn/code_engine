cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

project( marco_to_name  )

include_directories(MarcoToNameSln/)

file(GLOB SOURCES "MarcoToNameSln/*.cpp")

add_executable( marco_to_name ${SOURCES} )
