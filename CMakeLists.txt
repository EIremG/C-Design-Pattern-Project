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
)

set(MODE_SOURCES
    src/mode/ModeManager.cpp
    src/mode/StateManager.cpp
    src/mode/ModeMenu.cpp
)

set(TEST_SOURCES
    tests/TestRunner.cpp
)

add_executable(msh
    src/main.cpp
    ${CORE_SOURCES}
    ${MODE_SOURCES}
    ${TEST_SOURCES}
)

if(MSVC)
  target_compile_options(msh PRIVATE /EHsc)
endif()
