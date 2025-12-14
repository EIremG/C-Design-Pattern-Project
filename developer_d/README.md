# Developer D - Camera + Motion System

Bu proje, güvenlik kamerası ve hareket algılama sistemi için tasarlanmış bir C++ uygulamasıdır. Proje, çeşitli tasarım desenlerini (Design Patterns) ve LLR (Low Level Requirements) gereksinimlerini içermektedir.

## 📋 İçindekiler

- [Gereksinimler](#gereksinimler)
- [Kurulum](#kurulum)
- [Derleme (Build)](#derleme-build)
- [Çalıştırma](#çalıştırma)
- [Test Sonuçları](#test-sonuçları)
- [Tasarım Desenleri](#tasarım-desenleri)
- [LLR'ler](#llrler)

## 🔧 Gereksinimler

- **CMake**: 3.10 veya üzeri
- **C++ Compiler**: C++98 standardını destekleyen bir derleyici (g++, clang++, vb.)
- **Make**: Unix/Linux/MacOS için (Windows'ta MinGW veya Visual Studio kullanılabilir)

### CMake Versiyonunu Kontrol Etme

```bash
cmake --version
```

## 📦 Kurulum

1. Projeyi klonlayın veya indirin:
```bash
git clone https://github.com/EIremG/C-Design-Pattern-Project.git
cd C-Design-Pattern-Project
git checkout göktuğ
cd developer_d
```

## 🔨 Derleme (Build)

### Adım 1: Build Dizini Oluşturma

```bash
mkdir build
cd build
```

### Adım 2: CMake ile Yapılandırma

```bash
cmake ..
```

Bu komut CMakeLists.txt dosyasını okuyup projeyi yapılandıracaktır.

### Adım 3: Derleme

```bash
make
```

veya Windows'ta Visual Studio kullanıyorsanız:

```bash
cmake --build .
```

### Tek Komutla Derleme

Tüm adımları tek seferde yapmak için:

```bash
mkdir -p build && cd build && cmake .. && make
```

## ▶️ Çalıştırma

Derleme tamamlandıktan sonra, `build` dizininde `main` adında bir çalıştırılabilir dosya oluşacaktır:

```bash
cd build
./main
```

veya tek satırda:

```bash
cd build && ./main
```

## ✅ Test Sonuçları

Program çalıştırıldığında 6 farklı test otomatik olarak çalıştırılır:

1. **Singleton Pattern Test**: EventQueue, EventObjectPool ve DeviceManager singleton'larının doğru çalışması
2. **Builder Pattern Test**: CameraBuilder ile kamera oluşturma
3. **Object Pool Pattern Test**: Event nesnelerinin pool'dan alınıp geri verilmesi
4. **Observer Pattern Test**: EventDispatcher ve SecuritySystem arasındaki iletişim
5. **Motion Detection Test (LLR25)**: Tam hareket algılama akışı
6. **Debug Simulator Test (LLR38)**: Simülatör fonksiyonlarının test edilmesi

### Beklenen Çıktı

Program başarıyla çalıştığında şu çıktıyı göreceksiniz:

```
========================================
TEST SONUÇLARI
========================================
Başarılı Testler: 6/6
>>> TÜM TESTLER BAŞARILI! ✓✓✓

========================================
PROGRAM BAŞARIYLA TAMAMLANDI!
========================================
```

## 🎨 Tasarım Desenleri

Bu proje aşağıdaki tasarım desenlerini içermektedir:

1. **Singleton Pattern**: 
   - `EventQueue`
   - `EventObjectPool`
   - `DeviceManager`

2. **Builder Pattern**: 
   - `CameraBuilder` (fluent interface ile)

3. **Observer Pattern**: 
   - `EventDispatcher` + `SecuritySystem`

4. **Object Pool Pattern**: 
   - `EventObjectPool` (event nesnelerinin yeniden kullanımı)

## 📝 LLR'ler (Low Level Requirements)

Proje aşağıdaki LLR gereksinimlerini karşılamaktadır:

- **LLR10**: Camera Device Class with inheritance from Device
- **LLR25**: Motion Detection -> Alarm Sequence (Observer pattern)
- **LLR29**: Event Queue/Scheduler with FIFO processing
- **LLR34**: Camera Configuration using Builder pattern
- **LLR38**: Debug Simulator for testing

## 🗂️ Proje Yapısı

```
developer_d/
├── CMakeLists.txt          # CMake yapılandırma dosyası
├── main.cpp                # Ana program ve testler
├── Device.h/cpp            # Temel cihaz sınıfı
├── Camera.h/cpp            # Kamera sınıfı
├── CameraBuilder.h/cpp     # Kamera builder sınıfı
├── Event.h/cpp             # Temel event sınıfı
├── MotionEvent.h/cpp       # Hareket event sınıfı
├── AlarmEvent.h/cpp        # Alarm event sınıfı
├── DeviceFailureEvent.h/cpp # Cihaz hata event sınıfı
├── EventQueue.h/cpp        # Event kuyruğu (Singleton)
├── EventObjectPool.h/cpp   # Event object pool (Singleton)
├── EventDispatcher.h/cpp   # Event dağıtıcı
├── EventObserver.h         # Observer interface
├── EventType.h             # Event tipleri
├── SecuritySystem.h/cpp    # Güvenlik sistemi
├── DeviceManager.h/cpp     # Cihaz yöneticisi (Singleton)
└── DebugSimulator.h/cpp   # Debug simülatörü
```

## 🐛 Sorun Giderme

### CMake Bulunamıyor

Eğer `cmake: command not found` hatası alıyorsanız:

**macOS:**
```bash
brew install cmake
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install cmake
```

**Windows:**
CMake'i [cmake.org](https://cmake.org/download/) adresinden indirip kurun.

### Derleme Hataları

Eğer derleme sırasında hata alıyorsanız:

1. Build dizinini temizleyin:
```bash
rm -rf build
```

2. Tekrar derleyin:
```bash
mkdir build && cd build && cmake .. && make
```

### Program Çalışmıyor

Eğer program çalışmıyorsa:

1. Derlemenin başarılı olduğundan emin olun
2. `build/main` dosyasının var olduğunu kontrol edin
3. Çalıştırma izinlerini kontrol edin:
```bash
chmod +x build/main
```

## 📄 Lisans

Bu proje eğitim amaçlı geliştirilmiştir.

## 👤 Geliştirici

Developer D - Göktuğ

---

**Not**: Bu proje CMake build sistemi ile teslim edilmiştir. Tüm kaynak dosyalar ve CMakeLists.txt dosyası repository'de bulunmaktadır.

