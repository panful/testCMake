cmake_minimum_required(VERSION 3.12)
project ("project_00")

set(target_name "00_message")

# 查找Qt的Core组件
find_package(Qt6 COMPONENTS Core)

# 指定查找包的路径
find_package(Qt6 
	COMPONENTS
		Core
	QUIET
	PATHS
		myPaths
	NO_DEFAULT_PATH
)

message("---------------------------------------")
	
find_package(MPI)

if(MPI_FOUND)
	message("MPI_CXX_INCLUDE_DIRS = ${MPI_CXX_INCLUDE_DIRS}")
	message("MPI_CXX_LIBRARIES = ${MPI_CXX_LIBRARIES}")
	message("MPI_COMPILER = ${MPI_COMPILER}")
	message("MPI_EXECUTABLE_SUFFIX = ${MPI_EXECUTABLE_SUFFIX}")
	message("MPI_VERSION = ${MPI_VERSION}")
	message("MPI_CXX_COMPILER = ${MPI_CXX_COMPILER}")
	message("MPI_CXX_LINK_FLAGS = ${MPI_CXX_LINK_FLAGS}")
	#message("MPI::MPI_CXX = ${MPI::MPI_CXX}")
	message("MPIEXEC_EXECUTABLE = ${MPIEXEC_EXECUTABLE}")
	message("MPIEXEC_NUMPROC_FLAG = ${MPIEXEC_NUMPROC_FLAG}")
	message("MPIEXEC_MAX_NUMPROCS = ${MPIEXEC_MAX_NUMPROCS}")
	message("MPIEXEC_PREFLAGS = ${MPIEXEC_PREFLAGS}")
	message("MPIEXEC_POSTFLAGS = ${MPIEXEC_POSTFLAGS}")
endif()

message("---------------------------------------")

find_package(Python3 COMPONENTS NumPy)

if (Python3_FOUND)
  message(STATUS "Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
  message(STATUS "_Python3_EXECUTABLE: ${_Python3_EXECUTABLE}\n")
 
  message(STATUS "Python3_INCLUDE_DIR: ${Python3_INCLUDE_DIR}")
  message(STATUS "_Python3_INCLUDE_DIR: ${_Python3_INCLUDE_DIR}\n")
 
  message(STATUS "Python3_LIBRARY_DEBUG: ${Python3_LIBRARY_DEBUG}")
  message(STATUS "_Python3_LIBRARY_DEBUG: ${_Python3_LIBRARY_DEBUG}\n")
 
  message(STATUS "Python3_LIBRARY_RELEASE: ${Python3_LIBRARY_RELEASE}")
  message(STATUS "_Python3_LIBRARY_RELEASE: ${_Python3_LIBRARY_RELEASE}\n")
 
  message(STATUS "Python3_NumPy_INCLUDE_DIR: ${Python3_NumPy_INCLUDE_DIR}")
  message(STATUS "_Python3_NumPy_INCLUDE_DIR: ${_Python3_NumPy_INCLUDE_DIR}\n")
endif()