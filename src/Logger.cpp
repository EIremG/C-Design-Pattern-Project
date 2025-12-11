#include "../include/Logger.h"

// Static member initialization
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
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return std::string(buffer);
}

std::string Logger::logLevelToString(LogLevel level) {
    switch(level) {
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::DEBUG:   return "DEBUG";
        default:               return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::string timestamp = getCurrentTimestamp();
    std::string levelStr = logLevelToString(level);
    
    std::string logMessage = "[" + timestamp + "] [" + levelStr + "] " + message;
    
    // Console output
    std::cout << logMessage << std::endl;
    
    // File output if enabled
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