#include "Logger.h"

Logger* Logger::instance = nullptr;

Logger::Logger() : fileLogging(false) {
}

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

std::string Logger::getCurrentTimestamp() {
    time_t now = time(0);
    char buffer[80];
    struct tm* timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

std::string Logger::logLevelToString(LogLevel level) {
    switch(level) {
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::CRITICAL: return "CRITICAL";
        // ERROR kaldırıldı çünkü CRITICAL ile aynı değerde (3)
        default:               return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string timestamp = getCurrentTimestamp();
    std::string levelStr = logLevelToString(level);
    
    std::string logMessage = "[" + timestamp + "] [" + levelStr + "] " + message;
    
    std::cout << logMessage << std::endl;
    
    if (fileLogging && logFile.is_open()) {
        logFile << logMessage << std::endl;
        logFile.flush();
    }
}

void Logger::enableFileLogging(const std::string& filename) {
    if (logFile.is_open()) {
        logFile.close();
    }
    
    logFile.open(filename, std::ios::app);
    if (logFile.is_open()) {
        fileLogging = true;
        log(LogLevel::INFO, "File logging enabled: " + filename);
    } else {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void Logger::disableFileLogging() {
    if (fileLogging && logFile.is_open()) {
        log(LogLevel::INFO, "File logging disabled");
        logFile.close();
        fileLogging = false;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}