
# linux下执行以下命令，windows没用
# mkdir build && cd build
# cmake ..
# make MyTask

# windows执行以下命令
# cmake --build . --target MyTask

cmake_minimum_required(VERSION 3.12)
project("project_04_02")

set(IsDebug "$<IF:$<CONFIG:Debug>,is deubg,not debug>")

add_custom_target(MyTask
    COMMAND ${CMAKE_COMMAND} -E 
    # 拷贝config目录下的所有文件(包括子目录的文件)到etc目录下
    copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/config ${CMAKE_CURRENT_SOURCE_DIR}/etc

    COMMAND ${CMAKE_COMMAND} -E 
    # 拷贝log.txt文件到etc目录下
    copy ${CMAKE_CURRENT_SOURCE_DIR}/log.txt ${CMAKE_CURRENT_SOURCE_DIR}/etc

    COMMENT "Result of generator expression :"
    COMMAND ${CMAKE_COMMAND} -E echo "${IsDebug}"
    # VERBATIM 可以保证在不同平台CMakeLists解析的结果一致
    VERBATIM
)