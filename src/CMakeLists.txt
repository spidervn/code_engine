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

    file(GLOB MAINSKELETON "CodeEngine/c_engine/impl/example/*.cpp"
                    "CodeEngine/c_engine/impl/toolkit/*.cpp"
                    "CodeEngine/c_engine/impl/engine/cpp/*.cpp"
                    "CodeEngine/c_engine/impl/engine/string/*.cpp"
                    "CodeEngine/c_engine/impl/engine/system/*.cpp")

    add_library(libcodeengine STATIC ${MAINSKELETON})

    add_executable(code_engine CodeEngine/main.cpp)
    target_link_libraries(code_engine ${Boost_LIBRARIES} libcodeengine)

    # Application
    add_executable(cpp_ifdef CodeEngine/c_engine/app/cpp/CppGenerateIfdef.cpp)
    target_link_libraries(cpp_ifdef ${Boost_LIBRARIES} libcodeengine)

    # Testing
    add_executable(test_system CodeEngine/c_engine/app/test/system/TestFileSystem.cpp)
    target_link_libraries(test_system ${Boost_LIBRARIES} libcodeengine)    
endif()

