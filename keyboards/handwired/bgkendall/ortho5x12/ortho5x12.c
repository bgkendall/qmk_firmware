#include "ortho5x12.h"

#include "bgk_rgb.h"

#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

const rgblight_segment_t PROGMEM ortho_5_12_ok_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    BGKRGB_RAINBOW_PIXEL(0),
    BGKRGB_RAINBOW_PIXEL(1),
    BGKRGB_RAINBOW_PIXEL(2),
    BGKRGB_RAINBOW_PIXEL(3),
    BGKRGB_RAINBOW_PIXEL(4),
    BGKRGB_RAINBOW_PIXEL(5),
    BGKRGB_RAINBOW_PIXEL(6),
    BGKRGB_RAINBOW_PIXEL(7),
    BGKRGB_RAINBOW_PIXEL(8),
    BGKRGB_RAINBOW_PIXEL(9),
    BGKRGB_RAINBOW_PIXEL(10)
);

const rgblight_segment_t PROGMEM ortho_5_12_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {0, 1, HSV_RED}, {RGBLED_NUM-1, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM ortho_5_12_rgb_layers[RGBLIGHT_MAX_LAYERS] = RGBLIGHT_LAYERS_LIST
(
    [KL_DEF]    = bgkrgb_white_indicator_layer,
    [KL_DEF1]   = bgkrgb_coral_indicator_layer,
    [KL_DEF2]   = bgkrgb_chartreuse_indicator_layer,
    [KL_DEF3]   = bgkrgb_cyan_indicator_layer,
    [KL_DEF4]   = bgkrgb_magenta_indicator_layer,
    [KL_NUM]    = bgkrgb_springgreen_indicator_layer,
    [KL_NP]     = bgkrgb_blue_indicator_layer,
    [KL_FN]     = bgkrgb_orange_indicator_layer,
    [KL_FN1]    = bgkrgb_orange_indicator_layer,
    [KL_FN2]    = bgkrgb_magenta_indicator_layer,
    [KL_META]   = bgkrgb_purple_indicator_layer,
    [RGBL_OK]   = ortho_5_12_ok_layer,
    [RGBL_CAPS] = ortho_5_12_caps_layer
);

void keyboard_post_init_kb(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    debug_matrix = true;
#endif

    // Enable the LED layers:
    rgblight_layers = ortho_5_12_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1800);
}

layer_state_t layer_state_set_kb(layer_state_t state)
{
    if (get_highest_layer(state) <= KL_META)
    {
        // bgkrgb_set_from_highest_layer(state, KL_DEF4+1, KL_META);
        bgkrgb_blink_highest_layer(state, KL_DEF4+1, KL_META);
    }

    return state;
}

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}
