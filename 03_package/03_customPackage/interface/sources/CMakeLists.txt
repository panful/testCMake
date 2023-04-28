
set(target_name "MyMath")
set(CMAKE_CXX_STANDARD 20)

set(GLOBAL_FILE     "global/global.h")
set(HEADERS_FILE    "include/myMath.h")
set(SRCS_FILE       "src/myMath.cpp")

# 是否编译为静态库
option(STATIC_LIB "compile static lib" ON)

if(STATIC_LIB)
    message("===== This library type: staic =====")
    add_definitions(-DMyMath_STATIC)
    add_library(${target_name} STATIC ${GLOBAL_FILE} ${HEADERS_FILE} ${SRCS_FILE})
else()
    message("===== This library type: dynamic =====")
    add_library(${target_name} SHARED ${GLOBAL_FILE} ${HEADERS_FILE} ${SRCS_FILE})
endif()

target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/global)

install(TARGETS ${target_name}
    RUNTIME DESTINATION ${INSTALL_DIR}/bin
    ARCHIVE DESTINATION ${INSTALL_DIR}/lib
)