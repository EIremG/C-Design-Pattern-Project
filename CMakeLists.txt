cmake_minimum_required(VERSION 3.10)
project(MySweetHome CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}) # tests/ include ediyorsan işe yarar

set(CORE_SOURCES
    src/core/App.cpp
    src/core/Input.cpp
    src/core/MenuController.cpp
    src/core/SignalFlag.cpp
)

set(TEST_SOURCES
    tests/TestRunner.cpp
)

add_executable(msh
    src/main.cpp
    ${CORE_SOURCES}
    ${TEST_SOURCES}
)

if(MSVC)
  target_compile_options(msh PRIVATE /EHsc)
endif()
