cmake_minimum_required(VERSION 3.12)
project("test_property")
set(target_name "test_target")

add_executable(${target_name} "main.cpp")

# set_property的第一个参数可以是GLOBAL DIRECTORY TARGET SOURCE INSTALL TEST CACHE中的任意一个

#-----------------------------------------------
# 设置目标属性
set_property(TARGET ${target_name}
	PROPERTY _MY_PROPERTY_1_ val1 val2 val3
)

get_property(resultVal_1 TARGET ${target_name}
	PROPERTY _MY_PROPERTY_1_ 
)

message("====== ${resultVal_1}")

#-----------------------------------------------
# 设置源码属性
set_property(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	PROPERTY _MY_PROPERTY_2_ cpp_file
)

get_property(resultVal_2 SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	PROPERTY _MY_PROPERTY_2_
)

message("====== ${resultVal_2}")

#-----------------------------------------------
# 设置目标属性
set_target_properties(${target_name} PROPERTIES _MY_PROPERTY_3_ target_val) # 一个属性只能有一个值

get_target_property(resultVal_3 ${target_name} _MY_PROPERTY_3_)

message("====== ${resultVal_3}")

#-----------------------------------------------
# 设置源码属性
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	PROPERTIES _MY_PROPERTY_4_ source_val
)

get_source_file_property(resultVal_4 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp _MY_PROPERTY_4_)

message("====== ${resultVal_4}")