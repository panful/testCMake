cmake_minimum_required(VERSION 3.12)
project("project_exe_static_shared")

set(target_name "exe_static_shared")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/target)

add_executable(${target_name} "main.cpp")
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(${target_name} PRIVATE static_shared)
target_link_libraries(${target_name} PRIVATE shared)
