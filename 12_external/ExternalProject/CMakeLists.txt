cmake_minimum_required(VERSION 3.12)

project(ExternalProject_demo)

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")
endif()

include(ExternalProject)

set(gtest_proj "gtest_proj_dir")
ExternalProject_Add(
    ${gtest_proj}                                   # gtest 解压到该目录，即gtest源码目录前缀，一般都是使用原本的项目名
    URL https://github.com/google/googletest/archive/release-1.10.0.zip
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/gtest_dir    # gtest 所在的目录
    DOWNLOAD_EXTRACT_TIMESTAMP OFF                  # 不更新解压缩的时间戳
    INSTALL_COMMAND ""                              # 不安装项目
)

ExternalProject_Get_Property(${gtest_proj}  SOURCE_DIR BINARY_DIR)

message("====== ${SOURCE_DIR}")
message("====== ${BINARY_DIR}")

set(lib_gtest "lib_gtest")
add_library(${lib_gtest} IMPORTED STATIC GLOBAL)
add_dependencies(${lib_gtest} ${gtest_proj})
# 库文件的路径，使用该库的项目会用到，注意：不同平台、不同环境(Debug Release)路径可能都会变化
# 因为导入的库是在build时编译的，所以需要预先定义好库文件和头文件的位置(target_link_libraries include...)
set_target_properties(${lib_gtest} PROPERTIES 
    "IMPORTED_LOCATION" "${BINARY_DIR}/lib/Debug/gtestd.lib"
)

set(target_name test_external_project)
add_executable(${target_name} "main.cpp")
target_include_directories(${target_name} PRIVATE ${SOURCE_DIR}/googletest/include)
target_link_libraries(${target_name} PRIVATE ${lib_gtest})
