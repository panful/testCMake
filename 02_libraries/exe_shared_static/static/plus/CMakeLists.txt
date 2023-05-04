cmake_minimum_required(VERSION 3.12)
project("MyProject")

set(target_name "plus")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../../shared)

add_library(${target_name} STATIC "plus.h" "plus.cpp")

install(TARGETS ${target_name}
    ARCHIVE DESTINATION lib
)

install(FILES plus.h DESTINATION include)