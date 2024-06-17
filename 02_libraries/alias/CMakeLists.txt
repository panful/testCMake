cmake_minimum_required(VERSION 3.12)

project(MyProject VERSION 1.0 LANGUAGES CXX)
 
set(COMPONENT_NAME MyLib)
 
add_library(${COMPONENT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp)
target_include_directories(${COMPONENT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 别名
add_library(${PROJECT_NAME}::${COMPONENT_NAME} ALIAS ${COMPONENT_NAME})

#------------------------------
set(EXE_NAME MyExe)
add_executable(${EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${EXE_NAME} PRIVATE ${PROJECT_NAME}::${COMPONENT_NAME}) # 使用别名就可以链接
target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
