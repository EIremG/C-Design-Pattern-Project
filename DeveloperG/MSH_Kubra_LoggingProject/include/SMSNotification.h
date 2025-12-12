// SMSNotification.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: SMS bildirimi (simülasyon)
// Pattern: Concrete implementation of Notification

#ifndef SMSNOTIFICATION_H
#define SMSNOTIFICATION_H

#include "Notification.h"
#include <string>

/**
 * @class SMSNotification
 * @brief SMS gönderimini simüle eder
 * 
 * LLR19: "A SMS is sent" şeklinde simülasyon mesajı
 * LLR36: SMS bildirim tipi
 * 
 * Kullanım senaryosu:
 * - Kullanıcı "SMS" bildirim tercihini seçer
 * - Cihaz arızası veya olay gerçekleştiğinde SMS simülasyonu yapılır
 * - Gerçek SMS gönderilmez, sadece konsola mesaj yazılır
 * 
 * Çıktı formatı (LLR19'da belirtildiği gibi):
 * A SMS is sent: Light 2 failure
 * A SMS is sent: Camera detected motion
 */
class SMSNotification : public Notification {
public:
    /**
     * @brief Constructor
     */
    SMSNotification();
    
    /**
     * @brief Destructor
     */
    virtual ~SMSNotification();
    
    /**
     * @brief SMS gönderimini simüle eder
     * @param message SMS içeriği
     * 
     * LLR19 gereği çıktı formatı:
     * "A SMS is sent: [message]"
     * 
     * Örnek:
     * A SMS is sent: Light 2 failure
     */
    virtual void send(const std::string& message);
    
    /**
     * @brief Bildirim tipini döndürür
     * @return std::string "SMS"
     */
    virtual std::string getType() const;
};

#endif // SMSNOTIFICATION_H