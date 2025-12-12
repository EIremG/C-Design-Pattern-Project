// JSONLogFormatter.h
// Developer G - Kübra Akpınar
// LLR8: JSON formatında log oluşturur
// Pattern: Concrete implementation of LogFormatter

#ifndef JSONLOGFORMATTER_H
#define JSONLOGFORMATTER_H

#include "LogFormatter.h"
#include <string>

/**
 * @class JSONLogFormatter
 * @brief JSON formatında log satırı oluşturur
 * 
 * LLR8: JSON format desteği
 * 
 * Çıktı formatı:
 * {"timestamp":"2025-12-12 14:30:00","action":"PowerOn","deviceId":5}
 * 
 * Avantajları:
 * - Makine tarafından kolayca parse edilebilir
 * - Modern sistemlerle uyumlu
 * - Programatik işlemler için ideal
 */
class JSONLogFormatter : public LogFormatter {
public:
    /**
     * @brief Constructor
     */
    JSONLogFormatter();
    
    /**
     * @brief Destructor
     */
    virtual ~JSONLogFormatter();
    
    /**
     * @brief Log mesajını JSON formatında oluşturur
     * @param timestamp Zaman damgası
     * @param action Yapılan işlem
     * @param deviceId Hedef cihaz ID
     * @return std::string JSON formatında log satırı
     * 
     * Örnek çıktı:
     * {"timestamp":"2025-12-12 14:30:00","action":"AddDevice","deviceId":10}
     */
    virtual std::string format(const std::string& timestamp,
                              const std::string& action,
                              int deviceId);
    
    /**
     * @brief Format tipini döndürür
     * @return std::string "JSON"
     */
    virtual std::string getFormatType() const;

private:
    /**
     * @brief String'i JSON için escape eder (", \, vb.)
     * @param str Escape edilecek string
     * @return std::string Escape edilmiş string
     */
    std::string escapeJson(const std::string& str) const;
};

#endif // JSONLOGFORMATTER_H