# windows:
# mkdir build && cd build
# cmake ..
# cmake --install .
# cmake --build . 会执行add_custom_command
# add_custom_command 命令可以用来将生成的库文件拷贝到vs生成的debug目录下

#---------------------------------------------------------------------

# add_custom_command 内部不能用if()，也不能使用foreach()
# 可以使用if()或foreach()将add_custom_command包裹起来，例如： 
# foreach() 
#   add_custom_command... 
# endforeach()

#---------------------------------------------------------------------

# add_custom_command()、add_custom_target() 和execute_process()可以用来执行
# 创建、删除、重命名或移动文件和目录等任务。不同平台执行这些任务的命令可能不同，
# 使用CMake本身提供的命令模式即可在不同平台使用相同的命令。
# cmake -E命令列表如下：
# compare_files
# copy
# copy_directory
# copy_if_different
# echo
# env
# make_directory
# md5sum
# remove (CMake 3.17 废弃)
# remove_directory (CMake 3.17 废弃)
# rename
# rm (需要CMake 3.17 或更高版本)
# tar
# time
# touch

#---------------------------------------------------------------------

cmake_minimum_required(VERSION 3.12)
project("project_04_01")
set(target_name "04_01_command")

add_executable(${target_name} main.cpp)

#---------------------------------------------------------------------
# 打印变量，使用IF条件判断
#---------------------------------------------------------------------

add_custom_command(TARGET ${target_name}
    # POST_BUILD表示编译完之后执行该命令，对应的还有PRE_BUILD等选项（PRE_BUILD仅vs支持）
    POST_BUILD
    # -E指的是CMake命令行模式，注意echo命令和cmd中的echo命令不一样
    COMMAND ${CMAKE_COMMAND} -E 
    # 打印：=======Start========
    echo "=======Start========"
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # 如果1==2为真，则打印123，否则打印456
    echo "\"$<IF:$<EQUAL:1,2>,1==2,1!=2>\""
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # 双引号转义，如果是release则打印"release"否则打印""
    echo "\"$<$<CONFIG:Release>:release>\""  
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # debug无需注意大小写，debug模式打印debug，release模式打印release
    echo "\"$<IF:$<CONFIG:debug>,debug,release>\""
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # 字符串"aaa"和"bbb"相等打印aaa==bbb否则打印aaa!=bbb
    echo "\"$<IF:$<STREQUAL:aaa,bbb>,aaa==bbb,aaa!=bbb>\""
    
    # add_custom_command可以包含多个COMMAND命令
    COMMAND ${CMAKE_COMMAND} -E
    # release打印release debug打印debug
    # cmake .. -DCMAKE_BUILD_TYPE=debug，打印debug，注意大小写
    echo "\"$<CONFIGURATION>\""
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # 打印  .../add_custom_command/build/Debug
    echo "\"$<TARGET_FILE_DIR:${target_name}>\""
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
    # 打印  .../add_custom_command/build/Debug/test_demo.exe
    echo "\"$<TARGET_FILE:${target_name}>\""
    
)

add_custom_command(TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        echo "=======End========"
)

#---------------------------------------------------------------------
# 依赖TARGET进行文件拷贝，目录拷贝
#---------------------------------------------------------------------

add_custom_command(TARGET ${target_name}
        POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/build ${CMAKE_CURRENT_SOURCE_DIR}/etc/mybuild

        PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E 
        # 拷贝config目录下的所有文件(包括子目录的文件，不包括config文件夹)到etc目录下
        copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/config ${CMAKE_CURRENT_SOURCE_DIR}/etc

        POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E
        copy ${CMAKE_CURRENT_SOURCE_DIR}/build/$<IF:$<CONFIG:Debug>,Debug,Release>/$<TARGET_FILE_NAME:${target_name}> ${CMAKE_CURRENT_SOURCE_DIR}/etc

    COMMAND ${CMAKE_COMMAND} -E 
        # 拷贝log.txt文件到etc目录下
        copy ${CMAKE_CURRENT_SOURCE_DIR}/log.txt ${CMAKE_CURRENT_SOURCE_DIR}/etc

    COMMAND ${CMAKE_COMMAND} -E
        # 拷贝生成的目标文件到目标文件所在目录下的copy文件夹中（如果含有相同的文件则不拷贝）
        copy_if_different $<TARGET_FILE:${target_name}> $<TARGET_FILE_DIR:${target_name}>/copy/${target_name}.exe
)

#---------------------------------------------------------------------
# 为TARGET生成依赖文件 https://www.cnblogs.com/dangerman/p/6529742.html
#---------------------------------------------------------------------

add_custom_command(OUTPUT myOutputFile.cpp
    # 使用Generator生成依赖文件myOutputFile.cpp，其他cmake命令就可以使用该文件
    COMMAND Generator
)