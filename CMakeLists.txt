cmake_minimum_required(VERSION 3.10)
project(MySweetHome_AlarmModule)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
    Alarm.cpp
    Alarm.h
)

add_executable(AlarmTest ${SOURCES})