
if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /IGNORE:4099")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /IGNORE:4099")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")
endif()

find_package(GTest
    PATHS
        ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/cmake/GTest
    NO_DEFAULT_PATH    
)

# 创建一个可执行文件（测试程序）
set(target_name "unit_test")
file(GLOB SRCS *.cpp)
set(SRCS ${SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/myserver.cpp
)
add_executable(${target_name} ${SRCS} )
target_link_libraries(${target_name} PRIVATE GTest::gtest GTest::gmock)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

# 向项目添加一个测试
# NAME后面是这个测试的名称
# COMMAND后面是要运行的测试命令，可以是一个可执行文件、脚本或任何你想要作为测试的命令
add_test(NAME my_unit_test COMMAND ${target_name})
