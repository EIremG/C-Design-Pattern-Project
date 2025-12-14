// NotificationManager.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Bildirim tercihlerini yönetir ve bildirim gönderir
// Pattern: Strategy Pattern (Context)

#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <string>
#include "Notification.h"

class NotificationManager {
private:
    Notification* currentNotification;  // Şu an kullanılan bildirim türü
    std::string currentType;            // Bildirim tipi adı ("console", "sms", ...)

public:
    /**
     * @brief Constructor - başlangıçta default strategy kurmaz.
     * Kullanıcı setNotificationMethod ile seçer (LLR36).
     */
    NotificationManager();

    /**
     * @brief Bildirim yöntemini ayarlar (LLR36)
     * @param type Bildirim tipi ("console", "sms", "email", "alarm")
     * @return bool Başarılı ise true
     */
    bool setNotificationMethod(const std::string& type);

    /**
     * @brief Notification nesnesini direkt ayarlar (Factory ile)
     * @param notification Kullanılacak Notification nesnesi
     */
    void setNotification(Notification* notification);

    /**
     * @brief Bildirim gönderir (LLR19)
     * Eğer method seçilmemişse console'a fallback yapar.
     */
    void notify(const std::string& message);

    /**
     * @brief Şu anki bildirim tipini döndürür
     */
    std::string getCurrentType() const;

    ~NotificationManager();
};

#endif
