
cmake_minimum_required(VERSION 3.12)

project(Math VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plus)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sub)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/use)

export(
    TARGETS Plus Sub 
    NAMESPACE ${PROJECT_NAME}:: 
    FILE ${PROJECT_NAME}Targets.cmake
)

install(
    TARGETS Plus Sub
    EXPORT MathTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)

# 导出和安装配置文件
install(
    EXPORT MathTargets
    FILE MathTargets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

#======================生成 xxxConfig.cmake===============================
# 该变量会通过xxxConfig.cmake.in用于在生成的xxxConfig.cmake中
set(INCLUDE_DIR include)
set(LIBRARIES_DIR lib)

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
    ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in  # 文件名，一般为xxxConfig.cmake.in文件，需要自己提供
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake           # 文件名，一般为xxxConfig.cmake文件。其会通过input中的文件进行生成
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}               # 安装路径，如果是相对路径，则相对于INSTALL_PREFIX
    PATH_VARS INCLUDE_DIR LIBRARIES_DIR                         # PATH_VARS 后面的变量需要在xxxConfig.cmake.in文件中出现，例如变量名 A，则在 xxxConfig.cmake.in 中要以 @PACKAGE_A@ 的形式出现
    INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}                      # 相对路径前缀
)

install(
    FILES 
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake 
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)

# https://blog.csdn.net/xiaoxiaozengz/article/details/127399274
# https://www.jianshu.com/p/ab7a94115d10
