# Developer D - Camera + Motion System

## Derleme ve Çalıştırma

### Gereksinimler
- CMake 3.10 veya üzeri
- C++ derleyici (g++, clang++, vb.)
- Make

### Adımlar

1. **Build dizini oluştur ve derle:**
```bash
mkdir -p build && cd build && cmake .. && make
```

2. **Programı çalıştır:**
```bash
./main
```

### Tek Komutla (Build + Çalıştır)
```bash
mkdir -p build && cd build && cmake .. && make && ./main
```

## Test Sonuçları

Program çalıştırıldığında 6 test otomatik olarak çalışır. Başarılı çalıştırmada şu çıktı görülür:

```
Başarılı Testler: 6/6
>>> TÜM TESTLER BAŞARILI! ✓✓✓
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
