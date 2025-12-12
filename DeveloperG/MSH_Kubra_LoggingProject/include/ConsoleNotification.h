// ConsoleNotification.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Konsola bildirim yazdırma
// Pattern: Concrete implementation of Notification

#ifndef CONSOLENOTIFICATION_H
#define CONSOLENOTIFICATION_H

#include "Notification.h"
#include <string>

/**
 * @class ConsoleNotification
 * @brief Konsola bildirim yazdırır (gerçek bildirim)
 * 
 * LLR19, LLR36: Console bildirim tipi
 * 
 * Kullanım senaryosu:
 * - Kullanıcı "Console" bildirim tercihini seçer
 * - Cihaz arızası veya olay gerçekleştiğinde konsola yazdırılır
 * 
 * Çıktı formatı:
 * [CONSOLE NOTIFICATION] Light 2 failure
 * [CONSOLE NOTIFICATION] Camera detected motion
 */
class ConsoleNotification : public Notification {
public:
    /**
     * @brief Constructor
     */
    ConsoleNotification();
    
    /**
     * @brief Destructor
     */
    virtual ~ConsoleNotification();
    
    /**
     * @brief Konsola bildirim yazdırır
     * @param message Bildirim mesajı
     * 
     * Örnek çıktı:
     * [CONSOLE NOTIFICATION] Device failure detected
     */
    virtual void send(const std::string& message);
    
    /**
     * @brief Bildirim tipini döndürür
     * @return std::string "Console"
     */
    virtual std::string getType() const;
};

#endif // CONSOLENOTIFICATION_H