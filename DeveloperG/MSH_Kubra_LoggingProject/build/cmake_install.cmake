# Install script for directory: C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MSH_Kubra_LoggingProject")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/Debug/MSH_Logging.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/Release/MSH_Logging.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/MinSizeRel/MSH_Logging.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/RelWithDebInfo/MSH_Logging.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/CMakeFiles/MSH_Logging.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/CMakeFiles/MSH_Logging.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/CMakeFiles/MSH_Logging.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/CMakeFiles/MSH_Logging.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/Logger.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/LogFormatter.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/LogFormatterFactory.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/JSONLogFormatter.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/XMLLogFormatter.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/YAMLLogFormatter.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/NotificationManager.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/Notification.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/NotificationFactory.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/ConsoleNotification.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/SMSNotification.h"
    "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/include/AlarmNotification.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/kmfm2/OneDrive/Masaüstü/C-Design-Pattern-Project/DeveloperG/MSH_Kubra_LoggingProject/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
