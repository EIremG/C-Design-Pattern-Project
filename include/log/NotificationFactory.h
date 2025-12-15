// NotificationFactory.h
// Developer G - Kübra Akpınar
// LLR19, LLR36: Bildirim seçimi için Factory Method Pattern
// Pattern: Factory Method - if/else kullanmadan notification oluşturur

#ifndef NOTIFICATIONFACTORY_H
#define NOTIFICATIONFACTORY_H

#include <string>
#include "log/Notification.h"

/**
 * @class NotificationFactory
 * @brief Notification nesnelerini üreten factory
 * 
 * LLR19: Arıza algılandığında seçilen bildirim türüne göre mesaj
 * LLR36: Kullanıcı bildirim tercihini uygulama başında seçer
 * 
 * SOLID Prensipleri:
 * - Single Responsibility: Sadece notification üretiminden sorumlu
 * - Open/Closed: Yeni bildirim türü eklemek için factory'yi 
 *   değiştiririz ama NotificationManager'ı değiştirmeyiz
 * - Dependency Inversion: NotificationManager concrete class 
 *   yerine Notification abstract'ına bağımlı
 * 
 * Factory Method Pattern kullanımı:
 * - if/else switch/case yerine factory kullanarak 
 *   nesne üretimi merkezileştirilir
 * - Yeni bildirim türü eklemek kolaydır
 * - Test edilebilirlik artar
 */
class NotificationFactory {
public:
    /**
     * @brief Bildirim tipine göre Notification oluşturur
     * @param type Bildirim tipi ("console", "sms", "alarm")
     * @return Notification* Oluşturulan notification (NULL değilse)
     * 
     * Kullanım:
     * Notification* notif = NotificationFactory::createNotification("sms");
     * NotificationManager mgr;
     * mgr.setNotificationMethod(notif);
     * mgr.notify("Light 2 failure");
     * 
     * Desteklenen tipler:
     * - "console" veya "CONSOLE" -> ConsoleNotification
     * - "sms" veya "SMS" -> SMSNotification
     * - "alarm" veya "ALARM" -> AlarmNotification
     * - Bilinmeyen tip -> NULL döner
     * 
     * NOT: LLR19 gereği "A SMS is sent" şeklinde simülasyon mesajı
     * konsola yazılır, gerçek SMS gönderilmez
     */
    static Notification* createNotification(const std::string& type);
};

#endif 