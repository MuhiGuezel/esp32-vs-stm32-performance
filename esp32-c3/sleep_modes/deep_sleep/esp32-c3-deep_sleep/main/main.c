/**
 * @file main.c
 * @brief Deep Sleep Stromverbrauchstest für ESP32-C3
 *
 * Dieses Programm versetzt den ESP32-C3 in den Deep-Sleep-Modus mit Wakeup
 * über den internen RTC-Timer nach 10 Sekunden. Vor dem Eintritt in den
 * Sleep-Modus werden alle verfügbaren GPIOs auf Eingänge mit Pulldown gesetzt
 * und per gpio_hold eingefroren, um Leckströme zu minimieren.
 *
 * Beim Neustart wird der Reset-Grund ausgegeben.
 *
 * Verwendete ESP-IDF Version: 5.2.2
 * Mikrocontroller: ESP32-C3 Mini-1
 * Autor: Muhammed Güzel
 * Datum: Mai 2025
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_sleep.h"
#include "esp_system.h"

void app_main(void)
{
    esp_reset_reason_t reason = esp_reset_reason();
    printf("Reset-Grund: %d\n", reason);

    gpio_num_t valid_gpios[] = {
        GPIO_NUM_0, GPIO_NUM_1, GPIO_NUM_2, GPIO_NUM_3, GPIO_NUM_4,
        GPIO_NUM_5, GPIO_NUM_6, GPIO_NUM_7, GPIO_NUM_8, GPIO_NUM_9,
        GPIO_NUM_10, GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_20
    };

    for (int i = 0; i < sizeof(valid_gpios)/sizeof(valid_gpios[0]); i++) {
        gpio_num_t pin = valid_gpios[i];

        gpio_reset_pin(pin);
        gpio_set_direction(pin, GPIO_MODE_INPUT);
        gpio_pulldown_en(pin);
        gpio_pullup_dis(pin);

        gpio_sleep_sel_en(pin);
        gpio_hold_en(pin);  // Freeze Zustand im Deep Sleep
    }

    // Nur Timer-Wakeup aktivieren
    esp_sleep_enable_timer_wakeup(10 * 1000000);

    printf("→ Gehe jetzt in Deep Sleep...\n");
    fflush(stdout);

    esp_deep_sleep_start();
}
