#include <iostream>
#include <limits>
#include <fstream>

#include "Logger.h"
#include "NotificationManager.h"

// Kullanıcıdan log formatını sor (LLR8)
LogFormat askLogFormat() {
    std::cout << "Log formatini seciniz:\n"
              << " 1) JSON\n"
              << " 2) XML\n"
              << " 3) YAML\n"
              << "Secim: ";

    int choice;
    if (!(std::cin >> choice)) {
        // Harf vb. girilirse temizle
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return LogFormat::JSON; // default
    }

    switch (choice) {
    case 2: return LogFormat::XML;
    case 3: return LogFormat::YAML;
    case 1:
    default:
        return LogFormat::JSON;
    }
}

// Kullanıcıdan bildirim tercihini sor (LLR36)
NotificationType askNotificationPreference() {
    std::cout << "\nBildirim tercihini seciniz:\n"
              << " 1) Console\n"
              << " 2) SMS\n"
              << " 3) Alarm Sound\n"
              << "Secim: ";

    int choice;
    if (!(std::cin >> choice)) {
        // Harf vb. girilirse temizle
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return NotificationType::CONSOLE; // default
    }

    switch (choice) {
    case 2: return NotificationType::SMS;
    case 3: return NotificationType::ALARM_SOUND;
    case 1:
    default:
        return NotificationType::CONSOLE;
    }
}

int main() {
    const std::string logFileName = "msh_log.txt";

    // --- LLR8 & LLR6: log formatini sec ve dosyayi ac ---
    LogFormat format = askLogFormat();
    Logger::instance().initialize(logFileName, format);

    // initialize() void olduğu için direkt başarı kontrolü yok.
    // En azından dosya erişimi yoksa kullanıcıya uyarı verelim:
    {
        std::ofstream testOpen(logFileName, std::ios::app);
        if (!testOpen.is_open()) {
            std::cerr << "[UYARI] Log dosyasi acilamadi: " << logFileName
                      << " (Loglar yazilamayabilir!)" << std::endl;
        }
    }

    // --- LLR36: kullanicidan bildirim tercihi al ---
    NotificationManager notifManager;
    notifManager.setPreference(askNotificationPreference());

    // --- LLR30: örnek başarılı işlemler loglansın ---
    Logger::instance().log(LogLevel::INFO, "TurnOnLight OK", 101, "TurnOnLight");
    Logger::instance().log(LogLevel::INFO, "OpenDoor OK", 202, "OpenDoor");

    // --- Örnek başarısız işlem (double log değil; bu ayrı bir başarısız işlem örneği) ---
    Logger::instance().log(LogLevel::ERROR, "StartHeater FAILED", 303, "StartHeater");

    // --- LLR19: cihaz arizasi bildirimi (user preference'a gore) ---
    std::cout << "\nSimulating device failure on device 303...\n";
    notifManager.notifyFailure(303, "Overheating detected");

    // --- LLR7: program kapanirken log dosyasini kapat ---
    Logger::instance().shutdown();

    std::cout << "\nProgram bitti. Loglar " << logFileName << " dosyasina yazildi.\n";
    return 0;
}
