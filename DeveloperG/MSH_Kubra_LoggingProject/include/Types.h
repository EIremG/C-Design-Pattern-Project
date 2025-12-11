#ifndef TYPES_H
#define TYPES_H

// Log seviyeleri (LLR30 için optional ama kullanışlı)
enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

// Log formatları (LLR8) - hocanın dokümanına göre
// JSON / XML / YAML
enum class LogFormat {
    JSON,
    XML,
    YAML
};

// Bildirim türleri (LLR19, LLR36)
// Doküman: log message, alarm, SMS
enum class NotificationType {
    CONSOLE,
    SMS,
    ALARM_SOUND
};

#endif



