cmake_minimum_required(VERSION 3.10)
project(MSH_DeveloperD)

# C++ Standard
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic")

# Build type (default to Release if not specified)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Source files
set(SOURCES
    Device.cpp
    Event.cpp
    MotionEvent.cpp
    AlarmEvent.cpp
    DeviceFailureEvent.cpp
    EventQueue.cpp
    EventObjectPool.cpp
    EventDispatcher.cpp
    Camera.cpp
    CameraBuilder.cpp
    SecuritySystem.cpp
    DeviceManager.cpp
    DebugSimulator.cpp
    main.cpp
)

# Header files (for IDE support)
set(HEADERS
    Device.h
    Event.h
    MotionEvent.h
    AlarmEvent.h
    DeviceFailureEvent.h
    EventQueue.h
    EventObjectPool.h
    EventDispatcher.h
    EventObserver.h
    EventType.h
    Camera.h
    CameraBuilder.h
    SecuritySystem.h
    DeviceManager.h
    DebugSimulator.h
)

# Create executable
add_executable(main ${SOURCES} ${HEADERS})
