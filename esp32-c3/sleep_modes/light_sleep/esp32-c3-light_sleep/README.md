# ESP32-C3 – Deep Sleep Mode Test

Dieser Test misst den Stromverbrauch des ESP32-C3 im Deep-Sleep-Modus mit Wakeup alle 10 Sekunden per interner RTC.

## Testverhalten

- Der ESP32-C3 wird in den Deep Sleep versetzt
- Wakeup erfolgt nach 10 Sekunden über den RTC-Timer
- Vor dem Sleep werden alle verfügbaren GPIOs in einen Low-Power-Zustand gesetzt
- Reset-Grund wird bei jedem Neustart ausgegeben

## Entwicklungsumgebung

- Framework: ESP-IDF (getestet mit Version 5.2.2)
- Mikrocontroller: ESP32-C3 Mini-1
- Toolchain: xtensa-esp32c3-elf
- IDE (empfohlen): Visual Studio Code mit ESP-IDF Extension

## Vorbereitung

Vor dem Build und Flash:

- Den korrekten seriellen Port (UART) auswählen  
  (z. B. `/dev/ttyUSB0`, `/dev/tty.SLAB_USBtoUART`, `COM3`, etc.)
- In den ESP-IDF-Einstellungen sicherstellen, dass:
  - Flash-Methode auf `UART` gesetzt ist
  - Baudrate z. B. auf `115200` eingestellt ist
- Zielchip auf `esp32c3` setzen
- Bei Nutzung der Kommandozeile sicherstellen, dass die ESP-IDF-Umgebung aktiv ist (`export.sh`)

## Build und Flash

### In Visual Studio Code

- "Set target" auf `esp32c3`
- "Build" starten
- "Flash" starten
- Seriellen Monitor öffnen

