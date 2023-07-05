
set(target_name "project_2")

add_executable(${target_name} "main.cpp")

# 单独设置这个项目的生成路径
set_target_properties(${target_name} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target_custom
)
