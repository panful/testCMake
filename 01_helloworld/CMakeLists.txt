cmake_minimum_required(VERSION 3.12)
project("project_01")

set(target_name "01_helloworld")

# 设置DEBUG和RELEASE下的exe输出路径
# 如果不带DEBUG或RELEASE，Windows下会在输出目录创建一个Debug或Release文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/target_debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/target_release)

add_executable(${target_name} "main.cpp")

# 命令行执行步骤：
# cd build
# cmake ..                           # 生成cmake缓存
# cmake --build .                    # 生成可执行程序，默认Debug模式
# cmake --build . --config debug     # 指定以debug模式生成可执行程序(debug可以修改为release)
# cmake --install .                  # 执行安装命令

# 如果没有设置CMAKE_INSTALL_PREFIX，会安装到C盘，且需要管理员权限，安装之前需要生成release目标文件（调用cmake --build . --config release)