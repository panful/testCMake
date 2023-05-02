cmake_minimum_required(VERSION 3.12)
project("myproject")

set(lib_name "mySharedLib")
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/target)

add_library(${lib_name} SHARED "include/test.h" "src/test.cpp")

# 添加头文件路径，target_include_directories必须在构建${lib_name}之后
target_include_directories(${lib_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS ${lib_name}
    LIBRARY DESTINATION ./lib
    ARCHIVE DESTINATION ./arc   # 动态库生成*.lib必须在导出函数或类之前使用__declspec(dllexport)修饰（windows）
    RUNTIME DESTINATION ./run
    #PUBLIC_HEADER DESTINATION include
)