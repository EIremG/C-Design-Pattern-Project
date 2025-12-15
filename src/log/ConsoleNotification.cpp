// ConsoleNotification.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Console bildirim implementasyonu

#include "log/ConsoleNotification.h"
#include <iostream>

// Constructor
ConsoleNotification::ConsoleNotification() {
}

// Destructor
ConsoleNotification::~ConsoleNotification() {
}

// LLR19, LLR36: Konsola bildirim yazdırır
void ConsoleNotification::send(const std::string& message) {
    std::cout << "[CONSOLE NOTIFICATION] " << message << std::endl;
}

// Bildirim tipini döndürür
std::string ConsoleNotification::getType() const {
    return "Console";
}