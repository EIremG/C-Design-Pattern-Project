// EmailNotification.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Email bildirimi (simülasyon) - Strategy Pattern
// Pattern: Strategy (Concrete Strategy)

#ifndef EMAILNOTIFICATION_H
#define EMAILNOTIFICATION_H

#include "log/Notification.h"
#include <string>

/**
 * @class EmailNotification
 * @brief Email gönderimini simüle eder (Strategy Pattern)
 * 
 * LLR19: "An Email is sent" şeklinde simülasyon mesajı
 * LLR36: Email bildirim tipi
 * 
 * Kullanım senaryosu:
 * - Kullanıcı "Email" bildirim tercihini seçer
 * - Cihaz arızası veya olay gerçekleştiğinde Email simülasyonu yapılır
 * - Gerçek Email gönderilmez, sadece konsola mesaj yazılır
 * 
 * Strategy Pattern:
 * - Notification interface'ini implement eder
 * - NotificationManager tarafından runtime'da seçilebilir
 * - Diğer strategy'lerle (SMS, Console, Alarm) değiştirilebilir
 * 
 * Çıktı formatı:
 * An Email is sent to: user@example.com
 * Subject: MSH Alert
 * Message: Light 2 failure
 */
class EmailNotification : public Notification {
private:
    std::string emailAddress;  // Simülasyon için email adresi
    
public:
    /**
     * @brief Constructor - varsayılan email adresi
     */
    EmailNotification();
    
    /**
     * @brief Constructor - özel email adresi ile
     * @param email Hedef email adresi
     */
    EmailNotification(const std::string& email);
    
    /**
     * @brief Destructor
     */
    virtual ~EmailNotification();
    
    /**
     * @brief Email gönderimini simüle eder (Strategy Pattern)
     * @param message Email içeriği
     * 
     * LLR19 gereği çıktı formatı:
     * "An Email is sent to: [address]"
     * "Subject: MSH Alert"
     * "Message: [message]"
     * 
     * Örnek:
     * An Email is sent to: user@example.com
     * Subject: MSH Alert - Device Failure
     * Message: Light 2 failure
     */
    virtual void send(const std::string& message);
    
    /**
     * @brief Bildirim tipini döndürür
     * @return std::string "Email"
     */
    virtual std::string getType() const;
    
    /**
     * @brief Email adresini ayarla
     * @param email Yeni email adresi
     */
    void setEmailAddress(const std::string& email);
    
    /**
     * @brief Email adresini al
     * @return std::string Mevcut email adresi
     */
    std::string getEmailAddress() const;
};

#endif 