cmake_minimum_required(VERSION 3.12)
project("myproject")

set(target_name "test_install")

# 设置安装路径的前缀
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

# 添加需要生成的动态库
add_library(${target_name} SHARED "${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp")
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 设置需要安装的头文件
set(public_header_ "${CMAKE_CURRENT_SOURCE_DIR}/include/test.h")
set_target_properties(${target_name} PROPERTIES PUBLIC_HEADER ${public_header_}) # 如果包含多个文件，${public_header_} 需要带引号 例如："${public_header_}"

# 设置需要安装的资源文件
set(resource_ "${CMAKE_CURRENT_SOURCE_DIR}/resources/readme.md")
set_target_properties(${target_name} PROPERTIES RESOURCE ${resource_})

install(TARGETS ${target_name}
    LIBRARY DESTINATION lib             # 无
    ARCHIVE DESTINATION arc             # *.lib
    RUNTIME DESTINATION run             # *.dll
    PUBLIC_HEADER DESTINATION include   # public_header_
    RESOURCE DESTINATION res            # resource_
)
