cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

project( code_engine  )
find_package(Boost 1.58 COMPONENTS filesystem)


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(CodeEngine/)
    include_directories(CodeEngine/c_engine)
    include_directories(lib/inja-master/src/)

    file(GLOB SOURCES "CodeEngine/*.cpp"
                    "CodeEngine/c_engine/example/*.cpp"
                    "CodeEngine/c_engine/impl/toolkit/*.cpp"
                    "CodeEngine/c_engine/impl/engine/cpp/*.cpp"
                    "CodeEngine/c_engine/impl/engine/string/*.cpp")

    add_executable( code_engine ${SOURCES} )
    target_link_libraries(code_engine ${Boost_LIBRARIES})
endif()

