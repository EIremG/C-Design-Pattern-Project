cmake_minimum_required(VERSION 3.10)
project(SmartHome_DeviceFramework)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/Device.cpp
    src/Detector.cpp
    src/SmokeDetector.cpp
    src/GasDetector.cpp
    src/DetectorFactory.cpp
    src/Light.cpp
    src/Camera.cpp
    src/TV.cpp
    src/MusicSystem.cpp
    src/Alarm.cpp
    src/DeviceFactory.cpp
    src/DeviceManager.cpp
    src/CriticalDeviceGuard.cpp
    src/Logger.cpp
)

# Executable
add_executable(SmartHome ${SOURCES})

# Enable warnings
if(MSVC)
    target_compile_options(SmartHome PRIVATE /W4)
else()
    target_compile_options(SmartHome PRIVATE -Wall -Wextra -Wpedantic)
endif()