# -----------------------------------生成库-----------------------------------
cmake_minimum_required(VERSION 3.12)
project("PLUS")

set(target_name "plus")

# 我自定义了install时候的路径，也可以定义为自己的install路径
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

add_library(${target_name} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/plus.cpp)
target_include_directories(${target_name} PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

set_target_properties(${target_name} PROPERTIES PUBLIC_HEADER "include/plus.h")

#==================生成目标文件的xxxTarget.cmake======================
# 会将生成的库libplus.so安装到${CMAKE_INSTALL_PREFIX}/lib下
install(
    TARGETS ${target_name}
    #EXPORT ${PROJECT_NAME}Targets
    PUBLIC_HEADER DESTINATION include
    ARCHIVE DESTINATION lib
     #LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
# 生成 xxxTargets.cmake文件
# install(
#     EXPORT ${PROJECT_NAME}Targets
#     FILE ${PROJECT_NAME}Targets.cmake
#     DESTINATION lib/cmake/mylib
# )

#======================生成 xxxConfig.cmake===============================
# 该变量会通过xxxConfig.cmake.in用于在生成的xxxConfig.cmake中
set(INCLUDE_DIRS include)
set(LIBRARIES ${target_name})
set(LIB_DIR lib)

# 由cmake提供
include(CMakePackageConfigHelpers)

# 生成 xxxConfigVersion.cmake文件
write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION 6.6.6
    COMPATIBILITY SameMajorVersion
)

# 用于生成 xxxConfig.cmake文件
configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/mylib
    PATH_VARS INCLUDE_DIRS LIBRARIES LIB_DIR
    INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}
)

install(
    FILES 
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake 
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/mylib
)

# https://blog.csdn.net/xiaoxiaozengz/article/details/127399274
