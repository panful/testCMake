cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "mystatic")

# 是否构建动态库
# set(BUILD_SHARED_LIBS NO)

# 定义输出路径
set(LIB_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 设置库文件输出路径
# Windows下会将dll,lib,exp,pdb(Debug模式)文件生成到当前目录下的lib/Debug或(lib/Release)文件夹内
# Linux下带DEBUG或RELEASE的属性无效
if(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/archive) # .lib .pdb
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/library) # 无文件输出
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/runtime) # 无文件输出
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/archive) # lib*.a
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/library) # 无文件输出
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/runtime) # 无文件输出
endif()

# STATIC可以不写，构建方式将使用BUILD_SHARED_LIBS的结果
# 如果BUILD_SHARED_LIBS和add_library构建方式不同，将使用add_library的方式
# 如果BUILD_SHARED_LIBS和add_library都没有指定库的类型，默认创建静态库
# add_library(${target_name} STATIC "include/demo.h" "src/demo.cpp")
add_library(${target_name} "${CMAKE_CURRENT_SOURCE_DIR}/src/demo.cpp")

target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

##############################################################################################
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../call)
install(TARGETS ${target_name}
    RUNTIME DESTINATION target #                 Linux: 无文件输出
    ARCHIVE DESTINATION arc    # Windows: *.lib  Linux: 无文件输出
    LIBRARY DESTINATION lib    #                 Linux: lib*.a
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/demo.h" DESTINATION include)