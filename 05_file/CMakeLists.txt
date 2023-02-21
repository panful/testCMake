cmake_minimum_required(VERSION 3.12)
project("project_05")
set(target_name "05_file")

message("----------------------------------------------------------")

# 以递归方式获取当前目录下的f2文件夹中的所有文件
# 子文件夹下的文件也会被获取
FILE(GLOB_RECURSE SRCS1 ${CMAKE_CURRENT_SOURCE_DIR}/f2/*)
# 将获取到的所有文件名添加到list
list(APPEND SRCS_NAME1 ${SRCS1})
# 遍历list打印文件名，list变量不需要带"${}"
foreach(_file_ IN LISTS SRCS_NAME1)
    message(${_file_})
endforeach()

message("----------------------------------------------------------")

# 子文件夹中的文件或文件夹不会被获取
# 会将子文件夹当作文件
FILE(GLOB SRCS2 ${CMAKE_CURRENT_SOURCE_DIR}/f2/*)
list(APPEND SRCS_NAME2 ${SRCS2})
foreach(_file_ IN LISTS SRCS_NAME2)
    message(${_file_})
endforeach()

message("----------------------------------------------------------")

# 所有的cpp文件
FILE(GLOB SRCS3 ${CMAKE_CURRENT_SOURCE_DIR}/f2/*.cpp)
list(APPEND SRCS_NAME3 ${SRCS3})
foreach(_file_ IN LISTS SRCS_NAME3)
    message(${_file_})
endforeach()

message("----------------------------------------------------------")

# configure_file最好用于不经常修改的文件，因为source文件修改，cmake将自动重新运行
# 如果在build路径下执行"cmake .."，则会将src.txt文件拷贝到build目录下，且名称更改为dest.cpp
# 目标即第二个参数必须是一个文件，不能是文件夹
# build目录其实就是${CMAKE_CURRENT_BINARY_DIR}
# 第一个参数的相对父路径是${CMAKE_CURRENT_SOURCE_DIR}
configure_file("src.txt" "dest.cpp")
# 将f1文件夹下的file1.txt文件拷贝到build/path2文件夹下，并重命名为file1.cp.txt
configure_file("f1/file1.txt" "path2/file1_cp.txt")

#configure_file还可以对文件内容进行替换 https://www.jianshu.com/p/2946eeec2489

message("----------------------------------------------------------")

# copy会复制源文件或目录的权限，不会打印信息
# install不会保留原始权限，执行cmake时会打印信息"Installing:xxx"
# 可以使用NO_SOURCE_PERMISSIONS 和USE_SOURCE_PERMISSIONS 选项来覆盖默认值
# 也可以使用FILE_PERMISSIONS 和DIRECTORY_PERMISSIONS 选项显式地指定权限
file(COPY "f1/file2.txt" DESTINATION "path3")
file(INSTALL "f1/file1.txt" DESTINATION "path4")

message("----------------------------------------------------------")