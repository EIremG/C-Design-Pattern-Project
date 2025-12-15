// NotificationFactory.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Factory Method Pattern - Notification üretimi
// Pattern: Factory Method + Strategy Pattern birlikte

#include "log/NotificationFactory.h"
#include "log/ConsoleNotification.h"
#include "log/SMSNotification.h"
#include "log/AlarmNotification.h"
#include "log/EmailNotification.h"
#include <iostream>
#include <cctype>

// String'i lowercase'e çeviren yardımcı fonksiyon (C++98 uyumlu)
static std::string toLowerCase(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        // C4244 fix: tolower(int) -> char'a güvenli cast
        unsigned char ch = static_cast<unsigned char>(result[i]);
        result[i] = static_cast<char>(tolower(ch));
    }
    return result;
}

// LLR19, LLR36: Bildirim tipine göre Notification Strategy oluşturur
Notification* NotificationFactory::createNotification(const std::string& type) {
    std::string lowerType = toLowerCase(type);

    if (lowerType == "console") {
        std::cout << "[NotificationFactory] Creating Console notification strategy" << std::endl;
        return new ConsoleNotification();
    }

    if (lowerType == "sms") {
        std::cout << "[NotificationFactory] Creating SMS notification strategy (simulated)" << std::endl;
        return new SMSNotification();
    }

    if (lowerType == "email") {
        std::cout << "[NotificationFactory] Creating Email notification strategy (simulated)" << std::endl;
        return new EmailNotification();
    }

    if (lowerType == "alarm") {
        std::cout << "[NotificationFactory] Creating Alarm notification strategy (simulated)" << std::endl;
        return new AlarmNotification();
    }

    std::cerr << "[NotificationFactory] ERROR: Unknown notification type: " << type << std::endl;
    std::cerr << "[NotificationFactory] Supported types: console, sms, email, alarm" << std::endl;
    return NULL;
}
