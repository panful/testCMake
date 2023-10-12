cmake_minimum_required(VERSION 3.12)
project("project_static")

set(target_name "static")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../shared)

add_library(${target_name} STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/add_sub.cpp")
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ${target_name}
    ARCHIVE DESTINATION static_lib
)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/add_sub.h" DESTINATION static_include)