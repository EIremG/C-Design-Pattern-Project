### C++ DESIGN PATTERNS PROJE RAPORU  
**Proje Adı:** My Sweet Home (MSH)  
**Ders:** BIL464 - Design Patterns  
**Hazırlayan:** Kerem — Developer A (Integrator)

#### Ekip Üyeleri
| Rol | İsim | Öğrenci No |
|------|------|-------------|
| **Developer A (Integrator)** | Kerem | 220206403 |
| Developer B | İrem | 220206404 |
| Developer C | Kaan | 220206405 |
| Developer D | Göktuğ | 220206406 |
| Developer E | Sencer | 220206407 |
| Developer F | Selin | 220206042 |
| Developer G | Kübra | 220206409 |
| Developer H | Şeyma | 220206410 |

---

## 1. Proje Özeti
**My Sweet Home (MSH)**, tasarım desenleri (Design Patterns) prensiplerini uygulayarak geliştirilmiş, konsol tabanlı bir akıllı ev yönetim sistemidir. Sistem kullanıcıya cihaz ekleme, çıkarma, mod değiştirme, olay simülasyonu ve log yönetimi gibi işlemleri gerçekleştirme imkânı sunar. CMake yapısı ve modüler mimarisi sayesinde her bir geliştirici (Developer A–H) kendi modülünü bağımsız şekilde geliştirmiş ve Kerem (Dev A) tarafından entegre edilmiştir.

---

## 2. Proje Mimarisi
Proje, aşağıdaki klasör yapısına göre organize edilmiştir:

```
DeveloperA/
│
├── include/
│   ├── core/       → Uygulama akışı, Input, MenuController, AppServices
│   ├── mode/       → Mode ve State yönetimi
│   ├── devices/    → Cihazlar, Factory ve Manager yapısı
│   ├── alarm/      → Alarm sistemi, Detector sınıfları
│   ├── sim/        → EventQueue, DebugSimulator, EventDispatcher
│   ├── log/        → Logger, Formatter, NotificationManager
│   └── ui/         → Kullanıcı arayüzü (menüler, cihaz ekleme/çıkarma)
│
├── src/            → Tüm modüllerin implementasyon dosyaları (.cpp)
├── tests/          → Unit test dosyaları (TinyTest, DeviceTests, TestRunner)
├── CMakeLists.txt  → CMake yapılandırma dosyası
└── out/build/      → Derleme çıktıları (CMake)
```

---

## 3. Kullanılan Tasarım Desenleri
| Design Pattern | Kullanıldığı Modül | Açıklama |
|-----------------|-------------------|-----------|
| **Singleton** | Alarm, Logger, EventQueue, HomeDeviceManager | Tekil nesne örneği oluşturularak sistem genelinde erişim sağlanmıştır. |
| **Factory** | DeviceFactory, LogFormatterFactory, DetectorFactory | Cihaz ve log formatı üretimi için kullanılmıştır. |
| **Observer** | EventDispatcher, NotificationManager | Olayların gözlemciler aracılığıyla dağıtılması sağlanmıştır. |
| **Prototype** | HomeDevice (clone metodu) | Cihazların kopyalanabilmesi için kullanılmıştır. |
| **Object Pool** | EventObjectPool | Event nesnelerinin tekrar kullanımı için optimize edilmiştir. |
| **Facade** | AppServices | Kullanıcı işlemlerini modüller arası karmaşıklığı gizleyerek yönetmiştir. |
| **Strategy** | LogFormatterFactory | Log çıktısının formatlanma biçimi (JSON, XML, PlainText) değiştirilebilir yapılmıştır. |

---

## 4. Modül Bazlı İnceleme
### 🔹 Core Modülü
- **App.cpp / AppServices.cpp:** Ana uygulama döngüsünü ve menü akışını yönetir.  
- Kullanıcı seçimlerine göre alt modüller (Devices, Mode, Sim, Alarm) çağrılır.  
- Sinyal kesme (SignalFlag) ile kontrollü çıkış yapılır.

