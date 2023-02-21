cmake_minimum_required(VERSION 3.0)
set(target_name "test")
project(${target_name} VERSION 1.0)

# 设置安装路径前缀
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/target)

# 生成可执行文件
add_executable(${target_name} main.cpp)

# 安装file.txt文件到target/files目录下
install(FILES file.txt DESTINATION ./files)

# 在build路径下执行 "cmake .."命令时，会将file_install.txt文件拷贝到build目录下的files文件夹内
file(INSTALL file_install.txt DESTINATION ./files)

# 将整个f1文件夹安装到target/dir目录下，包括f1
install(DIRECTORY f1 DESTINATION ./dir)

# 以递归方式获取当前目录下的f2文件夹中的所有文件
FILE(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/f2/*)

# 将文件名（包括路径）加入到list
list(APPEND SRCS_LIST ${SRCS})

# 遍历list安装文件
foreach(__file__ IN LISTS SRCS_LIST)
	MESSAGE(STATUS "=== ${__file__}")
	install(FILES ${__file__} DESTINATION ./files2)
endforeach()

# 和上面的语句效果一样，只不过如果安装文件太多会报错
#install(FILES ${SRCS_LIST} DESTINATION ./files2)

# 安装指定文件到指定目录
# EXPORT会导出一个*.cmake文件，提供给其他cmake工程调用
#install(TARGETS ${target_name}
#        EXPORT  myTarget
#        LIBRARY DESTINATION mylib
#        ARCHIVE DESTINATION mylib
#        RUNTIME DESTINATION ./path
#        PUBLIC_HEADER DESTINATION include
#       )