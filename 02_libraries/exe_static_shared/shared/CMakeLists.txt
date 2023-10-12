cmake_minimum_required(VERSION 3.12)
project("project_shared")

set(target_name "shared")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../static)

add_library(${target_name} SHARED "${CMAKE_CURRENT_SOURCE_DIR}/src/sub_add.cpp")
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ${target_name}
    RUNTIME DESTINATION shared_bin
    ARCHIVE DESTINATION shared_lib
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/sub_add.h" DESTINATION shared_include)