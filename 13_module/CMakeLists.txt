cmake_minimum_required(VERSION 3.12)
project("module_demo")

# MODULE一般用来设置 find_package 的查找路径
# 注意不要将原来的 MODULE_PATH 覆盖掉
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/myCMake")
# 也可以直接附加到后面
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/myCMake")

# 直接将文件包含进来，和C++的头文件类似
# 包含进来以后，就可以在这个文件使用包含文件的函数、宏等
include("${CMAKE_SOURCE_DIR}/myCMake/test.cmake")

message("+++++ call module function")
# 调用包含文件的函数
func1()
