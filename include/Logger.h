#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <mutex>

// LLR16 - Log Seviyesi Enum'ı
enum class LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    CRITICAL = 3
};

class Logger {
private:
    static Logger* instance;
    static std::mutex mutex_; // Thread güvenliği için
    std::ofstream logFile;
    bool fileLoggingEnabled = false;

    // Singleton deseni için private kurucu
    Logger() {} 

    std::string getTimestamp() const {
        // Mevcut zamanı al ve formatla (YYYY-MM-DD HH:MM:SS)
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* now_tm = std::localtime(&now_c);
        std::stringstream ss;
        ss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    std::string levelToString(LogLevel level) const {
        switch (level) {
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::INFO: return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::CRITICAL: return "CRITICAL";
        }
        return "UNKNOWN";
    }

public:
    // Kopya kurucuyu ve atama operatörünü sil
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    // LLR10 - Singleton Erişim Metodu
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_); // Mutex ile thread güvenliği sağlanır
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void enableFileLogging(const std::string& filename) {
        if (logFile.is_open()) logFile.close();
        // Dosyayı append modunda aç
        logFile.open(filename, std::ios::app);
        if (logFile.is_open()) {
            fileLoggingEnabled = true;
            log(LogLevel::INFO, "File logging enabled to " + filename);
        } else {
            std::cerr << "Error: Could not open log file " << filename << std::endl;
            fileLoggingEnabled = false;
        }
    }

    // LLR16 - Loglama Metodu
    void log(LogLevel level, const std::string& message) {
        std::string logEntry = "[" + getTimestamp() + "][" + levelToString(level) + "] " + message;
        
        // Konsol çıktısı
        std::cout << logEntry << std::endl;

        // Dosya çıktısı
        if (fileLoggingEnabled) {
            std::lock_guard<std::mutex> lock(mutex_);
            if (logFile.is_open()) {
                logFile << logEntry << std::endl;
                logFile.flush(); // Hemen diske yazmayı zorla
            }
        }
    }
};

// Statik Üyelerin Başlatılması
Logger* Logger::instance = nullptr;
std::mutex Logger::mutex_;