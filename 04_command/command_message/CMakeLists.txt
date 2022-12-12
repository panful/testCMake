cmake_minimum_required(VERSION 3.12)
project("project_04")
set(target_name "04_command")

add_executable(${target_name} main.cpp)

add_custom_command(TARGET ${target_name}
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
