#include <iostream>
#include <limits>

#include "Logger.h"
#include "NotificationManager.h"

// Güvenli int okuma (harf vs girilirse temizler)
int readIntSafe(const std::string& prompt) {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) {
            return x;
        }
        // Hatalı giriş (harf vb.) -> temizle ve tekrar sor
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Gecersiz giris. Lutfen sayi giriniz.\n";
    }
}

// Kullanıcıdan log formatını sor (LLR8)
LogFormat askLogFormat() {
    std::cout << "Log formatini seciniz:\n"
              << " 1) JSON\n"
              << " 2) XML\n"
              << " 3) YAML\n";

    int choice = readIntSafe("Secim: ");

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
              << " 3) Alarm Sound\n";

    int choice = readIntSafe("Secim: ");

    switch (choice) {
    case 2: return NotificationType::SMS;
    case 3: return NotificationType::ALARM_SOUND;
    case 1:
    default:
        return NotificationType::CONSOLE;
    }
}

int main() {
    // --- LLR8 & LLR6: log formatini sec ve dosyayi ac ---
    LogFormat format = askLogFormat();
    Logger::instance().initialize("msh_log.txt", format);

    // Logger dosyayı açamadıysa (sende sessiz dönüyor), kullanıcıya uyarı verelim
    // (Logger.h içinde currentFormat var; ama açık mı kontrolü yok. Basit uyarı yeter.)
    std::cout << "Log dosyasi: msh_log.txt (acilamadiysa log yazilmayabilir)\n";

    // --- LLR36: kullanicidan bildirim tercihi al ---
    NotificationManager notifManager;
    notifManager.setPreference(askNotificationPreference());

    // --- LLR30: örnek başarılı işlemler loglansın ---
    Logger::instance().log(LogLevel::INFO, "TurnOnLight OK", 101, "TurnOnLight");
    Logger::instance().log(LogLevel::INFO, "OpenDoor OK",     202, "OpenDoor");

    // --- Örnek başarısız işlem ---
    // Not: NotificationManager notifyFailure içinde de log atıyor,
    // ama main'deki bu ERROR log'u "başarısız işlem örneği" olarak kalsın.
    Logger::instance().log(LogLevel::ERROR, "StartHeater FAILED", 303, "StartHeater");

    // --- LLR19: cihaz arizasi bildirimi (user preference'a gore) ---
    std::cout << "\nSimulating device failure on device 303...\n";
    notifManager.notifyFailure(303, "Overheating detected");

    // --- LLR7: program kapanirken log dosyasini kapat ---
    Logger::instance().shutdown();

    std::cout << "\nProgram bitti. Loglar msh_log.txt dosyasina yazildi.\n";
    return 0;
}
