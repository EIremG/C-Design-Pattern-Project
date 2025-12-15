cmake_minimum_required(VERSION 3.15)

project(MySweetHome LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(MySweetHome
    src/main.cpp
    src/ModeManager.cpp
    src/StateManager.cpp
)
