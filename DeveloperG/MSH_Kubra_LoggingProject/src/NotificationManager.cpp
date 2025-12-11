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
    std::string channel;
    std::string outputText;
    LogLevel logLevel = LogLevel::ERROR;

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
        logLevel = LogLevel::WARNING;
        break;
    }

    // Ortak çıktı
    std::cout << outputText << std::endl;

    Logger::instance().log(logLevel,
                           "Device failure (" + channel + "): " + reason,
                           deviceId,
                           "FAILURE");
}
