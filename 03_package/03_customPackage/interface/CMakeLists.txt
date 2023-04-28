cmake_minimum_required(VERSION 3.12)

project("module_demo")

# 动态库: cmake .. -D STATIC_LIB=OFF 
# 静态库: cmake .. -D STATIC_LIB=ON （默认静态库）

# 动态库(*.dll *.pdb)的输出路径为bin (*.lib *.exp)的输出路径为lib
# 静态库(*.lib *.pdb)的输出路径为lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(sources)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyMathConfig.cmake DESTINATION ${CMAKE_BINARY_DIR}/lib/cmake)

set(INSTALL_DIR "C:" CACHE STRING "This is install directory")
message("===== install dir: ${INSTALL_DIR} =====")

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyMathConfig.cmake DESTINATION ${INSTALL_DIR}/lib/cmake)
