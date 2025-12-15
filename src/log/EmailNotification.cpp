// EmailNotification.cpp
// Developer G - Kübra Akpınar
// LLR19, LLR36: Email bildirim implementasyonu (simülasyon)

#include "log/EmailNotification.h"
#include <iostream>

// Constructor - varsayılan email
EmailNotification::EmailNotification() 
    : emailAddress("admin@msh-system.com") {
}

// Constructor - özel email ile
EmailNotification::EmailNotification(const std::string& email)
    : emailAddress(email) {
}

// Destructor
EmailNotification::~EmailNotification() {
}

// LLR19: Email gönderimini simüle eder
void EmailNotification::send(const std::string& message) {
    // Email simülasyonu - konsola özel formatta yazdırılır
    std::cout << "\n";
    std::cout << "========================================" << std::endl;
    std::cout << "An Email is sent to: " << emailAddress << std::endl;
    std::cout << "Subject: MSH Alert - Device Notification" << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "\n";
}

// Bildirim tipini döndürür
std::string EmailNotification::getType() const {
    return "Email";
}

// Email adresini ayarla
void EmailNotification::setEmailAddress(const std::string& email) {
    emailAddress = email;
}

// Email adresini al
std::string EmailNotification::getEmailAddress() const {
    return emailAddress;
}