cmake_minimum_required (VERSION 3.12)

project ("Multi_PROJECT")

set(CMAKE_CXX_STANDARD 17)

# 所有的子项目都将使用这里设置的生成路径，除非子项目中重新设置生成路径
# CMAKE_RUNTIME_OUTPUT_DIRECTORY 可执行文件(exe pdb)、动态库(dll pdb)
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY 静态库(lib pdb)、动态库(lib exp)加了动态库导出符号才会生成这两个文件
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/target)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/target)

# 包含子目录
add_subdirectory(sources)
