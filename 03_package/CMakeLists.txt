cmake_minimum_required(VERSION 3.12)
project ("project_00")

set(target_name "00_message")

#find_package(Qt6 COMPONENTS Core)

# 将qmake.exe所在的路径(包括qmake.exe)保存到_my_qmake_execute
#get_target_property(_my_qmake_execute Qt6::qmake IMPORTED_LOCATION)
# 将_my_qmake_execute的路径部分(不包括文件名)保存到_my_qt_bin_dir
#get_filename_component(_my_qt_bin_dir ${_my_qmake_execute} DIRECTORY)

message( STATUS "=====================" )
message( STATUS "${_my_qmake_execute}" )
message( STATUS "${_my_qt_bin_dir}" )
message( STATUS "${PARSE_ARGV}" )
message( STATUS "$<TARGET_FILE_DIR:${target_name}>") # 构建项目(cmake --build .)才能使TARGET_FILE_DIR生效
message( STATUS "=====================" )