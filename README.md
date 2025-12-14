# MSH Logging & Notification Project

**Developer G - Kübra Akpınar (220206033)**  
**BIL464 - Design Patterns with C++**
**Project:** My Sweet Home (MSH) - Logging & Notification Module  

---

## Proje Özeti
Bu modül, MSH (My Sweet Home) akıllı ev sisteminin **logging (kayıt tutma)** ve  
**notification (bildirim)** altyapısını sağlar.

---

## Sorumluluk Alanları (LLR)
- **LLR6:** Log dosyası başlatma  
- **LLR7:** Log dosyasını kapatma  
- **LLR8:** JSON / XML / YAML format seçimi  
- **LLR19:** Arıza bildirim sistemi  
- **LLR30:** Her işlemin loglanması  
- **LLR36:** Kullanıcı bildirim tercihi  

---

## Kullanılan Design Pattern’ler

### 1. Singleton Pattern
- **Nerede:** `Logger`
- **Amaç:** Sistem genelinde tek logger instance kullanılması

### 2. Factory Method Pattern
- **Nerede:** `LogFormatterFactory`, `NotificationFactory`
- **Amaç:** Nesne oluşturmayı merkezileştirmek

### 3. Strategy Pattern
- **Nerede:** `LogFormatter`, `Notification`
- **Amaç:** Runtime'da davranış değiştirebilme

---

## Sınıf Yapısı

### Logger + LogFormatter

Logger (Singleton)
├── LogFormatter (interface)
│ ├── JSONLogFormatter
│ ├── XMLLogFormatter
│ └── YAMLLogFormatter
└── LogFormatterFactory


### NotificationManager + Notification
NotificationManager
├── Notification (interface)
│ ├── ConsoleNotification
│ ├── SMSNotification
│ ├── EmailNotification
│ └── AlarmNotification
└── NotificationFactory



## Dosya Yapısı
MSH_Kubra_LoggingProject/
├── include/
├── src/
├── main.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md



## Derleme ve Çalıştırma
### Windows
```bash
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\MSH_Logging.exe

Linux / macOS:
mkdir build
cd build
cmake ..
make
./MSH_Logging


Test Akışı
 1.Log formatı seçilir (json/xml/yaml)
 2.Bildirim yöntemi seçilir (console/sms/email/alarm)
 3.İşlemler loglanır
 4.Arıza bildirimi gönderilir
 5.Log dosyası kapatılır


Log Dosyası:
Log çıktısı msh_log.txt dosyasına yazılır.
Bu dosya runtime çıktısıdır ve .gitignore içinde yer aldığı için repoya eklenmez.


SOLID Prensipleri (Özet)
 SRP: Her sınıf tek sorumluluk
 OCP: Yeni format/bildirim eklenebilir
 LSP: Türevler base yerine kullanılabilir
 ISP: Küçük ve net interface’ler
 DIP: Abstract sınıflara bağımlılık


Git:
Tüm geliştirme süreci Git ile takip edilmiştir.
Commit geçmişi ekran görüntüsü teslim edilmiştir.