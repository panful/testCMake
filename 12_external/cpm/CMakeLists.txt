cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(cpm_test)

set(target_name "cpm_demo")
add_executable(${target_name} "main.cpp")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage(
  NAME glm                      # 库名称
  GITHUB_REPOSITORY g-truc/glm  # 库路径
  GIT_TAG 0.9.9.8               # Git标签
)

target_link_libraries(${target_name} PRIVATE glm)
