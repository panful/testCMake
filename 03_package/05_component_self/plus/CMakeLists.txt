set(target_name Plus)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plus.cpp
)

add_library(${target_name} SHARED ${SRCS})
target_include_directories(${target_name} PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

add_library(${PROJECT_NAME}::${target_name} ALIAS ${target_name})

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/plus.h)
set_target_properties(${target_name} PROPERTIES PUBLIC_HEADER ${HEADERS})
