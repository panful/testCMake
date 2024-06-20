set(target_name Plus)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plus.cpp
)
 
add_library(${target_name} SHARED ${SRCS})
# 设置为 PUBLIC 就不需要添加 INTERFACE 库，其他目标使用该目标时，不再需要设置该目标的包含路径
target_include_directories(${target_name} PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_library(${PROJECT_NAME}::${target_name} ALIAS ${target_name})

# 即使 target_include_directories 使用的是 PUBLIC 此处仍需设置 PUBLIC_HEADER
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/plus.h)
set_target_properties(${target_name} PROPERTIES PUBLIC_HEADER ${HEADERS})
