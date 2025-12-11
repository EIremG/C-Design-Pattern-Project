#include "NotificationManager.h"
#include "Logger.h"

#include <iostream>

void NotificationManager::setPreference(NotificationType type) {
    m_type = type;
}

NotificationType NotificationManager::getPreference() const {
    return m_type;
}

void NotificationManager::notifyFailure(int deviceId, const std::string& reason) const {
    std::string channel;     // console / sms / alarm
    std::string outputText;  // ekrana basılacak mesaj

    switch (m_type) {
    case NotificationType::CONSOLE:
        channel = "console";
        outputText = "[CONSOLE] Device " + std::to_string(deviceId) +
                     " FAILED: " + reason;
        break;

    case NotificationType::SMS:
        channel = "sms";
        outputText = "[SMS] (simulated) Device " + std::to_string(deviceId) +
                     " FAILED: " + reason;
        break;

    case NotificationType::ALARM_SOUND:
        channel = "alarm";
        outputText = "[ALARM] Device " + std::to_string(deviceId) +
                     " FAILED: " + reason + " >>> ALARM SOUND <<<";
        break;

    default:
        channel = "unknown";
        outputText = "[NOTIFY] Unknown notification type!";
        Logger::instance().log(LogLevel::WARNING,
                               "Unknown notification type while notifying failure",
                               deviceId,
                               "FAILURE");
        std::cout << outputText << std::endl;
        return;
    }

    // Ortak kısım (TEK YER)
    std::cout << outputText << std::endl;

    Logger::instance().log(LogLevel::ERROR,
                           "Device failure (" + channel + "): " + reason,
                           deviceId,
                           "FAILURE");
}
