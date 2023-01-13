# windows:
# mkdir build && cd build
# cmake ..
# cmake --install .
# cmake --build . 会执行add_custom_command
# add_custom_command 命令可以用来将生成的库文件拷贝到vs生成的debug目录下


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

add_custom_command(TARGET ${target_name}
		POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E
		copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/build ${CMAKE_CURRENT_SOURCE_DIR}/etc/mybuild
		PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E 
		# 拷贝config目录下的所有文件(包括子目录的文件，不包括config文件夹)到etc目录下
		copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/config ${CMAKE_CURRENT_SOURCE_DIR}/etc
# add_custom_command 内部不能用if()endif()
#if(WIN32)
		POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E
		copy ${CMAKE_CURRENT_SOURCE_DIR}/build/$<IF:$<CONFIG:Debug>,Debug,Release>/$<TARGET_FILE_NAME:${target_name}> ${CMAKE_CURRENT_SOURCE_DIR}/etc
#endif()
	COMMAND ${CMAKE_COMMAND} -E 
		# 拷贝log.txt文件到etc目录下
		copy ${CMAKE_CURRENT_SOURCE_DIR}/log.txt ${CMAKE_CURRENT_SOURCE_DIR}/etc
		# 拷贝生成的目标文件到目标文件所在目录下的copy文件夹中（如果含有相同的文件则不拷贝）
	COMMAND ${CMAKE_COMMAND} -E
		copy_if_different $<TARGET_FILE:${target_name}> $<TARGET_FILE_DIR:${target_name}>/copy/${target_name}.exe
)