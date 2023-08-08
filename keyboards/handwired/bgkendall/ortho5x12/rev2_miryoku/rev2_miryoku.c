#include "rev2m.h"

#include "manna-harbour_miryoku.h"


/*****************************************************************************
 * ENCODER                                                                   *
 *****************************************************************************/

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [U_BASE]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
    [U_EXTRA]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
    [U_TAP]     = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },
    [U_BUTTON]  = { ENCODER_CCW_CW(LGUI(KC_MINS), LGUI(KC_EQL)) },
    [U_NAV]     = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP)  },
    [U_MOUSE]   = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  },
    [U_MEDIA]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [U_NUM]     = { ENCODER_CCW_CW(KC_DOWN, KC_UP)    },
    [U_SYM]     = { ENCODER_CCW_CW(KC_DOWN, KC_UP)    },
    [U_FUN]     = { ENCODER_CCW_CW(KC_BRID, KC_BRIU)  }
};

#endif // ENCODER_MAP_ENABLE


/*****************************************************************************
 * RGB                                                                       *
 *****************************************************************************/

#ifdef RGBLIGHT_ENABLE

#include "users/bgkendall/bgk_rgb.h"

enum RGB_ONLY_LAYERS
{
    RGBL_CAPW = (U_FUN+1),
    RGBL_CAPL,
    RGBL_OK
};


const rgblight_segment_t* const PROGMEM bgk_ortho5x12_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [U_BASE]    = bgkrgb_white_indicator_layer,
    [U_EXTRA]   = bgkrgb_goldenrod_indicator_layer,
    [U_TAP]     = bgkrgb_red_indicator_layer,
    [U_BUTTON]  = bgkrgb_purple_indicator_layer,
    [U_NAV]     = bgkrgb_cyan_indicator_layer,
    [U_MOUSE]   = bgkrgb_yellow_indicator_layer,
    [U_MEDIA]   = bgkrgb_magenta_indicator_layer,
    [U_NUM]     = bgkrgb_blue_indicator_layer,
    [U_SYM]     = bgkrgb_green_indicator_layer,
    [U_FUN]     = bgkrgb_orangered_indicator_layer,
    [RGBL_CAPW] = bgkrgb_vividpink_indicator_layer,
    [RGBL_CAPL] = bgkrgb_red_indicator_layer,
    [RGBL_OK]   = bgkrgb_green_indicator_layer
);

layer_state_t default_layer_state_set_kb(layer_state_t state)
{
    rgblight_blink_layer(get_highest_layer(state), BGKRGB_BLINK_TIME);

    return default_layer_state_set_user(state);
}

layer_state_t layer_state_set_kb(layer_state_t state)
{
    if (get_highest_layer(state) == U_MEDIA)
    {
        // Media layer has RGB underglow controls, so only blink layer
        // indicator so that the lighting being selected can be seen clearly:
        bgkrgb_set_from_layers(0, U_BUTTON, U_FUN);
        rgblight_blink_layer(U_MEDIA, BGKRGB_BLINK_TIME);
    }
    else
    {
        bgkrgb_set_from_layers(state, U_BUTTON, U_FUN);
    }

    return layer_state_set_user(state);
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPL, led_state.caps_lock);

    return true;
}

void caps_word_set_user(bool active)
{
    rgblight_set_layer_state(RGBL_CAPW, active);
}

#endif // RGBLIGHT_ENABLE



/*****************************************************************************
 * KEYBOARD INIT                                                             *
 *****************************************************************************/

void keyboard_post_init_user(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
#endif

#ifdef BACKLIGHT_ENABLE

    // Turn off lighting:
    backlight_disable();

#endif // BACKLIGHT_ENABLE

#ifdef RGBLIGHT_ENABLE

    rgblight_disable();

    // Enable the LED layers:
    rgblight_layers = bgk_ortho5x12_rgb_layers;

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, BGKRGB_BLINK_TIME);

#endif // RGBLIGHT_ENABLE
}
