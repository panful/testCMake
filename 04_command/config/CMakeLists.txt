cmake_minimum_required(VERSION 3.12)
project("project_01")
set(target_name "01_helloworld")
add_executable(${target_name} "main.cpp")

add_custom_command(TARGET ${target_name}
	
	COMMAND ${CMAKE_COMMAND} -E
		#copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/build/$<IF:$<CONFIG:Debug>,Debug,Release> ${CMAKE_CURRENT_SOURCE_DIR}/hhhh
		copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/build ${CMAKE_CURRENT_SOURCE_DIR}/hhhh
)

#add_custom_command(TARGET ${target_name}
#	COMMAND ${CMAKE_COMMAND} -E 
#		# 拷贝config目录下的所有文件(包括子目录的文件，不包括config文件夹)到etc目录下
#		copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/config ${CMAKE_CURRENT_SOURCE_DIR}/etc
#	COMMAND ${CMAKE_COMMAND} -E 
#		# 拷贝log.txt文件到etc目录下
#		copy ${CMAKE_CURRENT_SOURCE_DIR}/log.txt ${CMAKE_CURRENT_SOURCE_DIR}/etc
#		# 拷贝生成的目标文件到目标文件所在目录下的copy文件夹中（如果含有相同的文件则不拷贝）
#	COMMAND ${CMAKE_COMMAND} -E
#		copy_if_different $<TARGET_FILE:${target_name}> $<TARGET_FILE_DIR:${target_name}>/copy/${target_name}.exe
#)