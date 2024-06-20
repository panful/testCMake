set(target_name Example)

add_executable(${target_name} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# 同一个项目，所以此处不需要带命名空间 Math::
# 因为链接的目标设置包含目录时，使用的是 PUBLIC ，所以此处不再需要设置包含目录
target_link_libraries(${target_name} PRIVATE Plus Sub)
