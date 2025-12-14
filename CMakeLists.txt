cmake_minimum_required(VERSION 3.10)

project(MSH CXX)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

file(GLOB CORE src/core/*.cpp)
file(GLOB DEVICES src/devices/*.cpp)
file(GLOB UI src/ui/*.cpp)

add_executable(MSH
    src/main.cpp
    ${CORE}
    ${DEVICES}
    ${UI}
)
