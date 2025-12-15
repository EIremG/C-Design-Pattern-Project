cmake_minimum_required(VERSION 3.10)
project(MySweetHome CXX)

set(CMAKE_CXX_STANDARD 11)
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

set(UI_SOURCES
    
    src/ui/HelpPages.cpp
    src/ui/DeviceUI.cpp
)

set(LOG_SOURCES
    src/log/AlarmNotification.cpp
    src/log/ConsoleNotification.cpp
    src/log/EmailNotification.cpp
    src/log/JSONLogFormatter.cpp
    src/log/LogFormatterFactory.cpp
    src/log/Logger.cpp
    src/log/NotificationFactory.cpp
    src/log/NotificationManager.cpp
    src/log/SMSNotification.cpp
    src/log/XMLLogFormatter.cpp
    src/log/YAMLLogFormatter.cpp
)

set(ALARM_SOURCES
    src/alarm/Alarm.cpp
    src/alarm/AlarmDemo.cpp
)

set(DEVICES_SOURCES
    src/devices/HomeDevice.cpp
    src/devices/DeviceFactory.cpp
    src/devices/HomeDeviceManager.cpp
    src/devices/CriticalDeviceGuard.cpp

    src/devices/LightDevice.cpp
    src/devices/TVDevice.cpp
    src/devices/CameraDevice.cpp
    src/devices/MusicSystemDevice.cpp

    src/devices/DetectorDevice.cpp
    src/devices/SmokeDetectorDevice.cpp
    src/devices/GasDetectorDevice.cpp
    src/devices/AlarmDevice.cpp

    src/devices/DetectorFactory.cpp
)

set(TEST_SOURCES
    tests/TestRunner.cpp
)

add_executable(msh
    src/main.cpp
    ${DEVICES_SOURCES}
    ${CORE_SOURCES}
    ${MODE_SOURCES}
    ${SIM_SOURCES}
    ${TEST_SOURCES} 
    ${ALARM_SOURCES}
    ${UI_SOURCES}
    ${LOG_SOURCES}
)

if(MSVC)
  target_compile_options(msh PRIVATE /EHsc)
endif()
