#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include "Types.h"

// Logging altyapısını sağlayan Singleton Logger sınıfı
class Logger {
public:
    // Tek örneğe erişim
    static Logger& instance();

    // LLR6: Log sistemini başlatır ve kullanılacak formatı belirler
    // Örnek: Logger::instance().initialize("msh_log.txt", LogFormat::JSON);
    void initialize(const std::string& filename, LogFormat format);

    // LLR30: Her işlem için log satırı yazar
    // deviceId ve actionType bilinmiyorsa sırasıyla -1 ve "" kullanılabilir
    void log(LogLevel level,
             const std::string& message,
             int deviceId = -1,
             const std::string& actionType = "");

    // LLR7: Program kapanırken log dosyasını düzgün şekilde kapatır
    void shutdown();

    // Geçerli log formatını döndürür
    LogFormat currentFormat() const { return m_format; }

private:
    Logger();
    ~Logger();

    // Kopyalamayı engelle
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Yardımcı fonksiyonlar
    std::string formatTime(std::time_t t) const;
    std::string levelToString(LogLevel level) const;
    std::string formatLogLine(LogLevel level,
                              const std::string& message,
                              int deviceId,
                              const std::string& actionType) const;

private:
    std::ofstream m_file;
    bool         m_isOpen{false};
    LogFormat    m_format{LogFormat::JSON}; // Varsayılan log formatı
};

#endif // LOGGER_H
