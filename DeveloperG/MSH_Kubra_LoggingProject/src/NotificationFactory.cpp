// NotificationFactory.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Factory Method Pattern - Notification üretimi

#include "NotificationFactory.h"
#include "ConsoleNotification.h"
#include "SMSNotification.h"
#include "AlarmNotification.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// String'i lowercase'e çeviren yardımcı fonksiyon (C++98 uyumlu)
static std::string toLowerCase(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] = tolower(static_cast<unsigned char>(result[i]));
    }
    return result;
}

// LLR19, LLR36: Bildirim tipine göre Notification oluşturur
Notification* NotificationFactory::createNotification(const std::string& type) {
    // Tip kontrolü için lowercase'e çevir
    std::string lowerType = toLowerCase(type);
    
    // Console notification
    if (lowerType == "console") {
        std::cout << "[NotificationFactory] Creating Console notification" 
                  << std::endl;
        return new ConsoleNotification();
    }
    
    // SMS notification (simülasyon)
    if (lowerType == "sms") {
        std::cout << "[NotificationFactory] Creating SMS notification (simulated)" 
                  << std::endl;
        return new SMSNotification();
    }
    
    // Alarm notification (simülasyon)
    if (lowerType == "alarm") {
        std::cout << "[NotificationFactory] Creating Alarm notification (simulated)" 
                  << std::endl;
        return new AlarmNotification();
    }
    
    // Bilinmeyen tip
    std::cerr << "[NotificationFactory] ERROR: Unknown notification type: " 
              << type << std::endl;
    std::cerr << "[NotificationFactory] Supported types: console, sms, alarm" 
              << std::endl;
    
    return NULL;
}