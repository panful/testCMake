cmake_minimum_required(VERSION 3.12)
project("project_static_shared")

set(target_name "static_shared")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../exe)

add_library(${target_name} STATIC "${CMAKE_CURRENT_SOURCE_DIR}/src/myMath.cpp")

target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/shared_include)
target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/shared_lib)
target_link_libraries(${target_name} PRIVATE shared)

install(TARGETS ${target_name}
    ARCHIVE DESTINATION lib
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/myMath.h" DESTINATION include)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/shared_lib/shared.lib" DESTINATION lib)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/shared_bin/shared.dll" DESTINATION target)