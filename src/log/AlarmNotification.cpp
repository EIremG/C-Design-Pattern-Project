// AlarmNotification.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Alarm bildirim implementasyonu (simülasyon)

#include "log/AlarmNotification.h"
#include <iostream>

// Constructor
AlarmNotification::AlarmNotification() {
}

// Destructor
AlarmNotification::~AlarmNotification() {
}

// LLR19, LLR36: Alarm tetiklenmesini simüle eder
void AlarmNotification::send(const std::string& message) {
    // Alarm simülasyonu - konsola özel formatta yazdırılır
    std::cout << "\n";
    std::cout << "========================================" << std::endl;
    std::cout << "    ALARM TRIGGERED!" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\n";
}

// Bildirim tipini döndürür
std::string AlarmNotification::getType() const {
    return "Alarm";
}