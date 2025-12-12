// YAMLLogFormatter.h
// Developer G - Kübra Akpınar
// LLR8: YAML formatında log oluşturur
// Pattern: Concrete implementation of LogFormatter

#ifndef YAMLLOGFORMATTER_H
#define YAMLLOGFORMATTER_H

#include "LogFormatter.h"
#include <string>

/**
 * @class YAMLLogFormatter
 * @brief YAML formatında log satırı oluşturur
 * 
 * LLR8: YAML format desteği
 * 
 * Çıktı formatı:
 * ---
 * timestamp: "2025-12-12 14:30:00"
 * action: "PowerOn"
 * deviceId: 5
 * 
 * Avantajları:
 * - İnsan tarafından okunması kolay
 * - Konfigürasyon dosyaları için ideal
 * - Minimal syntax
 */
class YAMLLogFormatter : public LogFormatter {
public:
    /**
     * @brief Constructor
     */
    YAMLLogFormatter();
    
    /**
     * @brief Destructor
     */
    virtual ~YAMLLogFormatter();
    
    /**
     * @brief Log mesajını YAML formatında oluşturur
     * @param timestamp Zaman damgası
     * @param action Yapılan işlem
     * @param deviceId Hedef cihaz ID
     * @return std::string YAML formatında log satırı
     * 
     * Örnek çıktı:
     * ---
     * timestamp: "2025-12-12 14:30:00"
     * action: "AddDevice"
     * deviceId: 10
     */
    virtual std::string format(const std::string& timestamp,
                              const std::string& action,
                              int deviceId);
    
    /**
     * @brief Format tipini döndürür
     * @return std::string "YAML"
     */
    virtual std::string getFormatType() const;

private:
    /**
     * @brief String'i YAML için quote'lar (gerekirse)
     * @param str Quote'lanacak string
     * @return std::string Quote'lanmış string
     */
    std::string quoteIfNeeded(const std::string& str) const;
    
    /**
     * @brief Integer'ı string'e çevirir (C++98 uyumlu)
     * @param value Integer değer
     * @return std::string String değer
     */
    std::string intToString(int value) const;
};

#endif // YAMLLOGFORMATTER_H