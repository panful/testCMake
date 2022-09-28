cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "02_libraries")
set(lib_name "myLib")

# 是否构建动态库
set(BUILD_SHARED_LIBS YES)

# STATIC可以不写，构建方式将使用BUILD_SHARED_LIBS的结果
# 如果BUILD_SHARED_LIBS和add_library构建方式不同，将使用add_library的方式
#add_library(${lib_name} STATIC "include/demo.h" "src/demo.cpp")
add_library(${lib_name} "include/demo.h" "src/demo.cpp")

# 添加头文件路径，target_include_directories必须在构建${lib_name}之后
target_include_directories(${lib_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 构建可执行文件
add_executable(${target_name} "main.cpp")

# 将库文件的头文件路径包含到${target_name}项目中
target_include_directories(${target_name} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 链接上面构建的库文件
# 需要注意不同平台库文件的名字以及后缀可能不同
# Windows下动态库也会生成lib文件，也需要包含
target_link_libraries(${target_name} PRIVATE ${lib_name})