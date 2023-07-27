
cmake_minimum_required(VERSION 3.12)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/target_debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/target_release)

function(MyFunc Arg)
    get_filename_component(var_name ${Arg} NAME) # 找到文件名
    string(FIND ${var_name} "_" underscore_pos)  # 获取文件名的下划线位置

    if (underscore_pos GREATER 0)
        string(SUBSTRING ${var_name} 0 ${underscore_pos} number) # 截取文件名下划线之前的数字
        file(GLOB subdirectories ${Arg}/*) # 获取所有子文件夹

        foreach(subdir ${subdirectories})
            get_filename_component(tar_name ${subdir} NAME)     # 获取子文件夹名
            file(GLOB_RECURSE subdir_sources ${subdir}/*.cpp)   # 获取子文件夹中的所有cpp文件
            set(target_name "${number}_${tar_name}")            # 项目名

            # 构建项目
            add_executable(${target_name} ${subdir_sources})

            # 设置项目的一些属性
            #target_include_directories(${target_name} PRIVATE XXX)
            #target_link_directories(${target_name} PRIVATE XXX)
            
            # 安装可执行文件
            install(TARGETS ${target_name} RUNTIME DESTINATION .)

        endforeach(subdir ${subdirectories})
    endif()
endfunction(MyFunc Arg)
    
MyFunc(${CMAKE_CURRENT_SOURCE_DIR}/root/01_test)
MyFunc(${CMAKE_CURRENT_SOURCE_DIR}/root/02_test)