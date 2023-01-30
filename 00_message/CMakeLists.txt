cmake_minimum_required(VERSION 3.12)
project ("project_00")

set(target_name "00_message")

message( "-----------------------------------------------" )
message("CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}" )
message("CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" )
message("CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}" )
message("CMAKE_BINARY_DIR               = ${CMAKE_BINARY_DIR}" )
message("CMAKE_CURRENT_BINARY_DIR       = ${CMAKE_CURRENT_BINARY_DIR}" )
message("PROJECT_SOURCE_DIR             = ${PROJECT_SOURCE_DIR}" )
message("CMAKE_SOURCE_DIR               = ${CMAKE_SOURCE_DIR}" )
message("CMAKE_CURRENT_SOURCE_DIR       = ${CMAKE_CURRENT_SOURCE_DIR}" )

message( "-----------------------------------------------" )

message(STATUS          "CMake 状态, 带状态的CMake信息")
message(WARNING         "CMake 警告, 会继续执行")
message(AUTHOR_WARNING  "CMake 警告 (dev), 会继续执行")
message(SEND_ERROR      "CMake 错误, 继续执行，但是会跳过生成的步骤")
message(FATAL_ERROR     "CMake 错误, 终止所有处理过程")

message( "-----------------------------------------------" )