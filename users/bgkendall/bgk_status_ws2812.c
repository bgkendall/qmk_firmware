// © 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "bgk_status_ws2812.h"
#include "color.h"
#include "rgb_matrix.h"
#include "ws2812.h"


led_config_t g_led_config =
{
    { { 1 } },
    { { 112, 32 } },
    { LED_FLAG_INDICATOR }
};


LED_TYPE bgk_ws2812_array[RGB_MATRIX_LED_COUNT];

static void bgk_ws2812_init(void) {}

static void bgk_ws2812_flush(void)
{
    ws2812_setleds(bgk_ws2812_array, RGB_MATRIX_LED_COUNT);
}

static inline void bgk_ws2812_set_led(int i, uint8_t r, uint8_t g, uint8_t b)
{
    bgk_ws2812_array[i].r = r;
    bgk_ws2812_array[i].g = g;
    bgk_ws2812_array[i].b = b;
#    ifdef RGBW
    convert_rgb_to_rgbw(&bgk_ws2812_array[i]);
#    endif
}

static void bgk_ws2812_set_leds(uint8_t r, uint8_t g, uint8_t b)
{
    for (int i = 0; i < ARRAY_SIZE(bgk_ws2812_array); i++)
    {
        bgk_ws2812_set_led(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver =
{
    .init          = bgk_ws2812_init,
    .flush         = bgk_ws2812_flush,
    .set_color     = bgk_ws2812_set_led,
    .set_color_all = bgk_ws2812_set_leds,
};
