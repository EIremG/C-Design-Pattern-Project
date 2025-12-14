# CMakeLists.txt
# Developer G - Kübra Akpınar
# MSH Logging & Notification Module Build System

cmake_minimum_required(VERSION 3.10)

# Proje tanımı
project(MSH_Kubra_LoggingProject VERSION 1.0 LANGUAGES CXX)

# C++98 standardı (proje gereksinimine uygun)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include dizinini ekle
include_directories(${PROJECT_SOURCE_DIR}/include)

# Kaynak dosyaları
set(SOURCES
    # Logger modülü
    src/Logger.cpp
    src/LogFormatterFactory.cpp
    src/JSONLogFormatter.cpp
    src/XMLLogFormatter.cpp
    src/YAMLLogFormatter.cpp
    
    # Notification modülü
    src/NotificationManager.cpp
    src/NotificationFactory.cpp
    src/ConsoleNotification.cpp
    src/SMSNotification.cpp
    src/EmailNotification.cpp
    src/AlarmNotification.cpp
    
    # Main test programı
    src/main.cpp
)

# Header dosyaları (IDE'ler için)
set(HEADERS
    include/Logger.h
    include/LogFormatter.h
    include/LogFormatterFactory.h
    include/JSONLogFormatter.h
    include/XMLLogFormatter.h
    include/YAMLLogFormatter.h
    include/NotificationManager.h
    include/Notification.h
    include/NotificationFactory.h
    include/ConsoleNotification.h
    include/SMSNotification.h
    include/EmailNotification.h
    include/AlarmNotification.h
)

# Executable oluştur
add_executable(MSH_Logging ${SOURCES} ${HEADERS})

# Compiler uyarıları
if(MSVC)
    target_compile_options(MSH_Logging PRIVATE /W4)
else()
    target_compile_options(MSH_Logging PRIVATE -Wall -Wextra -pedantic)
endif()

# Build tipi mesajı
message(STATUS "========================================")
message(STATUS "MSH Logging & Notification Module")
message(STATUS "Developer G - Kübra Akpınar")
message(STATUS "========================================")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: C++98")
message(STATUS "========================================")

# Install kuralları (opsiyonel)
install(TARGETS MSH_Logging DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include)

# Test için custom target (opsiyonel)
add_custom_target(run
    COMMAND $<TARGET_FILE:MSH_Logging>
    DEPENDS MSH_Logging
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Running MSH Logging test program..."
)
