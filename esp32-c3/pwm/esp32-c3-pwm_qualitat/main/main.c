/**
 * @file main.c
 * @brief PWM-Signalqualitätstest für ESP32-C3
 *
 * Dieses Programm erzeugt ein PWM-Signal mit 10 kHz auf GPIO3 und
 * variabler Tastverhältnis-Einstellung, um die Signalqualität bei kleinen
 * Duty-Cycles zu untersuchen. Das PWM-Signal wird über den LEDC-Treiber
 * des ESP32-C3 erzeugt.
 *
 * Frequenz: 10 kHz
 * Auflösung: 10 Bit (0–1023)
 * Duty-Cycle-Vorgaben: z. B. 50 %, 10 %, 1 %, 0.5 %, 0.1 % (manuell anpassbar)
 *
 * Verwendete ESP-IDF Version: 5.2.2
 * Mikrocontroller: ESP32-C3 Mini-1
 * Autor: Muhammed Güzel
 * Datum: Mai 2025
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define PWM_GPIO        GPIO_NUM_3
#define PWM_FREQ_HZ     10000        // 10 kHz
#define PWM_DUTY_PCT  1   // Erst 50%, dann 10%, dann 1%, dann 0.5% und 0.1 % 
#define PWM_RESOLUTION  LEDC_TIMER_10_BIT  // Auflösung: 0–1023

void app_main(void) {
    // Timer konfigurieren
    ledc_timer_config_t pwm_timer = {
        .speed_mode       = LEDC_LOW_SPEED_MODE,
        .timer_num        = LEDC_TIMER_0,
        .duty_resolution  = PWM_RESOLUTION,
        .freq_hz          = PWM_FREQ_HZ,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&pwm_timer);

    // PWM-Kanal konfigurieren
    ledc_channel_config_t pwm_channel = {
        .speed_mode     = LEDC_LOW_SPEED_MODE,
        .channel        = LEDC_CHANNEL_0,
        .timer_sel      = LEDC_TIMER_0,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = PWM_GPIO,
        .duty           = (1023 * PWM_DUTY_PCT) / 100,
        .hpoint         = 0
    };
    ledc_channel_config(&pwm_channel);
}
