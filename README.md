[(7条消息) 补充番外14：cmake笔记_cmake -b_谢白羽的博客-CSDN博客](https://blog.csdn.net/weixin_43679037/article/details/124030345)



## 00_message

* CMake打印信息

## 01_helloworld

* CMake生成C++可执行文件

## 02_libraries

- 生成动态库
- 生成静态库
- 调用动态库
- 调用静态库
- 生成INTERFACE
- 调用INTERFACE

## 03_package

- 添加依赖包
- 添加依赖包组件
- 指定查找路径

## 04_command

- 拷贝文件/目录到生成目录

## 05_file

- 获取文件名

- 拷贝文件的几种方式 `file(COPY)` `configure_file()` `add_custom_target() add_custom_command()`

## 06_function

- CMake使用函数

## 07_list

- 列表list的使用（增、删、改、查）
- foreach()遍历列表

## 08_property

- 给文件设置属性，例如可执行文件依赖于那些dll
- 获取文件属性，例如获取可执行文件依赖于那些dll，从而拷贝这些文件到指定目录

## 09_vs_sln

- 使用脚本生成VS工程

- 生成带调试信息的Release工程

- 添加CMakeSettings.json文件设置releas带调试信息

[VS调试release程序 - 我是小绵羊 - 博客园 (cnblogs.com)](https://www.cnblogs.com/mmmmmmmmm/p/17041265.html)

## 10_install

- 安装生成文件到指定目录
- 安装资源文件/目录到指定目录
- 获取指定目录下的所有文件
- `file(INSTALL SRCS DESTINATION PATH)`拷贝文件

## 11_platform

- 判断当前系统类型

## 12_cpm
- 包管理器