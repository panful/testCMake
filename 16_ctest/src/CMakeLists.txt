
set(target_name "MyApp")
set(SOURCES__ "main.cpp" "../lib/client.cpp" "../lib/myserver.cpp")
add_executable(${target_name} ${SOURCES__})
target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
