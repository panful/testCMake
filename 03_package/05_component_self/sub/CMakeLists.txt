set(target_name Sub)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sub.cpp
)

add_library(${target_name} SHARED ${SRCS})
# 包含目录设置为 PUBLIC，同一个项目内其他目标链接该目标时，就不需要再设置该目标的包含目录
target_include_directories(${target_name} PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_library(${PROJECT_NAME}::${target_name} ALIAS ${target_name})

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/sub.h)
set_target_properties(${target_name} PROPERTIES PUBLIC_HEADER ${HEADERS})
