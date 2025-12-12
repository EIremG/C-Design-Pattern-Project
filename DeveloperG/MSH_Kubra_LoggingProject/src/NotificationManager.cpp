// NotificationManager.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Bildirim yönetimi implementasyonu

#include "NotificationManager.h"
#include "NotificationFactory.h"
#include <iostream>

// Constructor - varsayılan olarak Console bildirim
NotificationManager::NotificationManager() : currentNotification(NULL) {
    // Varsayılan bildirim tipi: Console
    setNotificationMethod("console");
}

// LLR36: Bildirim yöntemini ayarlar
bool NotificationManager::setNotificationMethod(const std::string& type) {
    // Eski notification'ı temizle
    if (currentNotification != NULL) {
        delete currentNotification;
        currentNotification = NULL;
    }
    
    // Factory ile yeni notification oluştur
    currentNotification = NotificationFactory::createNotification(type);
    
    if (currentNotification == NULL) {
        std::cerr << "[NotificationManager] Failed to create notification type: " 
                  << type << std::endl;
        
        // Fallback: Console'a dön
        currentNotification = NotificationFactory::createNotification("console");
        currentType = "console";
        
        return false;
    }
    
    currentType = type;
    
    std::cout << "[NotificationManager] Notification method set to: " 
              << currentNotification->getType() << std::endl;
    
    return true;
}

// Notification nesnesini direkt ayarlar (Factory ile)
void NotificationManager::setNotification(Notification* notification) {
    // Eski notification'ı temizle
    if (currentNotification != NULL) {
        delete currentNotification;
        currentNotification = NULL;
    }
    
    currentNotification = notification;
    
    if (currentNotification != NULL) {
        currentType = currentNotification->getType();
        std::cout << "[NotificationManager] Notification set to: " 
                  << currentType << std::endl;
    }
}

// LLR19: Bildirim gönderir
void NotificationManager::notify(const std::string& message) {
    if (currentNotification == NULL) {
        std::cerr << "[NotificationManager] No notification method set!" 
                  << std::endl;
        return;
    }
    
    // Seçilen bildirim türüne göre mesaj gönder
    currentNotification->send(message);
}

// Şu anki bildirim tipini döndürür
std::string NotificationManager::getCurrentType() const {
    return currentType;
}

// Destructor - kaynakları temizle
NotificationManager::~NotificationManager() {
    if (currentNotification != NULL) {
        delete currentNotification;
        currentNotification = NULL;
    }
}