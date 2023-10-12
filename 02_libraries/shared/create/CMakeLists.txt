cmake_minimum_required(VERSION 3.12)
project("project_02")

set(target_name "myshared")

# 是否构建动态库
set(BUILD_SHARED_LIBS YES)

# 定义输出路径
set(LIB_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 设置库文件输出路径
# Windows下会将dll,lib,exp,pdb(Debug模式)文件生成到当前目录下的bin/Debug或(bin/Release)文件夹内
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE 可以指定不生成Debug或Release目录，Linux下没效果
if(WIN32)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/archive) # .exp .lib
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/library) # 无文件输出
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${LIB_OUTPUT_DIR}/runtime) # .dll .pdb
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/archive) # 无文件输出
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/library) # lib*.so
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}/runtime) # 无文件输出
endif()

# SHARED 可以不写，构建方式将使用BUILD_SHARED_LIBS的结果
# 如果BUILD_SHARED_LIBS和add_library构建方式不同，将使用add_library的方式
# add_library(${target_name} SHARED "${CMAKE_CURRENT_SOURCE_DIR}/src/demo.cpp")
add_library(${target_name} "${CMAKE_CURRENT_SOURCE_DIR}/src/demo.cpp")

target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

##############################################################################################
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../call)
install(TARGETS ${target_name}
    RUNTIME DESTINATION target # Widnows: *.dll  Linux: 无文件输出
    ARCHIVE DESTINATION arc    # Windows: *.lib  Linux: 无文件输出
    LIBRARY DESTINATION lib    #                 Linux: lib*.so
)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/demo.h" DESTINATION include)
