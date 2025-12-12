// XMLLogFormatter.cpp
// Developer G - Kübra Akpınar
// LLR8: XML formatında log oluşturma

#include "XMLLogFormatter.h"
#include <sstream>

// Constructor
XMLLogFormatter::XMLLogFormatter() {
}

// Destructor
XMLLogFormatter::~XMLLogFormatter() {
}

// LLR8: XML formatında log mesajı oluşturur
// Örnek: <log><timestamp>2025-12-12 14:30:00</timestamp><action>AddDevice</action><deviceId>10</deviceId></log>
std::string XMLLogFormatter::format(const std::string& timestamp,
                                   const std::string& action,
                                   int deviceId) {
    std::ostringstream oss;
    
    oss << "<log>";
    oss << "<timestamp>" << escapeXml(timestamp) << "</timestamp>";
    oss << "<action>" << escapeXml(action) << "</action>";
    oss << "<deviceId>" << deviceId << "</deviceId>";
    oss << "</log>";
    
    return oss.str();
}

// Format tipini döndürür
std::string XMLLogFormatter::getFormatType() const {
    return "XML";
}

// XML için string escape (<, >, &, vb.)
std::string XMLLogFormatter::escapeXml(const std::string& str) const {
    std::string result;
    result.reserve(str.length());
    
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        
        switch (c) {
            case '<':
                result += "&lt;";
                break;
            case '>':
                result += "&gt;";
                break;
            case '&':
                result += "&amp;";
                break;
            case '"':
                result += "&quot;";
                break;
            case '\'':
                result += "&apos;";
                break;
            default:
                result += c;
                break;
        }
    }
    
    return result;
}