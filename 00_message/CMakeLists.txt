cmake_minimum_required(VERSION 3.12)
project ("project_00")

set(target_name "00_message")

# 带STATUS打印时会有两个横杠--，其他没有区别
message( STATUS "==========print cmake var===========" )
message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}" )
message("CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" )
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" )
message("CMAKE_BINARY_DIR               = ${CMAKE_BINARY_DIR}" )
message("CMAKE_CURRENT_BINARY_DIR       = ${CMAKE_CURRENT_BINARY_DIR}" )
message("PROJECT_SOURCE_DIR             = ${PROJECT_SOURCE_DIR}" )
message("CMAKE_SOURCE_DIR               = ${CMAKE_SOURCE_DIR}" )
message("CMAKE_CURRENT_SOURCE_DIR       = ${CMAKE_CURRENT_SOURCE_DIR}" )
message( STATUS "==========print cmake var===========" )