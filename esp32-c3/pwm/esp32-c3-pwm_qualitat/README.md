# ESP32-C3 – PWM-Signalqualitätstest (LEDC)

Dieser Test erzeugt ein PWM-Signal mit 10 kHz auf GPIO3, um die Qualität der Signalform bei unterschiedlichen Duty-Cycles zu analysieren.

## Testverhalten

- PWM-Ausgabe über den LEDC-Treiber (Low-Speed)
- Frequenz: 10.000 Hz
- Auflösung: 10 Bit (1024 Stufen)
- Ausgang: GPIO3
- Der Duty-Cycle kann manuell über die Konstante `PWM_DUTY_PCT` angepasst werden

Beispielhafte Tastverhältnisse:
- 50 %
- 10 %
- 1 %
- 0.5 %
- 0.1 %

Die Messung erfolgt extern (z. B. mit Oszilloskop), um die Qualität und Stabilität bei kleinen Duty-Cycles zu bewerten.

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

