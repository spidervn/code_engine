cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)

#
# Tips: Set Boost 
#   cmake -DCMAKE_INSTALL_PREFIX=$TARGET \
#    -DBOOST_ROOT:PATHNAME=$TARGET \
#    -DBoost_LIBRARY_DIRS:FILEPATH=${TARGET}/lib
#


project( code_engine  )
find_package(Boost COMPONENTS filesystem regex)

if(TRUE) # Boost_FOUND
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(CodeEngine/)
    include_directories(CodeEngine/c_engine)
    include_directories(lib/inja-master/src/)
    link_directories(${Boost_LIBRARY_DIRS})

    file(GLOB MAINSKELETON "CodeEngine/c_engine/example/*.cpp"
                    "CodeEngine/c_engine/impl/toolkit/*.cpp"
                    "CodeEngine/c_engine/impl/engine/cpp/*.cpp"
                    "CodeEngine/c_engine/impl/engine/string/*.cpp")

    add_executable( code_engine CodeEngine/main.cpp ${MAINSKELETON} )
    target_link_libraries(code_engine ${Boost_LIBRARIES})

    add_executable( cpp_ifdef CodeEngine/c_engine/app/cpp/CppGenerateIfdef.cpp ${MAINSKELETON} )
    target_link_libraries( cpp_ifdef ${Boost_LIBRARIES})
endif()

