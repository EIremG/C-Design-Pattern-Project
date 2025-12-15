// Logger.cpp
// Developer G - Kübra Akpınar
// LLR6, LLR7, LLR30: Logger implementation

#include "log/Logger.h"
#include "log/LogFormatter.h"
#include <iostream>
#include <ctime>
#include <sstream>

Logger* Logger::instance = NULL;

Logger::Logger() : formatter(NULL), isInitialized(false) {
}

Logger* Logger::getInstance() {
    if (instance == NULL) {
        instance = new Logger();
    }
    return instance;
}

// LLR6: Log dosyası başlatma
bool Logger::initialize(const std::string& logFilename, LogFormatter* fmt) {
    if (isInitialized) {
        std::cerr << "[Logger] Already initialized!" << std::endl;
        return false;
    }

    if (fmt == NULL) {
        std::cerr << "[Logger] Error: LogFormatter is NULL!" << std::endl;
        return false;
    }

    this->filename = logFilename;
    this->formatter = fmt;

    // Dosyayı aç
    logFile.open(logFilename.c_str(), std::ios::out | std::ios::trunc);

    if (!logFile.is_open()) {
        std::cerr << "[Logger] Error: Could not open log file: "
                  << logFilename << std::endl;
        return false;
    }

    isInitialized = true;

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

void Logger::log(const std::string& message) {
    if (!isInitialized) {
        std::cerr << "[Logger] Not initialized!" << std::endl;
        return;
    }

    logFile << message << std::endl;
    logFile.flush();
}

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

    std::string formattedMsg = formatter->format(timestamp, action, deviceId);

    logFile << formattedMsg << std::endl;
    logFile.flush();

    std::cout << "[Logger] Logged: " << action
              << " (DeviceID: " << deviceId << ")" << std::endl;
}

void Logger::close() {
    if (!isInitialized) {
        return;
    }

    std::string endMsg = "\n=== MSH Logging System Closed ===\n";
    endMsg += "Timestamp: " + getCurrentTimestamp() + "\n";
    endMsg += "==================================\n";

    logFile << endMsg;
    logFile.flush();
    logFile.close();

    std::cout << "[Logger] Log file closed: " << filename << std::endl;

    isInitialized = false;
}

bool Logger::isReady() const {
    return isInitialized;
}

// C4996 fix: MSVC -> localtime_s, diğerleri -> localtime
std::string Logger::getCurrentTimestamp() const {
    time_t now = time(NULL);

    struct tm timeinfo;
#ifdef _MSC_VER
    localtime_s(&timeinfo, &now);
#else
    struct tm* tmp = localtime(&now);
    if (tmp) timeinfo = *tmp;
    else {
        // fallback boş zaman
        timeinfo.tm_year = 70; timeinfo.tm_mon = 0; timeinfo.tm_mday = 1;
        timeinfo.tm_hour = 0; timeinfo.tm_min = 0; timeinfo.tm_sec = 0;
    }
#endif

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return std::string(buffer);
}

Logger::~Logger() {
    if (isInitialized) {
        close();
    }

    if (formatter != NULL) {
        delete formatter;
        formatter = NULL;
    }
}
