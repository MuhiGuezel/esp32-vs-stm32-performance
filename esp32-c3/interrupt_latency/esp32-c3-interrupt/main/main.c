/**
 * @file main.c
 * @brief Interrupt-Latenztest für ESP32-C3
 *
 * Dieses Programm misst die Latenzzeit zwischen einem steigenden Signal an GPIO2
 * und einer Reaktion an GPIO3. Beim Auftreten einer Flanke auf dem Eingangspin wird
 * in der ISR sofort ein Impuls auf dem Ausgangspin erzeugt.
 *
 * Ziel ist es, die Verzögerung zwischen Ereignis und Reaktion mithilfe eines
 * Oszilloskops messbar zu machen.
 *
 * Eingang: GPIO2 (Pull-up aktiviert, reagiert auf steigende Flanke)  
 * Ausgang: GPIO3 (kurzer High-Puls innerhalb der ISR)
 *
 * Verwendete ESP-IDF Version: 5.2.2  
 * Mikrocontroller: ESP32-C3 Mini-1  
 * Autor: Muhammed Güzel  
 * Datum: Mai 2025
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"

#define INPUT_GPIO  GPIO_NUM_2
#define OUTPUT_GPIO GPIO_NUM_3

void IRAM_ATTR gpio_isr_handler(void* arg) {
    gpio_set_level(OUTPUT_GPIO, 1);
    gpio_set_level(OUTPUT_GPIO, 0);
}

void app_main(void) {
    // Konfiguration des Eingangspins
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_POSEDGE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = 1ULL << INPUT_GPIO,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&io_conf));

    // Ausgangspin vorbereiten
    gpio_set_direction(OUTPUT_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(OUTPUT_GPIO, 0);

    // ISR-Service aktivieren und Handler registrieren
    ESP_ERROR_CHECK(gpio_install_isr_service(0));
    ESP_ERROR_CHECK(gpio_isr_handler_add(INPUT_GPIO, gpio_isr_handler, NULL));
}
