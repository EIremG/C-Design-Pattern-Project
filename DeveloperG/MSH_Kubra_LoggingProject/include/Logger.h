// Logger.h
// Developer G - Kübra Akpınar
// LLR6, LLR7, LLR30: Log dosyası yönetimi ve işlem loglama
// Pattern: Singleton - Tek bir Logger instance garantisi

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

// Forward declaration - LogFormatter bağımlılığı
class LogFormatter;

/**
 * @class Logger
 * @brief Singleton pattern ile log yönetimi sağlar
 * 
 * LLR6: Sistem başlatıldığında log dosyası oluşturulur
 * LLR7: Kapanışta log dosyası düzgün kapatılır
 * LLR30: Her başarılı işlem loglanır (timestamp, işlem, device id)
 */
class Logger {
private:
    static Logger* instance;           // Singleton instance
    LogFormatter* formatter;           // Kullanılan format stratejisi
    std::ofstream logFile;            // Log dosyası stream
    std::string filename;             // Log dosya adı
    bool isInitialized;               // Başlatılma durumu
    
    // Private constructor - Singleton için
    Logger();
    
    // Copy constructor ve assignment operator'ü engelle
    Logger(const Logger&);
    Logger& operator=(const Logger&);
    
    // Timestamp oluşturma yardımcı fonksiyonu
    std::string getCurrentTimestamp() const;
    
public:
    /**
     * @brief Singleton instance'ı döndürür
     * @return Logger* Tek Logger instance
     */
    static Logger* getInstance();
    
    /**
     * @brief Logger'ı başlatır ve dosya açar (LLR6)
     * @param filename Log dosya adı
     * @param fmt LogFormatter stratejisi (JSON/XML/YAML)
     * @return bool Başarılı ise true
     */
    bool initialize(const std::string& filename, LogFormatter* fmt);
    
    /**
     * @brief Genel log mesajı yazar
     * @param message Log mesajı
     */
    void log(const std::string& message);
    
    /**
     * @brief İşlem loglar (LLR30)
     * @param timestamp Zaman damgası
     * @param action Yapılan işlem
     * @param deviceId Hedef cihaz ID
     */
    void logAction(const std::string& timestamp, 
                   const std::string& action, 
                   int deviceId);
    
    /**
     * @brief Log dosyasını kapatır (LLR7)
     */
    void close();
    
    /**
     * @brief Logger başlatılmış mı kontrolü
     * @return bool Başlatılmışsa true
     */
    bool isReady() const;
    
    /**
     * @brief Destructor - kaynakları temizler
     */
    ~Logger();
};

#endif // LOGGER_H