# ESP32-C3 – GPIO Toggle Geschwindigkeitstest

Dieser Test misst die maximale Schaltfrequenz eines GPIO-Pins durch direktes Setzen und Löschen per Low-Level-Hardwarezugriff.

## Testverhalten

- GPIO3 wird in einer Endlosschleife direkt über die Low-Level-Funktion `gpio_ll_set_level()` getoggelt
- Es entsteht ein Rechtecksignal mit sehr kurzer Periode
- Ziel ist die Bestimmung der maximalen Toggle-Frequenz des GPIOs

## Entwicklungsumgebung

- Framework: ESP-IDF (getestet mit Version 5.2.2)
- Mikrocontroller: ESP32-C3 Mini-1
- Toolchain: xtensa-esp32c3-elf
- IDE (empfohlen): Visual Studio Code mit ESP-IDF Extension

## Vorbereitung

Vor dem Build und Flash:

- Den korrekten seriellen Port (UART) auswählen  
  (z. B. `/dev/ttyUSB0`, `COM3`, etc.)
- In den ESP-IDF-Einstellungen sicherstellen, dass:
  - Flash-Methode auf `UART` gesetzt ist
  - Baudrate auf 115200 eingestellt ist
- Zielchip auf `esp32c3` setzen
- Bei Nutzung der Kommandozeile sicherstellen, dass die ESP-IDF-Umgebung aktiv ist (`export.sh`)

## Build und Flash

### In Visual Studio Code

- "Set target" auf `esp32c3`
- "Build" starten
- "Flash" starten
- Seriellen Monitor öffnen (optional, gibt nichts aus)

