**测试EXE调用动态库，动态库又调用静态库，只测试了Windows环境**

## EXE编译并运行依赖的文件
- 动态库的lib
- 动态库的dll

## 执行步骤
```shell
# 编译静态库，并将静态库的lib、头文件拷贝到动态库目录下
cd static/build
cmake ..
cmake --build .
cmake --install . --config debug
# 编译动态库，并将动态库的dll、lib、头文件拷贝到exe目录下
cd shared/build
cmake ..
cmake --build .
cmake --install . --config debug
# 编译可执行文件，并运行exe
cd exe/build
cmake ..
cmake --build .
./exe_shared_static.exe
```