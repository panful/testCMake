cmake_minimum_required(VERSION 3.4)
project(Te)

set(target_name "usePackage")

# 设置find_package的查找路径
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../createPackage/install/lib/cmake/mylib)

find_package(PLUS REQUIRED)
if(PLUS_FOUND)
    message(" --- PLUS_FOUND = ${PLUS_FOUND}")
    message(" --- PLUS_INCLUDE_DIRS = ${PLUS_INCLUDE_DIRS}")
    message(" --- PLUS_LIBRARIES = ${PLUS_LIBRARIES}")
    message(" --- PLUS_LIBRARY_DIRS = ${PLUS_LIBRARY_DIRS}")
endif()


add_executable(${target_name} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_directories(${target_name} PUBLIC ${PLUS_LIBRARY_DIRS})
target_link_libraries(${target_name} plus)
target_include_directories(${target_name} PUBLIC ${PLUS_INCLUDE_DIRS})

add_custom_command(TARGET ${target_name}
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
    copy_if_different ${PLUS_LIBRARY_DIRS}/../bin/plus.dll $<TARGET_FILE_DIR:${target_name}>/plus.dll
)