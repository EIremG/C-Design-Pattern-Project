// Logger.cpp
// Developer G - Kübra Akpınar
// LLR6, LLR7, LLR30: Logger implementation

#include "Logger.h"
#include "LogFormatter.h"
#include <iostream>
#include <ctime>
#include <sstream>

// Static member initialization
Logger* Logger::instance = NULL;

// Private constructor (Singleton)
Logger::Logger() : formatter(NULL), isInitialized(false) {
}

// Singleton getInstance
Logger* Logger::getInstance() {
    if (instance == NULL) {
        instance = new Logger();
    }
    return instance;
}

// LLR6: Log dosyası başlatma
bool Logger::initialize(const std::string& filename, LogFormatter* fmt) {
    if (isInitialized) {
        std::cerr << "[Logger] Already initialized!" << std::endl;
        return false;
    }
    
    if (fmt == NULL) {
        std::cerr << "[Logger] Error: LogFormatter is NULL!" << std::endl;
        return false;
    }
    
    this->filename = filename;
    this->formatter = fmt;
    
    // Dosyayı aç
    logFile.open(filename.c_str(), std::ios::out | std::ios::trunc);
    
    if (!logFile.is_open()) {
        std::cerr << "[Logger] Error: Could not open log file: " 
                  << filename << std::endl;
        return false;
    }
    
    isInitialized = true;
    
    // Prıjenin başlangıç mesajı
    std::string startMsg = "=== MSH Logging System Started ===\n";
    startMsg += "Format: " + formatter->getFormatType() + "\n";
    startMsg += "Timestamp: " + getCurrentTimestamp() + "\n";
    startMsg += "===================================\n";
    
    logFile << startMsg;
    logFile.flush();
    
    std::cout << "[Logger] Initialized successfully with " 
              << formatter->getFormatType() 
              << " format" << std::endl;
    
    return true;
}

// Genel log fonksiyonu
void Logger::log(const std::string& message) {
    if (!isInitialized) {
        std::cerr << "[Logger] Not initialized!" << std::endl;
        return;
    }
    
    logFile << message << std::endl;
    logFile.flush();
}

// LLR30: Her işlem loglanmalı (timestamp, action, deviceId)
void Logger::logAction(const std::string& timestamp,
                      const std::string& action,
                      int deviceId) {
    if (!isInitialized) {
        std::cerr << "[Logger] Not initialized!" << std::endl;
        return;
    }
    
    if (formatter == NULL) {
        std::cerr << "[Logger] Formatter is NULL!" << std::endl;
        return;
    }
    
    // Formatter ile mesajı formatla
    std::string formattedMsg = formatter->format(timestamp, action, deviceId);
    
    // Log dosyasına yaz
    logFile << formattedMsg << std::endl;
    logFile.flush();
    
    // Debug: konsola da yazdır
    std::cout << "[Logger] Logged: " << action 
              << " (DeviceID: " << deviceId << ")" << std::endl;
}

// LLR7: Kapanışta log dosyası kapatılır
void Logger::close() {
    if (!isInitialized) {
        return;
    }
    
    // Kapanış mesajı
    std::string endMsg = "\n=== MSH Logging System Closed ===\n";
    endMsg += "Timestamp: " + getCurrentTimestamp() + "\n";
    endMsg += "==================================\n";
    
    logFile << endMsg;
    logFile.flush();
    logFile.close();
    
    std::cout << "[Logger] Log file closed: " << filename << std::endl;
    
    isInitialized = false;
}

// Logger başlatılmış mı kontrolü
bool Logger::isReady() const {
    return isInitialized;
}

// Timestamp oluşturma
std::string Logger::getCurrentTimestamp() const {
    time_t now = time(NULL);
    char buffer[80];
    struct tm* timeinfo = localtime(&now);
    
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    return std::string(buffer);
}

// Destructor
Logger::~Logger() {
    if (isInitialized) {
        close();
    }
    
    // Formatter'ı temizle (factory'den geldiği için)
    if (formatter != NULL) {
        delete formatter;
        formatter = NULL;
    }
}