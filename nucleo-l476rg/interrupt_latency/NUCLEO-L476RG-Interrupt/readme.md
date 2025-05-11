# NUCLEO-L476RG – Interrupt-Latenztest

Dieses Projekt misst die Reaktionszeit des STM32L476RG auf einen externen GPIO-Interrupt. Bei einer steigenden Flanke an PA10 wird in der ISR ein kurzer Impuls auf PB3 ausgelöst. Die Zeitdifferenz zwischen Eingangssignal und Reaktionspuls kann mit einem Oszilloskop gemessen werden.

## Testverhalten

- PA10 ist als EXTI-Interrupt-Eingang konfiguriert (steigende Flanke)
- PB3 ist ein GPIO-Ausgang, der in der ISR kurz gesetzt und direkt wieder gelöscht wird
- Der Test dient der Bestimmung der Interrupt-Latenz über externen Trigger

## Entwicklungsumgebung

- IDE: STM32CubeIDE
- HAL-Treiber: STM32CubeL4
- Mikrocontroller: STM32L476RG (NUCLEO-Board)

## .ioc-Einstellungen (wichtig)

### Clock Configuration:
- System Clock: 80 MHz über PLL (aus HSI)

### GPIO:
- PA10: GPIO_MODE_IT_RISING, kein Pull
- PB3: GPIO Output, Push-Pull, High Speed
- EXTI15_10_IRQn: aktiviert, Priority = 0

### NVIC:
- Interrupts aktiviert für EXTI15_10_IRQn

### USART2:
- Optional aktiviert, nicht notwendig für diesen Test

## Projektstruktur

interrupt_latency/
├── Core/
│ ├── Inc/
│ │ └── main.h
│ └── Src/
│ └── main.c
├── Drivers/
├── .ioc (CubeMX-Konfiguration)
├── .project / .cproject
└── README.md


## Codeausschnitt (ISR)

```c
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_10)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    }
}

Messaufbau

PA10 (D2): mit externer Signalquelle verbinden (z. B. Rechteckgenerator)
PB3 (D3): an Oszilloskop anschließen
Latenzzeit = Zeit zwischen steigender Flanke an PA10 und dem Puls auf PB3
