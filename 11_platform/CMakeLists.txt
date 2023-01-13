cmake_minimum_required(VERSION 3.12)
project("MyCMake")

if(WIN32)
    message("WIN32")
elseif(UNIX)
    message("UNIX")
else()
    message("else")
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("WIN32")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("WIN32")
endif()

message(${CMAKE_HOST_SYSTEM_NAME})
message(${CMAKE_SYSTEM_NAME})
