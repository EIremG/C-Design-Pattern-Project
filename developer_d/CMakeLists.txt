cmake_minimum_required(VERSION 3.10)
project(MSH_DeveloperD)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ansi -pedantic")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main
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
