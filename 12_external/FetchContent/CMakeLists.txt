cmake_minimum_required(VERSION 3.14)

project(fetch_content_demo)

include(FetchContent)

# 声明外部项目
set(external_name "spdlog_proj")
FetchContent_Declare(
    ${external_name} # 外部依赖项名字（可以根据需要随便起，不一定和实际项目名一样）
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.4.1
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/spdlog_dir # 下载的外部依赖项目所在目录
)

# 下载和构建这个外部项目
FetchContent_MakeAvailable(${external_name}) # cmake 3.14之后才开始支持该命令

message("=== SOURCE_DIR: ${spdlog_SOURCE_DIR}")
message("=== BINARY_DIR: ${spdlog_BINARY_DIR}")

set(target_name test_spdlog)
add_executable(${target_name} "main.cpp")
target_link_libraries(${target_name} PRIVATE spdlog)
