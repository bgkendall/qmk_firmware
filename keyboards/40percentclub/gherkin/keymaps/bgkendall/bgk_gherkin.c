#include "bgk_encoder.h"
#include "bgk_rgb.h"


enum LAYERS
{
    KL_COLEMAK = 0,
    KL_QWERTY,
    KL_NUMBER,
    KL_SYMBOL_CM,
    KL_SYMBOL_QW,
    KL_NAVIGATION,
    KL_FUNCTION,
    KL_META,
    RGBL_OK,
    RGBL_CAPS
};

const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_COLEMAK...KL_QWERTY]      = { { KC_LEFT,    KC_RGHT   } },
    [KL_NUMBER]                   = { { KC_BRID,    KC_BRIU   } },
    [KL_SYMBOL_CM...KL_SYMBOL_QW] = { { KC_VOLD,    KC_VOLU   } },
    [KL_NAVIGATION]               = { { KC_WH_U,    KC_WH_D   } }, // Flipped *back* for trad. scrolling
    [KL_FUNCTION]                 = { { G(KC_MINS), G(KC_EQL) } },
    [KL_META]                     = { { BL_DEC,     BL_INC    } }
};

const rgblight_segment_t PROGMEM gherkin_red_green_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {0, 1, HSV_RED}, {1, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM bgk_gherkin_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [KL_COLEMAK...KL_QWERTY]      = bgkrgb_white_layer,
    [KL_NUMBER]                   = bgkrgb_springgreen_layer,
    [KL_SYMBOL_CM...KL_SYMBOL_QW] = bgkrgb_magenta_layer,
    [KL_NAVIGATION]               = bgkrgb_blue_layer,
    [KL_FUNCTION]                 = bgkrgb_orange_layer,
    [KL_META]                     = bgkrgb_white_layer,
    [RGBL_OK]                     = bgkrgb_green_layer,
    [RGBL_CAPS]                   = bgkrgb_red_indicator_layer
);

layer_state_t layer_state_set_user(layer_state_t state)
{
    bgkrgb_set_from_highest_layer(state, KL_NUMBER, KL_FUNCTION);

    if (get_highest_layer(state) == KL_META)
    {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD+2);
    }
    else
    {
        rgblight_disable();
    }

    return state;
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);

    return true;
}

void keyboard_post_init_user(void)
{
    // Enable/disable debugging (requires CONSOLE_ENABLE = yes in rules.mk):
    debug_enable = false;
    debug_matrix = false;

    // Turn off lighting:
    backlight_disable();
    rgblight_disable();

    // Enable the LED layers:
    rgblight_layers = bgk_gherkin_rgb_layers;

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1000);
}
