set(target_name "MyMath")
add_library(${target_name} INTERFACE)
target_include_directories(${target_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}../../include)
target_link_directories(${target_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)