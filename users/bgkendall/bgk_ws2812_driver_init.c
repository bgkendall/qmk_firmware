// © 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "bgk_ws2812_driver.h"
#include "color.h"
#include "gpio.h"
#include "rgb_matrix.h"


rgb_led_t bgk_ws2812_matrix[RGB_MATRIX_LED_COUNT];

static void bgk_ws2812_matrix_init(void)
{
#ifdef BGK_CUSTOM_WS2812_POWER_PIN
    setPinOutput(BGK_CUSTOM_WS2812_POWER_PIN);
    writePinHigh(BGK_CUSTOM_WS2812_POWER_PIN);
#endif
}

static void bgk_ws2812_matrix_flush(void)
{
    bgk_ws2812_set_leds(bgk_ws2812_matrix, RGB_MATRIX_LED_COUNT);
}

static inline void bgk_ws2812_matrix_set_led(int i, uint8_t r, uint8_t g, uint8_t b)
{
    bgk_ws2812_matrix[i].r = r;
    bgk_ws2812_matrix[i].g = g;
    bgk_ws2812_matrix[i].b = b;
#    ifdef RGBW
    convert_rgb_to_rgbw(&bgk_ws2812_matrix[i]);
#    endif
}

static void bgk_ws2812_matrix_set_leds(uint8_t r, uint8_t g, uint8_t b)
{
    for (int i = 0; i < ARRAY_SIZE(bgk_ws2812_matrix); i++)
    {
        bgk_ws2812_matrix_set_led(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver =
{
    .init          = bgk_ws2812_matrix_init,
    .flush         = bgk_ws2812_matrix_flush,
    .set_color     = bgk_ws2812_matrix_set_led,
    .set_color_all = bgk_ws2812_matrix_set_leds,
};
