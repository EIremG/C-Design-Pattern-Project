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

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/Device.cpp
    src/Event.cpp
    src/MotionEvent.cpp
    src/AlarmEvent.cpp
    src/DeviceFailureEvent.cpp
    src/EventQueue.cpp
    src/EventObjectPool.cpp
    src/EventDispatcher.cpp
    src/Camera.cpp
    src/CameraBuilder.cpp
    src/SecuritySystem.cpp
    src/DeviceManager.cpp
    src/DebugSimulator.cpp
    main.cpp
)

# Header files (for IDE support)
set(HEADERS
    include/Device.h
    include/Event.h
    include/MotionEvent.h
    include/AlarmEvent.h
    include/DeviceFailureEvent.h
    include/EventQueue.h
    include/EventObjectPool.h
    include/EventDispatcher.h
    include/EventObserver.h
    include/EventType.h
    include/Camera.h
    include/CameraBuilder.h
    include/SecuritySystem.h
    include/DeviceManager.h
    include/DebugSimulator.h
)

# Create executable
add_executable(main ${SOURCES} ${HEADERS})
