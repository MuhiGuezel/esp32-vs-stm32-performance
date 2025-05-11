# NUCLEO-L476RG – GPIO Toggle Geschwindigkeitstest

Dieses Projekt misst die maximale Schaltfrequenz eines GPIO-Pins am STM32L476RG, indem in einer Endlosschleife der Pin PA5 kontinuierlich gesetzt und zurückgesetzt wird.

## Testverhalten

- Pin PA5 (LED oder externer Ausgang) wird schnell getoggelt
- Umschaltung erfolgt über HAL_GPIO_WritePin()
- Rechtecksignal wird über Oszilloskop vermessen
- Ziel: Ermittlung der maximalen Toggle-Frequenz mit HAL

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)
- Debug: deaktiviert (für reale Messung)

## .ioc-Einstellungen (wichtig)

### Clock Configuration:
- System Clock: 80 MHz über PLL (aus HSI)
- AHB/APB1/APB2: kein Divider (alle auf voller Geschwindigkeit)

### GPIO:
- PA5 als Output Push-Pull
- Speed: Very High
- Kein Pull-Up/Pull-Down

### USART2:
- Optional aktiviert, hat aber keinen Einfluss auf den Test

## Projektstruktur

gpio_toggle_speed/
├── Core/
│ ├── Inc/
│ │ └── main.h
│ └── Src/
│ └── main.c
├── Drivers/
├── .ioc (CubeMX-Konfiguration)
├── .project / .cproject
└── README.md


## Codeausschnitt

```c
while (1) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

Messung

Pin PA5 an Oszilloskop anschließen
Frequenz und Signalform analysieren
Erwartete Frequenz: einige hundert kHz mit HAL (für mehr: LL oder direkte Registerzugriffe nötig)