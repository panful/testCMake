cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "callShared")

# 设置可执行文件的生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/target)

# 构建可执行文件
add_executable(${target_name} "main.cpp")

# 将库文件的头文件路径包含到项目中
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 链接库文件
# 需要注意不同平台库文件的名字以及后缀可能不同
# Windows下动态库也会生成lib文件，也需要包含
target_link_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib) # 设置库文件路径
target_link_libraries(${target_name} PRIVATE myshared)                          # 设置需要链接的库文件名称