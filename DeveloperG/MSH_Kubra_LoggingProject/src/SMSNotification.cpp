// SMSNotification.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: SMS bildirim implementasyonu (simülasyon)

#include "SMSNotification.h"
#include <iostream>

// Constructor
SMSNotification::SMSNotification() {
}

// Destructor
SMSNotification::~SMSNotification() {
}

// LLR19: "A SMS is sent" formatında simülasyon mesajı
void SMSNotification::send(const std::string& message) {
    // LLR19'da belirtilen format: "A SMS is sent: [message]"
    std::cout << "A SMS is sent: " << message << std::endl;
}

// Bildirim tipini döndürür
std::string SMSNotification::getType() const {
    return "SMS";
}