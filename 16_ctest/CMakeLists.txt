cmake_minimum_required(VERSION 3.14)
project(utest_proj)

# 启用当前项目CMake的测试功能
enable_testing()

if(NOT WIN32)
    return()
endif(NOT WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /Zc:__cplusplus /utf-8 /EHsc")

add_subdirectory(src)
add_subdirectory(test)
