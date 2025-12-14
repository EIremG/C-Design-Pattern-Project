# Developer D - Camera + Motion System

## Proje Yapısı

```
developer_d/
├── include/              # Header dosyaları (.h)
│   ├── EventType.h
│   ├── Device.h
│   ├── Event.h
│   ├── MotionEvent.h
│   ├── AlarmEvent.h
│   ├── DeviceFailureEvent.h
│   ├── EventObserver.h
│   ├── EventQueue.h
│   ├── EventObjectPool.h
│   ├── EventDispatcher.h
│   ├── Camera.h
│   ├── CameraBuilder.h
│   ├── SecuritySystem.h
│   ├── DeviceManager.h
│   └── DebugSimulator.h
├── src/                  # Kaynak dosyaları (.cpp)
│   ├── Device.cpp
│   ├── Event.cpp
│   ├── MotionEvent.cpp
│   ├── AlarmEvent.cpp
│   ├── DeviceFailureEvent.cpp
│   ├── EventQueue.cpp
│   ├── EventObjectPool.cpp
│   ├── EventDispatcher.cpp
│   ├── Camera.cpp
│   ├── CameraBuilder.cpp
│   ├── SecuritySystem.cpp
│   ├── DeviceManager.cpp
│   └── DebugSimulator.cpp
├── build/                # Build çıktıları (oluşturulur)
├── main.cpp             # Ana program
├── CMakeLists.txt       # CMake yapılandırma
└── README.md            # Bu dosya
```

## Derleme ve Çalıştırma

### Gereksinimler
- CMake 3.10 veya üzeri
- C++ derleyici (g++, clang++, vb.)
- Make

### Adımlar

1. **Proje dizinine gidin:**
```bash
cd developer_d
```

2. **Build dizini oluştur ve derle:**
```bash
mkdir -p build && cd build && cmake .. && make
```

3. **Programı çalıştır:**
```bash
./main
```

### Tek Komutla (Build + Çalıştır)
```bash
cd developer_d && mkdir -p build && cd build && cmake .. && make && ./main
```

### Temiz Build (Önceki build'i silerek)
```bash
cd developer_d && rm -rf build && mkdir -p build && cd build && cmake .. && make && ./main
```

## Test Sonuçları

Program çalıştırıldığında 6 test otomatik olarak çalışır:

1. **Test 1: Singleton Pattern** - EventQueue, EventObjectPool ve DeviceManager'ın tek instance olduğunu doğrular
2. **Test 2: Builder Pattern** - CameraBuilder ile Camera oluşturma ve yapılandırma
3. **Test 3: Object Pool Pattern** - Event nesnelerinin yeniden kullanımı
4. **Test 4: Observer Pattern** - EventDispatcher ve SecuritySystem arasındaki gözlemci deseni
5. **Test 5: Motion Detection (LLR25)** - Hareket algılama akışı: Camera → Event → Dispatcher → SecuritySystem
6. **Test 6: Debug Simulator (LLR38)** - Simüle edilmiş hareket ve cihaz arızası testleri

Başarılı çalıştırmada program sonunda şu mesaj görülür:

```
========================================
All Tests Completed Successfully!
========================================
```

## Tasarım Desenleri

- Singleton Pattern (EventQueue, EventObjectPool, DeviceManager)
- Builder Pattern (CameraBuilder)
- Observer Pattern (EventDispatcher + SecuritySystem)
- Object Pool Pattern (EventObjectPool)

## LLR'ler

- LLR10: Camera Device Class
- LLR25: Motion Detection -> Alarm Sequence
- LLR29: Event Queue/Scheduler
- LLR34: Camera Configuration (Builder)
- LLR38: Debug Simulator
