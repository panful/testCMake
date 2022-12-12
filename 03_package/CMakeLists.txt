cmake_minimum_required(VERSION 3.12)
project ("project_00")

set(target_name "00_message")

#find_package(Qt6 COMPONENTS Core)

# 将qmake.exe所在的路径(包括qmake.exe)保存到_my_qmake_execute
#get_target_property(_my_qmake_execute Qt6::qmake IMPORTED_LOCATION)
# 将_my_qmake_execute的路径部分(不包括文件名)保存到_my_qt_bin_dir
#get_filename_component(_my_qt_bin_dir ${_my_qmake_execute} DIRECTORY)

message( STATUS "=====================" )
message( STATUS "${_my_qmake_execute}" )
message( STATUS "${_my_qt_bin_dir}" )
message( STATUS "${PARSE_ARGV}" )
message( STATUS "$<TARGET_FILE_DIR:${target_name}>") # 构建项目(cmake --build .)才能使TARGET_FILE_DIR生效
message( STATUS "=====================" )

find_package(MPI)
if(MPI_FOUND)
	message("+++++++++++++++++++++++++++")
	
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
	
	message("+++++++++++++++++++++++++++")
endif()