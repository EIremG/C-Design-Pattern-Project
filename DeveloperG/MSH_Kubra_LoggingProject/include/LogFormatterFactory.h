// LogFormatterFactory.h
// Developer G - Kübra Akpınar
// LLR8: Log format seçimi için Factory Method Pattern
// Pattern: Factory Method - if/else kullanmadan formatter oluşturur

#ifndef LOGFORMATTERFACTORY_H
#define LOGFORMATTERFACTORY_H

#include <string>
#include "LogFormatter.h"

/**
 * @class LogFormatterFactory
 * @brief LogFormatter nesnelerini üreten factory
 * 
 * LLR8: Kullanıcı tercihine göre JSON/XML/YAML formatter üretir
 * 
 * SOLID Prensipleri:
 * - Single Responsibility: Sadece formatter üretiminden sorumlu
 * - Open/Closed: Yeni format eklemek için factory'yi değiştiririz
 *   ama Logger'ı değiştirmeyiz
 * - Dependency Inversion: Logger concrete class yerine 
 *   LogFormatter abstract'ına bağımlı
 * 
 * Factory Method Pattern kullanımı:
 * - if/else switch/case yerine factory kullanarak 
 *   nesne üretimi merkezileştirilir
 * - Yeni formatter eklemek kolaydır
 * - Test edilebilirlik artar
 */
class LogFormatterFactory {
public:
    /**
     * @brief Format tipine göre LogFormatter oluşturur
     * @param type Format tipi ("json", "xml", "yaml")
     * @return LogFormatter* Oluşturulan formatter (NULL değilse)
     * 
     * Kullanım:
     * LogFormatter* fmt = LogFormatterFactory::createFormatter("json");
     * Logger::getInstance()->initialize("log.txt", fmt);
     * 
     * Desteklenen tipler:
     * - "json" veya "JSON" -> JSONLogFormatter
     * - "xml" veya "XML" -> XMLLogFormatter
     * - "yaml" veya "YAML" -> YAMLLogFormatter
     * - Bilinmeyen tip -> NULL döner
     */
    static LogFormatter* createFormatter(const std::string& type);
};

#endif 