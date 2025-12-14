// Notification.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Bildirim sistemi için abstract base class
// Pattern: Abstract Base Class (Factory Method için temel)

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

/**
 * @class Notification
 * @brief Bildirim göndermek için abstract base class (Strategy Pattern)
 * 
 * LLR19: Arıza algılandığında kullanıcıya seçilen bildirim 
 *        türüne göre mesaj yazılır (Console: "A SMS is sent")
 * LLR36: Kullanıcı bildirim tercihini uygulama başında seçebilir
 *        (Console/SMS/Email/Alarm mesajı - simülasyon)
 * 
 * Design Pattern: Strategy Pattern
 * - Bu sınıf Strategy interface'i olarak çalışır
 * - Her türev sınıf (Console/SMS/Email/Alarm) farklı bir concrete strategy'dir
 * - NotificationManager (Context) runtime'da strategy'yi değiştirebilir
 * 
 * SOLID - Open/Closed Principle: Yeni bildirim türü eklemek için
 * mevcut kodu değiştirmeden yeni türev sınıf oluşturulur
 * 
 * Desteklenen bildirim strategy'leri:
 * - ConsoleNotification: Konsola yazdırma (gerçek)
 * - SMSNotification: SMS gönderme (simülasyon)
 * - EmailNotification: Email gönderme (simülasyon)
 * - AlarmNotification: Alarm tetikleme (simülasyon)
 */
class Notification {
public:
    /**
     * @brief Virtual destructor - türev sınıflar için
     */
    virtual ~Notification() {}
    
    /**
     * @brief Bildirim gönderme (pure virtual)
     * @param message Gönderilecek mesaj
     * 
     * Her türev sınıf kendi bildirim mantığını implement eder:
     * - ConsoleNotification: std::cout << "..." 
     * - SMSNotification: std::cout << "A SMS is sent: ..."
     * - AlarmNotification: std::cout << "ALARM TRIGGERED: ..."
     */
    virtual void send(const std::string& message) = 0;
    
    /**
     * @brief Bildirim tipini döndürür (opsiyonel)
     * @return std::string Bildirim tipi adı
     */
    virtual std::string getType() const = 0;
};

#endif 