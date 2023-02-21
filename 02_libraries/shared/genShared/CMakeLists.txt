cmake_minimum_required(VERSION 3.12)
project("project_02")

set(lib_name "mySharedLib")

# 是否构建动态库
set(BUILD_SHARED_LIBS YES)

# 定义输出路径
set(LIB_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 设置库文件输出路径，
# Windows下会将dll,lib,exp,pdb(Debug模式)文件生成到当前目录下的bin/Debug或(bin/Release)文件夹内
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})

# SHARED 可以不写，构建方式将使用BUILD_SHARED_LIBS的结果
# 如果BUILD_SHARED_LIBS和add_library构建方式不同，将使用add_library的方式
#add_library(${lib_name} SHARED "include/demo.h" "src/demo.cpp")
add_library(${lib_name} "include/demo.h" "src/demo.cpp")

# 添加头文件路径，target_include_directories必须在构建${lib_name}之后
target_include_directories(${lib_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)