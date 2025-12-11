#ifndef NOTIFICATION_MANAGER_H
#define NOTIFICATION_MANAGER_H

#include <string>
#include "Types.h"

// LLR19 & LLR36: Kullanıcı bildirim tercihine göre arıza bildirimi
class NotificationManager {
public:
    // Bildirim tercihinin ayarlanması (LLR36)
    void setPreference(NotificationType type);
    NotificationType getPreference() const;

    // LLR19: Cihaz arızasını kullanıcıya bildir
    void notifyFailure(int deviceId, const std::string& reason) const;

private:
    // Varsayılan bildirim türü
    NotificationType m_type{NotificationType::CONSOLE};
};

#endif // NOTIFICATION_MANAGER_H
