cmake_minimum_required(VERSION 3.12)
project("test_list")

set(list1 A B C)
set(list2 X Y Z)
set(list3 aa bb cc dd)

message(STATUS "===== test_list =====")

# 获取list长度
list(LENGTH list1 len_list1)
message(STATUS "list1 length: ${len_list1}")

# 访问list指定位置的元素
list(GET list3 0 elem0_list3)
list(GET list3 1 elem1_list3)
list(GET list3 3 2 elem3_2_list3)
message(STATUS "elem 0 with list3: ${elem0_list3} elem 1 with list3: ${elem1_list3}")
message(STATUS "elem 3 2 with list3: ${elem3_2_list3}")

# list添加元素
list(INSERT list1 1 D E)     # 在位置1添加，即位置0之后添加
list(APPEND list2 A B C)     # 在末尾追加
list(PREPEND list3 xx yy zz) # 在最前面添加
message(STATUS "list1: ${list1}")
message(STATUS "list2: ${list2}")
message(STATUS "list3: ${list3}")
list(APPEND list1 ${list2})  # 末尾追加list
message(STATUS "list1 append list2: ${list1}")

# 查找指定元素的位置，没有找到返回-1
message(STATUS "--------------------")
list(FIND list2 A A_index_val)
message("the index of A in list2: ${A_index_val}")
list(FIND list2 H H_index_val)
message("the index of H in list2: ${H_index_val}")

# 删除元素
message(STATUS "--------------------")
list(REMOVE_ITEM list2 Y)     # 删除指定值的元素，即使没有这个值也不会报错
message("remove Y of list2: ${list2}")
list(REMOVE_AT list2 1)       # 删除指定索引的元素，索引超出cmake将报错
message("remove index 1 of list2: ${list2}")
list(REMOVE_DUPLICATES list1) # 删除重复元素，确保列表不包含重复项
message("remove duplicates list1: ${list1}")
list(POP_FRONT list1) # 弹出最前面的一个元素
message("pop front list1: ${list1}")
list(POP_BACK list1)  # 弹出最后面的一个元素
message("pop back list1: ${list1}")
list(POP_FRONT list1 list1_front0 list1_front1) # 弹出的元素保存到变量中，可以多个也可以一个
message("pop front twice list1: ${list1} front0：${list1_front0} front1: ${list1_front1}")

# 翻转
list(REVERSE list1)
message("reverse list1: ${list1}")

# 排序，可以设置排序策略（camke13.3)
list(SORT list1)
message("sort list1: ${list1}")

#---------------------------------------------------------
message(STATUS "--------------------")
# 遍历list
foreach(var IN LISTS list1)
	message(STATUS "${var}")
endforeach()

message(STATUS "--------------------")
# 遍历多个list
foreach(var1 var2 IN ZIP_LISTS list1 list2)
	message(STATUS "var1: ${var1}    var2: ${var2}") 
endforeach()

message(STATUS "--------------------")
# 遍历多个list，只用一个变量
foreach(var IN ZIP_LISTS list1 list3)
	message(STATUS "var1: ${var_0}    var2: ${var_1}") 
endforeach()

message(STATUS "--------------------")
# 遍历多个list，list的长度不一样
foreach(var1 var2 IN ZIP_LISTS list1 list3)
	message(STATUS "var1: ${var1}    var2: ${var2}") 
endforeach()

#---------------------------------------------------------

message(STATUS "--------------------")
# 中断循环
foreach(var IN LISTS list3)
	message(STATUS "${var}")
	
	if(var STREQUAL "bb")
		break()
	endif()
endforeach()

message(STATUS "--------------------")
# 跳过指定成员
foreach(var IN LISTS list3)
	if(var STREQUAL "bb")
		continue()
	endif()
	
	message(STATUS "${var}")
endforeach()

message(STATUS "--------------------")
while(list1)
	list(POP_FRONT list1 list1_front)
	message(STATUS "while get list1: ${list1_front}")
endwhile()

message(STATUS "===== test_list =====")