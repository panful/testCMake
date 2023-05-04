cmake_minimum_required(VERSION 3.12)
project("MyProject")

set(target_name "MyMath")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../exe)

add_library(${target_name} SHARED "mymath.h" "mymath.cpp")

target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${target_name} PRIVATE sub plus)

install(TARGETS ${target_name} 
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
)
install(FILES mymath.h DESTINATION include)