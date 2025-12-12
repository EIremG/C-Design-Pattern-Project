// JSONLogFormatter.cpp
// Developer G - Kübra Akpınar
// LLR8: JSON formatında log oluşturma

#include "JSONLogFormatter.h"
#include <sstream>

// Constructor
JSONLogFormatter::JSONLogFormatter() {
}

// Destructor
JSONLogFormatter::~JSONLogFormatter() {
}

// LLR8: JSON formatında log mesajı oluşturur
// Örnek: {"timestamp":"2025-12-12 14:30:00","action":"AddDevice","deviceId":10}
std::string JSONLogFormatter::format(const std::string& timestamp,
                                    const std::string& action,
                                    int deviceId) {
    std::ostringstream oss;
    
    oss << "{";
    oss << "\"timestamp\":\"" << escapeJson(timestamp) << "\",";
    oss << "\"action\":\"" << escapeJson(action) << "\",";
    oss << "\"deviceId\":" << deviceId;
    oss << "}";
    
    return oss.str();
}

// Format tipini döndürür
std::string JSONLogFormatter::getFormatType() const {
    return "JSON";
}

// JSON için string escape (", \, vb.)
std::string JSONLogFormatter::escapeJson(const std::string& str) const {
    std::string result;
    result.reserve(str.length());
    
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        
        switch (c) {
            case '"':
                result += "\\\"";
                break;
            case '\\':
                result += "\\\\";
                break;
            case '\n':
                result += "\\n";
                break;
            case '\r':
                result += "\\r";
                break;
            case '\t':
                result += "\\t";
                break;
            default:
                result += c;
                break;
        }
    }
    
    return result;
}