### 🔹 Devices Modülü
- **HomeDevice, DeviceFactory, HomeDeviceManager:**  
  Her cihaz (ışık, TV, müzik sistemi, kamera, dedektör, alarm) için soyut sınıflar ve fabrika metotları içerir.  
- **CriticalDeviceGuard:** Kritik cihazların yanlışlıkla kapatılmasını önler.

### 🔹 Mode Modülü
- **ModeManager & StateManager:** Kullanıcı modlarını (Normal, Evening, Party, Cinema) yönetir.  
- Önceki state kayıtlarını tutarak “Previous Mode” işlevini sağlar (LLR26).

### 🔹 Alarm Modülü
- **Alarm (Singleton):** Tehlike durumlarında alarm üretir ve kullanıcı onayı bekler.  
- **LLR27–28:** Alarmın zamanla acil durum çağrısına dönüşmesi ve ışıkların yanıp sönmesi sağlanmıştır.

### 🔹 Simülasyon (Sim) Modülü
- **DebugSimulator:** Hareket, alarm ve cihaz arıza olaylarını simüle eder.  
- **EventQueue & EventDispatcher:** Kuyruk sistemiyle olayları sıralı olarak işler. (LLR38–39)

### 🔹 Log ve Notification Modülü
- **Logger (Singleton):** Tüm eylemleri `msh.log` dosyasına yazar.  
- **LogFormatterFactory:** Log formatını dinamik olarak belirler.  
- **NotificationManager:** Kullanıcıya bildirimler gönderir (LLR30–31).

### 🔹 UI Modülü
- **DeviceUI.cpp:** Kullanıcıdan cihaz ekleme/çıkarma girişlerini alır.  
- Menü, `Input::readIntInRange` ve `Input::readLine` fonksiyonlarıyla güvenli veri alımı sağlar.

### 🔹 Tests Modülü
- **TinyTest & TestRunner:** Input fonksiyonları ve DeviceFactory metotları test edilir.  
- `msh.exe -test` komutuyla çalışır, sonuçlar `test_report.txt`’ye yazılır.

---

## 5. Gereksinim ve LLR Eşleşmeleri
| Gereksinim | LLR No | Modül | Açıklama |
|-------------|---------|--------|-----------|
| REQ1 | LLR1–4 | Core | Uygulama temel akışı |
| REQ2 | LLR5–8 | Devices | Cihaz üretimi ve yönetimi |
| REQ3 | LLR9–13 | Mode | Mod değişimi ve önceki mod yönetimi |
| REQ4 | LLR14–19 | Alarm | Alarm tetikleme ve senaryo yönetimi |
| REQ5 | LLR20–26 | Sim | Olay kuyruğu ve dispatcher sistemi |
| REQ6 | LLR27–30 | Log | Loglama ve bildirim altyapısı |
| REQ7 | LLR31–34 | UI | Kullanıcı etkileşimi ve menüler |
| REQ8 | LLR35–40 | Test | Otomatik test ve doğrulama |

---

## 6. Çalıştırma Talimatları
### 🔹 Derleme
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 🔹 Uygulamayı çalıştırma
```bash
./msh.exe
```

### 🔹 Testleri çalıştırma
```bash
./msh.exe -test
```
Çıktılar `test_report.txt` dosyasına yazılır.

---

## 7. Sonuç
Bu proje, C++ dilinde tasarım desenlerinin birlikte kullanımını gösteren, çok geliştiricili bir yazılım mimarisine örnek teşkil etmektedir.  
Her modül bağımsız olarak geliştirilebilmiş, CMake entegrasyonu sayesinde birleştirilebilmiştir.  
Sonuç olarak **My Sweet Home**, tasarım desenlerinin mühendislik yaklaşımıyla uygulanmasını pratikte göstermektedir.

---

**Hazırlayan:**  
Kerem — *Developer A (Integrator)*  
OSTİM Teknik Üniversitesi, Bilgisayar Mühendisliği  
2025

