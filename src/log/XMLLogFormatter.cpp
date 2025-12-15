// XMLLogFormatter.cpp
// Developer G - Kübra Akpınar
// LLR8: XML formatında log oluşturma

#include "log/XMLLogFormatter.h"
#include <sstream>

// Constructor
XMLLogFormatter::XMLLogFormatter() {
}

// Destructor
XMLLogFormatter::~XMLLogFormatter() {
}

// LLR8: XML formatında log mesajı oluşturur
// Daha okunabilir XML çıktısı üretir (indent + newline)
std::string XMLLogFormatter::format(const std::string& timestamp,
                                   const std::string& action,
                                   int deviceId) {
    std::ostringstream oss;

    oss << "<log>\n";
    oss << "  <timestamp>" << escapeXml(timestamp) << "</timestamp>\n";
    oss << "  <action>" << escapeXml(action) << "</action>\n";
    oss << "  <deviceId>" << deviceId << "</deviceId>\n";
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
            case '<':  result += "&lt;";   break;
            case '>':  result += "&gt;";   break;
            case '&':  result += "&amp;";  break;
            case '"':  result += "&quot;"; break;
            case '\'': result += "&apos;"; break;
            default:   result += c;        break;
        }
    }

    return result;
}
