// LogFormatterFactory.cpp
// Developer G - Kübra Akpınar
// LLR8: Factory Method Pattern - LogFormatter üretimi

#include "LogFormatterFactory.h"
#include "JSONLogFormatter.h"
#include "XMLLogFormatter.h"
#include "YAMLLogFormatter.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// String'i lowercase'e çeviren yardımcı fonksiyon (C++98 uyumlu)
static std::string toLowerCase(const std::string& str) {
    std::string result = str;
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] = tolower(static_cast<unsigned char>(result[i]));
    }
    return result;
}

// LLR8: Format tipine göre LogFormatter oluşturur
LogFormatter* LogFormatterFactory::createFormatter(const std::string& type) {
    // Tip kontrolü için lowercase'e çevir
    std::string lowerType = toLowerCase(type);
    
    // JSON formatter
    if (lowerType == "json") {
        std::cout << "[LogFormatterFactory] Creating JSON formatter" << std::endl;
        return new JSONLogFormatter();
    }
    
    // XML formatter
    if (lowerType == "xml") {
        std::cout << "[LogFormatterFactory] Creating XML formatter" << std::endl;
        return new XMLLogFormatter();
    }
    
    // YAML formatter
    if (lowerType == "yaml" || lowerType == "yml") {
        std::cout << "[LogFormatterFactory] Creating YAML formatter" << std::endl;
        return new YAMLLogFormatter();
    }
    
    // Bilinmeyen format
    std::cerr << "[LogFormatterFactory] ERROR: Unknown format type: " 
              << type << std::endl;
    std::cerr << "[LogFormatterFactory] Supported formats: json, xml, yaml" 
              << std::endl;
    
    return NULL;
}