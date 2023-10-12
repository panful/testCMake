**测试可执行文件调用静态库**

## 一、可执行文件编译并运行需要依赖的文件
### 1.Windows
- 静态库的lib
### 2.Linux
- lib*.a
## 二、执行步骤
```shell
# 编译静态库，并将动态库的lib、头文件拷贝到可执行文件的目录下
cd create/build
cmake ..
cmake --build .
cmake --install . --config debug
# 编译可执行文件，并运行
cd call/build
cmake ..
cmake --build .
../target/callStatic.exe
```