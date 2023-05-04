cmake_minimum_required(VERSION 3.12)
project("MyProject")

set(target_name "Test")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${target_name} main.cpp)

target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${target_name} PRIVATE MyMath)

install(TARGETS ${target_name} RUNTIME DESTINATION .)