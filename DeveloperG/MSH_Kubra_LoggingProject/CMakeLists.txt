cmake_minimum_required(VERSION 3.15)

project(MSH_Kubra_LoggingProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MSH_Kubra_LoggingProject
    src/main.cpp
    src/Logger.cpp
    src/NotificationManager.cpp
)

target_include_directories(MSH_Kubra_LoggingProject PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)