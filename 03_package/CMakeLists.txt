cmake_minimum_required(VERSION 3.12)
project ("project_03")

set(target_name "03_package")

message("---------------------------------------------------------------")

# 判断是否安装了qt6
find_package(Qt6)
if(Qt6_FOUND)
    message("qt6 found")
endif()

message("---------------------------------------------------------------")

# QUIET 关闭找到包时cmake自带的打印信息
# 如果没有找到仍会打印错误信息
find_package(Qt6 QUIET) # 不打印任何信息
find_package(Python2)   # 打印错误信息

message("---------------------------------------------------------------")

# 查找Qt的Core组件
find_package(Qt6 COMPONENTS Core)

message("---------------------------------------------------------------")

# 指定查找包的路径
# 在myPaths路径下查找Qt6的Core组件
find_package(Qt6 
    COMPONENTS
        Core
    PATHS
        myPaths
    NO_DEFAULT_PATH
)

message("---------------------------------------------------------------")

# 查找MPI库
find_package(MPI)

if(MPI_FOUND)
    message("MPI_CXX_INCLUDE_DIRS = ${MPI_CXX_INCLUDE_DIRS}")
    message("MPI_CXX_LIBRARIES = ${MPI_CXX_LIBRARIES}")
    message("MPI_COMPILER = ${MPI_COMPILER}")
    message("MPI_EXECUTABLE_SUFFIX = ${MPI_EXECUTABLE_SUFFIX}")
    message("MPI_VERSION = ${MPI_VERSION}")
    message("MPI_CXX_COMPILER = ${MPI_CXX_COMPILER}")
    message("MPI_CXX_LINK_FLAGS = ${MPI_CXX_LINK_FLAGS}")
    message("MPIEXEC_EXECUTABLE = ${MPIEXEC_EXECUTABLE}")
    message("MPIEXEC_NUMPROC_FLAG = ${MPIEXEC_NUMPROC_FLAG}")
    message("MPIEXEC_MAX_NUMPROCS = ${MPIEXEC_MAX_NUMPROCS}")
    message("MPIEXEC_PREFLAGS = ${MPIEXEC_PREFLAGS}")
    message("MPIEXEC_POSTFLAGS = ${MPIEXEC_POSTFLAGS}")
endif()

message("---------------------------------------------------------------")

# 查找Python3的Numpy组件
find_package(Python3 COMPONENTS NumPy)

if (Python3_FOUND)
  message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
  message("_Python3_EXECUTABLE: ${_Python3_EXECUTABLE}\n")
 
  message("Python3_INCLUDE_DIR: ${Python3_INCLUDE_DIR}")
  message("_Python3_INCLUDE_DIR: ${_Python3_INCLUDE_DIR}\n")
 
  message("Python3_LIBRARY_DEBUG: ${Python3_LIBRARY_DEBUG}")
  message("_Python3_LIBRARY_DEBUG: ${_Python3_LIBRARY_DEBUG}\n")
 
  message("Python3_LIBRARY_RELEASE: ${Python3_LIBRARY_RELEASE}")
  message("_Python3_LIBRARY_RELEASE: ${_Python3_LIBRARY_RELEASE}\n")
 
  message("Python3_NumPy_INCLUDE_DIR: ${Python3_NumPy_INCLUDE_DIR}")
  message("_Python3_NumPy_INCLUDE_DIR: ${_Python3_NumPy_INCLUDE_DIR}\n")
endif()

message("---------------------------------------------------------------")