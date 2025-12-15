cmake_minimum_required(VERSION 3.10)
project(AlarmTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header dosyalarımızın olduğu yer (include/core içindekileri direkt bulsun diye)
include_directories(include/core)

# Kaynak kodlarımızı (CPP) ekliyoruz
# main.cpp src klasöründe, Alarm.cpp src/core klasöründe
add_executable(AlarmTest 
    src/main.cpp 
    src/core/Alarm.cpp
)