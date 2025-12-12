// XMLLogFormatter.h
// Developer G - Kübra Akpınar
// LLR8: XML formatında log oluşturur
// Pattern: Concrete implementation of LogFormatter

#ifndef XMLLOGFORMATTER_H
#define XMLLOGFORMATTER_H

#include "LogFormatter.h"
#include <string>

/**
 * @class XMLLogFormatter
 * @brief XML formatında log satırı oluşturur
 * 
 * LLR8: XML format desteği
 * 
 * Çıktı formatı:
 * <log>
 *   <timestamp>2025-12-12 14:30:00</timestamp>
 *   <action>PowerOn</action>
 *   <deviceId>5</deviceId>
 * </log>
 * 
 * Avantajları:
 * - Standart XML parser'larla kolayca işlenebilir
 * - Hiyerarşik veri yapısı
 * - Enterprise sistemlerle uyumlu
 */
class XMLLogFormatter : public LogFormatter {
public:
    /**
     * @brief Constructor
     */
    XMLLogFormatter();
    
    /**
     * @brief Destructor
     */
    virtual ~XMLLogFormatter();
    
    /**
     * @brief Log mesajını XML formatında oluşturur
     * @param timestamp Zaman damgası
     * @param action Yapılan işlem
     * @param deviceId Hedef cihaz ID
     * @return std::string XML formatında log satırı
     * 
     * Örnek çıktı:
     * <log><timestamp>2025-12-12 14:30:00</timestamp><action>AddDevice</action><deviceId>10</deviceId></log>
     */
    virtual std::string format(const std::string& timestamp,
                              const std::string& action,
                              int deviceId);
    
    /**
     * @brief Format tipini döndürür
     * @return std::string "XML"
     */
    virtual std::string getFormatType() const;

private:
    /**
     * @brief String'i XML için escape eder (<, >, &, vb.)
     * @param str Escape edilecek string
     * @return std::string Escape edilmiş string
     */
    std::string escapeXml(const std::string& str) const;
};

#endif // XMLLOGFORMATTER_H