// YAMLLogFormatter.cpp
// Developer G - Kübra Akpınar
// LLR8: YAML formatında log oluşturma

#include "log/YAMLLogFormatter.h"
#include <sstream>

// Constructor
YAMLLogFormatter::YAMLLogFormatter() {
}

// Destructor
YAMLLogFormatter::~YAMLLogFormatter() {
}

// LLR8: YAML formatında log mesajı oluşturur
// Örnek:
// ---
// timestamp: "2025-12-12 14:30:00"
// action: "AddDevice"
// deviceId: 10
std::string YAMLLogFormatter::format(const std::string& timestamp,
                                    const std::string& action,
                                    int deviceId) {
    std::ostringstream oss;
    
    oss << "---\n";
    oss << "timestamp: " << quoteIfNeeded(timestamp) << "\n";
    oss << "action: " << quoteIfNeeded(action) << "\n";
    oss << "deviceId: " << deviceId;
    
    return oss.str();
}

// Format tipini döndürür
std::string YAMLLogFormatter::getFormatType() const {
    return "YAML";
}

// YAML için string quote'lama (gerekirse)
std::string YAMLLogFormatter::quoteIfNeeded(const std::string& str) const {
    // YAML'da özel karakterler varsa quote'la
    bool needsQuote = false;
    
    // Boşluk, :, #, vb. varsa quote gerekir
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c == ':' || c == '#' || c == '-' || c == '[' || c == ']' ||
            c == '{' || c == '}' || c == ',' || c == '&' || c == '*' ||
            c == '!' || c == '|' || c == '>' || c == '\'' || c == '"' ||
            c == '%' || c == '@' || c == '`') {
            needsQuote = true;
            break;
        }
    }
    
    if (needsQuote || str.empty()) {
        return "\"" + str + "\"";
    }
    
    return str;
}

// Integer'ı string'e çevirme (C++98 uyumlu)
std::string YAMLLogFormatter::intToString(int value) const {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}