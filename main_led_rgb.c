#include "led_strip.h"

#define BLINK_GPIO 8

static led_strip_handle_t led_strip;

void configurar_led(void) {
    led_strip_config_t strip_config = {
        .strip_gpio_num = BLINK_GPIO,
        .max_leds = 1,
    };

    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000,
    };

    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

    led_strip_clear(led_strip);
}

void controlar_led_rgb(uint8_t comando) {
    if (comando == 1) {
        led_strip_set_pixel(led_strip, 0, 0, 0, 50);
        led_strip_refresh(led_strip);
    } else if (comando == 2) {
        led_strip_set_pixel(led_strip, 0, 0, 50, 0);
        led_strip_refresh(led_strip);
    } else if (comando == 3) {
        led_strip_set_pixel(led_strip, 0, 50, 0, 0);
        led_strip_refresh(led_strip);
    } else {
        led_strip_clear(led_strip);
    }
}
