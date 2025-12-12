// NotificationManager.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Bildirim tercihlerini yönetir ve bildirim gönderir
// Pattern: Manager class - Notification strategy'lerini yönetir

#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <string>
#include "Notification.h"

/**
 * @class NotificationManager
 * @brief Bildirim sistemini yönetir
 * 
 * LLR19: Arıza algılandığında kullanıcıya seçilen bildirim 
 *        türüne göre mesaj yazılır
 * LLR36: Kullanıcı bildirim tercihini uygulama başında seçebilir
 * 
 * Sorumluluklar:
 * - Kullanıcının bildirim tercihini saklar
 * - Bildirim gönderme işlemini yönetir
 * - Factory ile oluşturulan notification'ları kullanır
 * 
 * SOLID - Dependency Inversion:
 * - Concrete notification sınıflarına değil, 
 *   Notification abstract class'ına bağımlı
 */
class NotificationManager {
private:
    Notification* currentNotification;  // Şu an kullanılan bildirim türü
    std::string currentType;            // Bildirim tipi adı
    
public:
    /**
     * @brief Constructor - varsayılan bildirim Console
     */
    NotificationManager();
    
    /**
     * @brief Bildirim yöntemini ayarlar (LLR36)
     * @param type Bildirim tipi ("console", "sms", "alarm")
     * @return bool Başarılı ise true
     * 
     * Kullanım:
     * NotificationManager mgr;
     * mgr.setNotificationMethod("sms");
     * mgr.notify("Device failure");
     * // Çıktı: A SMS is sent: Device failure
     */
    bool setNotificationMethod(const std::string& type);
    
    /**
     * @brief Notification nesnesini direkt ayarlar (Factory ile)
     * @param notification Kullanılacak Notification nesnesi
     * 
     * Kullanım:
     * Notification* notif = NotificationFactory::createNotification("sms");
     * mgr.setNotification(notif);
     */
    void setNotification(Notification* notification);
    
    /**
     * @brief Bildirim gönderir (LLR19)
     * @param message Gönderilecek mesaj
     * 
     * Örnek:
     * mgr.notify("Light 2 failure");
     * // SMS seçiliyse: A SMS is sent: Light 2 failure
     * // Console seçiliyse: [CONSOLE NOTIFICATION] Light 2 failure
     * // Alarm seçiliyse:   ALARM TRIGGERED: Light 2 failure
     */
    void notify(const std::string& message);
    
    /**
     * @brief Şu anki bildirim tipini döndürür
     * @return std::string Bildirim tipi
     */
    std::string getCurrentType() const;
    
    /**
     * @brief Destructor - kaynakları temizler
     */
    ~NotificationManager();
};

#endif // NOTIFICATIONMANAGER_H