cmake_minimum_required(VERSION 3.12)
project("library_interface")

set(CMAKE_CXX_STANDARD 20)

set(interface_name "the_inter")
set(target_name "the_target")

# 添加一个Interface库
# 可以给这个库添加包含路径，库文件（*.lib *.so *.dll *.a）
add_library(${interface_name} INTERFACE)
target_include_directories(${interface_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/includes)

# 添加一个生成目标
add_executable(${target_name} main.cpp)
# 给这个生成目标添加interface库
# 可以理解为将生成目标的link和include放在了这个interface库中，生成目标只需要link这个interface
target_link_libraries(${target_name} PRIVATE ${interface_name})