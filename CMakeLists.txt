cmake_minimum_required(VERSION 3.10)
project(MySweetHome CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CORE_SOURCES
    src/core/App.cpp
    src/core/Input.cpp
    src/core/MenuController.cpp
    src/core/SignalFlag.cpp
    src/core/AppServices.cpp
    src/core/Console.cpp

)

set(MODE_SOURCES
    src/mode/ModeManager.cpp
    src/mode/StateManager.cpp
    src/mode/ModeMenu.cpp
)

set(SIM_SOURCES
    src/sim/AlarmEvent.cpp
    src/sim/Camera.cpp
    src/sim/CameraBuilder.cpp
    src/sim/DebugSimulator.cpp
    src/sim/Device.cpp
    src/sim/DeviceFailureEvent.cpp
    src/sim/DeviceManager.cpp
    src/sim/Event.cpp
    src/sim/EventDispatcher.cpp
    src/sim/EventObjectPool.cpp
    src/sim/EventQueue.cpp
    src/sim/MotionEvent.cpp
    src/sim/SecuritySystem.cpp

)

set(ALARM_SOURCES
    src/alarm/Alarm.cpp
    src/alarm/AlarmDemo.cpp
)

set(TEST_SOURCES
    tests/TestRunner.cpp
)

add_executable(msh
    src/main.cpp
    ${CORE_SOURCES}
    ${MODE_SOURCES}
    ${SIM_SOURCES}
    ${TEST_SOURCES} 
    ${ALARM_SOURCES}
)

if(MSVC)
  target_compile_options(msh PRIVATE /EHsc)
endif()
