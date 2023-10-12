cmake_minimum_required(VERSION 3.12)
project("project_shared_static")

set(target_name "shared_static")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../exe)

add_library(${target_name} SHARED "${CMAKE_CURRENT_SOURCE_DIR}/src/mymath.cpp")
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/static_include)
target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/static_lib)
target_link_libraries(${target_name} PRIVATE static)

install(TARGETS ${target_name}
    RUNTIME DESTINATION target
    ARCHIVE DESTINATION lib
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/mymath.h" DESTINATION include)