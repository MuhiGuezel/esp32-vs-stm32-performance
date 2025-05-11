# NUCLEO-L476RG – PWM-Signalqualitätstest (TIM2)

Dieses Projekt erzeugt ein PWM-Signal mit 10 kHz über TIM2 Channel 2, um die Signalqualität bei sehr kleinen Tastverhältnissen zu beurteilen. Das PWM-Signal wird extern per Oszilloskop analysiert.

## Testverhalten

- PWM-Frequenz: 10 kHz
- Duty-Cycle: konfigurierbar, z. B. 1 %
- Timer: TIM2, Channel 2
- Ausgangspin: PA1 (alternativ je nach Boardkonfiguration)
- Ziel: Bewertung der Signalform bei kleinen Duty-Cycles (für LED, Steuerung etc.)

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)

## .ioc-Einstellungen (wichtig)

### Clock Configuration:
- System Clock Source: PLLCLK (80 MHz aus HSI)
- TIM2-Clock: APB1 (80 MHz → durch Prescaler reduziert auf 1 MHz)

### TIM2 Einstellungen:
- Mode: PWM Generation CH2
- Prescaler: 79 (ergibt 1 MHz Timer-Takt)
- Period: 99 (ergibt 10 kHz PWM-Frequenz)
- Pulse: 1 (entspricht 1 % Duty-Cycle)
- Channel 2 aktiviert, GPIO Output auf PA1

### GPIO:
- TIM2_CH2 → Alternate Function AF1 auf PA1
- Kein Pull-Up/Down

## Projektstruktur

pwm_quality/
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
htim2.Init.Prescaler = 79;
htim2.Init.Period = 99;
sConfigOC.Pulse = 1;  // 1 % Duty-Cycle bei 10 kHz
HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

Messung

Oszilloskop an PA1 anschließen
PWM-Signal analysieren (Anstiegszeit, Flanken, Stabilität bei sehr kleiner Pulsbreite)
Ergebnisdokumentation je nach Duty-Cycle-Einstellung