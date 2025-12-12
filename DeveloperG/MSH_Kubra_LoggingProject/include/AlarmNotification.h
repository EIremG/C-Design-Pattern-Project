// AlarmNotification.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Alarm bildirimi (simülasyon)
// Pattern: Concrete implementation of Notification

#ifndef ALARMNOTIFICATION_H
#define ALARMNOTIFICATION_H

#include "Notification.h"
#include <string>

/**
 * @class AlarmNotification
 * @brief Alarm tetiklenmesini simüle eder
 * 
 * LLR19: Arıza durumunda alarm mesajı
 * LLR36: Alarm bildirim tipi
 * 
 * Kullanım senaryosu:
 * - Kullanıcı "Alarm" bildirim tercihini seçer
 * - Cihaz arızası veya kritik olay gerçekleştiğinde alarm tetiklenir
 * - Gerçek alarm sesi çalmaz, sadece konsola mesaj yazılır
 * 
 * Çıktı formatı:
 *   ALARM TRIGGERED: Light 2 failure
 *   ALARM TRIGGERED: Smoke detected
 */
class AlarmNotification : public Notification {
public:
    /**
     * @brief Constructor
     */
    AlarmNotification();
    
    /**
     * @brief Destructor
     */
    virtual ~AlarmNotification();
    
    /**
     * @brief Alarm tetiklenmesini simüle eder
     * @param message Alarm mesajı
     * 
     * Örnek çıktı:
     *   ALARM TRIGGERED: Device failure detected
     *   ALARM TRIGGERED: Motion detected by camera
     */
    virtual void send(const std::string& message);
    
    /**
     * @brief Bildirim tipini döndürür
     * @return std::string "Alarm"
     */
    virtual std::string getType() const;
};

#endif // ALARMNOTIFICATION_H