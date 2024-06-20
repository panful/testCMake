cmake_minimum_required(VERSION 3.12)
project(TestUsePackage)

set(target_name "usePackage")

# 设置find_package的查找路径
set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib/cmake/Math)

# find_package(Math REQUIRED)

find_package(Math 
    COMPONENTS 
        Plus Sub
    QUIET
)

if(Math_FOUND)
    message(" --- Math_FOUND         = ${Math_FOUND}")
    message(" --- Math_INCLUDE_DIR   = ${Math_INCLUDE_DIR}")
    message(" --- Math_LIBRARIES     = ${Math_LIBRARIES}")
    message(" --- Math_LIBRARIES_DIR = ${Math_LIBRARIES_DIR}")
endif()

add_executable(${target_name} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# 使用 Plus Sub 链接，还需要指定库的路径
# target_link_directories(${target_name} PRIVATE ${Math_LIBRARIES_DIR})

# 使用 Math::Plus Math::Sub 链接，就不再需要指定头文件路径，也不再需要指定库的路径
target_link_libraries(${target_name} PRIVATE ${Math_LIBRARIES})

# 使用 Plus Sub 链接，还需要指定头文件路径，否则找不到对应的头文件
# target_link_libraries(${target_name} PRIVATE Plus Sub)
# target_include_directories(${target_name} PRIVATE ${Math_INCLUDE_DIR})

add_custom_command(TARGET ${target_name}
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
    copy_if_different ${Math_LIBRARIES_DIR}/../bin/Plus.dll $<TARGET_FILE_DIR:${target_name}>/Plus.dll
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
    copy_if_different ${Math_LIBRARIES_DIR}/../bin/Sub.dll $<TARGET_FILE_DIR:${target_name}>/Sub.dll
)
