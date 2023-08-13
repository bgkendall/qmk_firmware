#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
# include <print.h>
#endif

#include "users/bgkendall/bgk_keycommands.h"


/*****************************************************************************
 * CAPS WORD                                                                 *
 *****************************************************************************/

#ifdef CAPS_WORD_ENABLE

bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode)
    {
        // Keycodes that continue Caps Word, with shift applied:
        case KC_A ... KC_Z:
        case KC_MINS:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key
            return true;

        // Keycodes that continue Caps Word, without shifting:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word
    }
}

#endif // CAPS_WORD_ENABLE


/*****************************************************************************
 * RGB                                                                       *
 *****************************************************************************/

enum RGBS
{
    RGBL_OFF = 0,
    RGBL_A,
    RGBL_B,
    RGBL_C,
    RGBL_D,
    RGBL_E,
    RGBL_F,
    RGBL_G,
    RGBL_H,
    RGBL_I,
    RGBL_J,
    RGBL_K,
    RGBL_L,
    RGBL_M,
    RGBL_N,
    RGBL_O,
    RGBL_P,
    RGBL_Q,
    RGBL_R,
    RGBL_S,
    RGBL_CAPW,
    RGBL_CAPL,
    RGBL_OK
 };

uint8_t get_rgb_layer(layer_state_t state)
{

#ifdef RGBLIGHT_LAYER_KEY
    uint16_t rgb_layer_key = keymap_key_to_keycode(get_highest_layer(state),
                                                   (keypos_t)RGBLIGHT_LAYER_KEY);
printf("State: %i", state);
printf(", key: %i\n", rgb_layer_key);

    if (rgb_layer_key >= KC_A && rgb_layer_key <= KC_S)
    {
        return (uint8_t)(rgb_layer_key - KC_A + 1);
    }
#endif // RGBLIGHT_LAYER_KEY

    return 0;
}


#ifdef RGB_MATRIX_ENABLE

#include "color.h"
#include "users/bgkendall/bgk_rgb.h"

const HSV bgk_rgb_layers[] = {
    [RGBL_OFF] = { HSV_BLACK },

    [RGBL_F] = { HSV_WHITE },
    [RGBL_R] = { HSV_RED },
    [RGBL_K] = { HSV_CORAL },
    [RGBL_J] = { HSV_ORANGERED },
    [RGBL_O] = { HSV_ORANGE },
    [RGBL_N] = { HSV_GOLDENROD },
    [RGBL_D] = { HSV_GOLD },
    [RGBL_L] = { HSV_YELLOW },
    [RGBL_H] = { HSV_CHARTREUSE },
    [RGBL_G] = { HSV_GREEN },
    [RGBL_S] = { HSV_SPRINGGREEN },
    [RGBL_Q] = { HSV_TURQUOISE },
    [RGBL_E] = { HSV_TEAL },
    [RGBL_C] = { HSV_CYAN },
    [RGBL_A] = { HSV_AZURE },
    [RGBL_B] = { HSV_BLUE },
    [RGBL_I] = { HSV_PURPLE },
    [RGBL_M] = { HSV_MAGENTA },
    [RGBL_P] = { HSV_PINK },

    [RGBL_CAPW] = { HSV_VIVIDPINK },
    [RGBL_CAPL] = { HSV_RED },
    [RGBL_OK]   = { HSV_GREEN }
};

bool rgb_matrix_indicators_kb(void)
{
    if (!rgb_matrix_indicators_user())
    {
        return false;
    }

    uint8_t rgb_layer = RGBL_OFF;

    if (host_keyboard_led_state().caps_lock)
    {
        rgb_layer = RGBL_CAPL;
    }
    else if (is_caps_word_on())
    {
        rgb_layer = RGBL_CAPW;
    }
    else
    {
        rgb_layer = get_rgb_layer(layer_state);
    }

    rgb_matrix_sethsv_noeeprom(bgk_rgb_layers[rgb_layer].h,
                               bgk_rgb_layers[rgb_layer].s,
                               bgk_rgb_layers[rgb_layer].v);

    return true;
}

#elifdef RGBLIGHT_ENABLE

#include "users/bgkendall/bgk_rgb.h"

const rgblight_segment_t* const PROGMEM bgk_rgb_layers[] = RGBLIGHTS_LIST
(
    [RGBL_OFF] = bgkrgb_black_layer,

    [RGBL_F] = bgkrgb_white_layer,
    [RGBL_R] = bgkrgb_red_layer,
    [RGBL_K] = bgkrgb_coral_layer,
    [RGBL_J] = bgkrgb_orangered_layer,
    [RGBL_O] = bgkrgb_orange_layer,
    [RGBL_N] = bgkrgb_goldenrod_layer,
    [RGBL_D] = bgkrgb_gold_layer,
    [RGBL_L] = bgkrgb_yellow_layer,
    [RGBL_H] = bgkrgb_chartreuse_layer,
    [RGBL_G] = bgkrgb_green_layer,
    [RGBL_S] = bgkrgb_springgreen_layer,
    [RGBL_Q] = bgkrgb_turquoise_layer,
    [RGBL_E] = bgkrgb_teal_layer,
    [RGBL_C] = bgkrgb_cyan_layer,
    [RGBL_A] = bgkrgb_azure_layer,
    [RGBL_B] = bgkrgb_blue_layer,
    [RGBL_I] = bgkrgb_purple_layer,
    [RGBL_M] = bgkrgb_magenta_layer,
    [RGBL_P] = bgkrgb_pink_layer,

    [RGBL_CAPW] = bgkrgb_vividpink_layer,
    [RGBL_CAPL] = bgkrgb_red_layer,
    [RGBL_OK]   = bgkrgb_green_layer
);


layer_state_t layer_state_set_kb(layer_state_t state)
{
    bgkrgb_set_all_layers(get_rgb_layer(state), RGBL_A, RGBL_S);

    return layer_state_set_user(state);
}

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPL, led_state.caps_lock);

    return true;
}

void caps_word_set_user(bool active)
{
    rgblight_set_layer_state(RGBL_CAPW, active);
}

#endif // RGB_MATRIX_ENABLE / RGBLIGHT_ENABLE


void keyboard_post_init_kb(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    debug_matrix = false;
    debug_keyboard = false;
    debug_mouse = false;
#endif

#ifdef RGB_MATRIX_ENABLE

# ifdef RGBLIGHT_POWER_PIN
    setPinOutput(RGBLIGHT_POWER_PIN);
    writePinHigh(RGBLIGHT_POWER_PIN);
    // TODO: Only enable the pin when the light is needed?
# endif

    rgb_matrix_enable_noeeprom();
#endif

#ifdef RGBLIGHT_ENABLE

# ifdef RGBLIGHT_POWER_PIN
    setPinOutput(RGBLIGHT_POWER_PIN);
    writePinHigh(RGBLIGHT_POWER_PIN);
    // TODO: Only enable the pin when the light is needed?
# endif

    // Enable the LED layers:
    rgblight_layers = bgk_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer_repeat(RGBL_OK, 333, 3);

#endif // RGBLIGHT_ENABLE

}
