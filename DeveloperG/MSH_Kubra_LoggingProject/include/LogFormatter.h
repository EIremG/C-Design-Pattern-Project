// LogFormatter.h
// Developer G - Kübra Akpınar
// LLR8: Log formatı seçimi için abstract base class
// Pattern: Abstract Base Class (Factory Method için temel)

#ifndef LOGFORMATTER_H
#define LOGFORMATTER_H

#include <string>

/**
 * @class LogFormatter
 * @brief Log formatlamak için abstract base class
 * 
 * LLR8: JSON/XML/YAML formatlarını destekler
 * SOLID - Open/Closed Principle: Yeni format eklemek için 
 * mevcut kodu değiştirmeden yeni türev sınıf oluşturulur
 */
class LogFormatter {
public:
    /**
     * @brief Virtual destructor - türev sınıflar için
     */
    virtual ~LogFormatter() {}
    
    /**
     * @brief Log mesajını formatlama (pure virtual)
     * @param timestamp Zaman damgası
     * @param action Yapılan işlem
     * @param deviceId Hedef cihaz ID
     * @return std::string Formatlanmış log satırı
     * 
     * Her türev sınıf kendi format mantığını implement eder:
     * - JSONLogFormatter: {"timestamp":"...", "action":"...", "device":...}
     * - XMLLogFormatter: <log><timestamp>...</timestamp>...</log>
     * - YAMLLogFormatter: timestamp: ...\naction: ...\ndevice: ...
     */
    virtual std::string format(const std::string& timestamp,
                              const std::string& action,
                              int deviceId) = 0;
    
    /**
     * @brief Format tipini döndürür (opsiyonel)
     * @return std::string Format adı
     */
    virtual std::string getFormatType() const = 0;
};

#endif // LOGFORMATTER_H
