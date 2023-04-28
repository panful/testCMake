cmake_minimum_required(VERSION 3.12)

project("find_package")

#----------------------------------------------------------------------------
# 在find_package函数内部指定包的路径时，包的cmake文件名必须是：PackageNameConfig.cmake 即 XXXConfig.cmake
# find_package(TestPackage
#     PATHS
#         ${CMAKE_CURRENT_SOURCE_DIR}/../config
#     NO_DEFAULT_PATH    
# )

#----------------------------------------------------------------------------
# 设置 PackageName_DIR 变量查找包
# 查找包的cmake文件名必须是：PackageNameConfig.cmake 即 XXXConfig.cmake
# set(TestPackage_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../config")
# find_package(TestPackage)

#----------------------------------------------------------------------------
# 设置 CMAKE_MODULE_PATH 包的cmake文件名必须是 FindPackageName.cmake 即 FindXXX.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/../module)
find_package(TestPackage)


if(TestPackageFound)
    message("============ TestPackage found ==========")
else()
    message("========== TestPackage not found ========")
endif()