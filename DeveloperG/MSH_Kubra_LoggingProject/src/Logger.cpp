#include "Logger.h"

#include <iomanip>
#include <sstream>
#include <iostream>

// --- Singleton erişimi ---
Logger& Logger::instance() {
    static Logger inst;
    return inst;
}

// --- ctor/dtor ---
Logger::Logger() = default;

Logger::~Logger() {
    // Program kapanırken unutulsa bile dosyayı kapat
    shutdown();
}

// --- LLR6: initialize ---
void Logger::initialize(const std::string& filename, LogFormat format) {
    // Daha önce açıksa kapat
    if (m_isOpen) {
        shutdown();
    }

    m_format = format;

    m_file.open(filename, std::ios::out | std::ios::app);
    if (!m_file.is_open()) {
        m_isOpen = false;
        std::cerr << "[LOGGER] Failed to open log file: " << filename << std::endl;
        return;
    }

    m_isOpen = true;
}

// --- LLR30: log ---
void Logger::log(LogLevel level,
                 const std::string& message,
                 int deviceId,
                 const std::string& actionType) {
    if (!m_isOpen) {
        // initialize çağrılmamış olabilir
        return;
    }

    const std::string line = formatLogLine(level, message, deviceId, actionType);
    m_file << line << std::endl;
    m_file.flush();
}

// --- LLR7: shutdown ---
void Logger::shutdown() {
    if (m_isOpen) {
        m_file.close();
        m_isOpen = false;
    }
}

// --- helpers ---
std::string Logger::formatTime(std::time_t t) const {
    std::tm tmBuf{};
#if defined(_WIN32)
    localtime_s(&tmBuf, &t);
#else
    localtime_r(&t, &tmBuf);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tmBuf, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string Logger::levelToString(LogLevel level) const {
    switch (level) {
    case LogLevel::INFO:     return "INFO";
    case LogLevel::WARNING:  return "WARNING";
    case LogLevel::ERROR:    return "ERROR";
    default:                return "UNKNOWN";
    }
}

std::string Logger::formatLogLine(LogLevel level,
                                 const std::string& message,
                                 int deviceId,
                                 const std::string& actionType) const {
    const std::time_t now = std::time(nullptr);
    const std::string ts = formatTime(now);

    switch (m_format) {
    case LogFormat::JSON: {
        std::ostringstream oss;
        oss << "{"
            << "\"timestamp\":\"" << ts << "\","
            << "\"level\":\"" << levelToString(level) << "\","
            << "\"message\":\"" << message << "\","
            << "\"deviceId\":" << deviceId << ","
            << "\"actionType\":\"" << actionType << "\""
            << "}";
        return oss.str();
    }
    case LogFormat::XML: {
        std::ostringstream oss;
        oss << "<log>"
            << "<timestamp>" << ts << "</timestamp>"
            << "<level>" << levelToString(level) << "</level>"
            << "<message>" << message << "</message>"
            << "<deviceId>" << deviceId << "</deviceId>"
            << "<actionType>" << actionType << "</actionType>"
            << "</log>";
        return oss.str();
    }
    case LogFormat::YAML: {
        std::ostringstream oss;
        oss << "timestamp: " << ts << "\n"
            << "level: " << levelToString(level) << "\n"
            << "message: " << message << "\n"
            << "deviceId: " << deviceId << "\n"
            << "actionType: " << actionType;
        return oss.str();
    }
    default: {
        // Güvenli fallback
        std::ostringstream oss;
        oss << "{"
            << "\"timestamp\":\"" << ts << "\","
            << "\"level\":\"" << levelToString(level) << "\","
            << "\"message\":\"" << message << "\","
            << "\"deviceId\":" << deviceId << ","
            << "\"actionType\":\"" << actionType << "\""
            << "}";
        return oss.str();
    }
    }
}
