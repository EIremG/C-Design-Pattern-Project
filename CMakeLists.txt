cmake_minimum_required(VERSION 3.10)
project(DeveloperH CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CORE_SOURCES
    src/core/Console.cpp
)

set(UI_SOURCES
    src/ui/Input.cpp
    src/ui/HelpPages.cpp
    src/ui/DeviceUI.cpp
)

add_executable(devh
    src/main.cpp
    ${CORE_SOURCES}
    ${UI_SOURCES}
)

if(MSVC)
  target_compile_options(devh PRIVATE /EHsc)
endif()
