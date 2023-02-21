cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "02_libraries_callStatic")
set(lib_name "myStaticLib")

# 生成库文件部分请看static文件夹
set(BUILD_SHARED_LIBS NO)
add_library(${lib_name} "include/demo.h" "src/demo.cpp")
target_include_directories(${lib_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 构建可执行文件
add_executable(${target_name} "main.cpp")

# 将库文件的头文件路径包含到${target_name}项目中
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 链接上面构建的库文件
# 需要注意不同平台库文件的名字以及后缀可能不同
target_link_libraries(${target_name} PRIVATE ${lib_name})