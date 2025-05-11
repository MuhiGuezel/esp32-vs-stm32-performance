# ESP32-C3 – Interrupt-Latenztest

Dieser Test misst die Interrupt-Reaktionszeit des ESP32-C3 auf einen externen Trigger über GPIO. Die Latenz wird über ein Oszilloskop anhand des Unterschieds zwischen Eingangs- und Ausgangsflanke gemessen.

## Testverhalten

- GPIO2 wird als Eingang mit Pull-up konfiguriert, reagiert auf eine steigende Flanke
- GPIO3 wird als Ausgang verwendet
- Beim Eintreffen der Flanke auf GPIO2 wird in der ISR ein kurzer Puls auf GPIO3 erzeugt
- Die Zeitdifferenz zwischen Eingangsflanke und Reaktionspuls entspricht der Interrupt-Latenz

## Entwicklungsumgebung

- Framework: ESP-IDF (getestet mit Version 5.2.2)
- Mikrocontroller: ESP32-C3 Mini-1
- Toolchain: xtensa-esp32c3-elf
- IDE: Visual Studio Code mit ESP-IDF Extension

## Vorbereitung

Vor dem Build und Flash:

- Den seriellen Port auswählen (z. B. `/dev/ttyUSB0`, `COM3`)
- Flash-Methode: UART
- Baudrate: 115200 (Standard)
- Zielchip: esp32c3

## Build und Flash

### In Visual Studio Code

- "Set target" auf `esp32c3`
- "Build" ausführen
- "Flash" starten

