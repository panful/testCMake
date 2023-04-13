cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "02_libraries")
set(lib_name "myStaticLib")

# 是否构建动态库
set(BUILD_SHARED_LIBS NO)

# 定义输出路径
set(LIB_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/lib)

# Windows下会将dll,lib,exp,pdb(Debug模式)文件生成到当前目录下的lib/Debug或(lib/Release)文件夹内
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR})

# STATIC可以不写，构建方式将使用BUILD_SHARED_LIBS的结果
# 如果BUILD_SHARED_LIBS和add_library构建方式不同，将使用add_library的方式
#add_library(${lib_name} STATIC "include/demo.h" "src/demo.cpp")
add_library(${lib_name} "include/demo.h" "src/demo.cpp")

# 添加头文件路径，target_include_directories必须在构建${lib_name}之后
target_include_directories(${lib_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)

