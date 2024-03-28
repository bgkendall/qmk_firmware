#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
# include <print.h>
#endif

#include "users/bgkendall/bgk_keycommands.h"
#include "users/bgkendall/bgk_shifted_mod_tap.h"


/*****************************************************************************
 * CAPS WORD                                                                 *
 *****************************************************************************/

#ifdef CAPS_WORD_ENABLE

#ifdef VIAL_TAP_DANCE_ENTRIES
#   define G33_TAP_DANCE_ENTRIES VIAL_TAP_DANCE_ENTRIES
#else
#   define G33_TAP_DANCE_ENTRIES 32
#endif

bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode)
    {
        // Keycodes that continue Caps Word, with shift applied:
        case KC_A ... KC_Z:
        case KC_MINS:
        // The first 50% of Tap Dances will cancel Caps Word, the other half will be shifted:
        case (QK_TAP_DANCE + G33_TAP_DANCE_ENTRIES/2) ... QK_TAP_DANCE_MAX:
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

enum RGB_LAYERS
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
    RGBL_CAPSWORD,
    RGBL_CAPSLOCK,
    RGBL_POWERON
 };

uint8_t get_rgb_layer(layer_state_t state)
{

#ifdef RGBLIGHT_LAYER_KEY
    uint16_t rgb_layer_key = keymap_key_to_keycode(get_highest_layer(state),
                                                   (keypos_t)RGBLIGHT_LAYER_KEY);

    if (rgb_layer_key >= KC_A && rgb_layer_key <= KC_S)
    {
        return (uint8_t)(rgb_layer_key - KC_A + 1);
    }
#endif // RGBLIGHT_LAYER_KEY

    return 0;
}


#ifdef RGB_MATRIX_ENABLE

#include "color.h"
#include "lib/lib8tion/lib8tion.h"
#include "users/bgkendall/bgk_rgb.h"

const HSV bgk_hsv_layers[] = {
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

    [RGBL_CAPSWORD] = { HSV_VIVIDPINK },
    [RGBL_CAPSLOCK] = { HSV_RED },
    [RGBL_POWERON]  = { HSV_GREEN }
};

#define POWER_UP_HUE_STEP (1 << 1)

bool rgb_matrix_indicators_kb(void)
{
    if (!rgb_matrix_indicators_user())
    {
        return false;
    }

    static bool powering_up = true;

    uint8_t rgb_layer = RGBL_OFF;

    if (unlikely(powering_up))
    {
        HSV hsv = rgb_matrix_config.hsv;

        if (((hsv.h + POWER_UP_HUE_STEP) % 256) == bgk_hsv_layers[RGBL_POWERON].h)
        {
            powering_up = false;
        }
        else
        {
            hsv.h += POWER_UP_HUE_STEP;
            rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);

            return true;
        }
    }
    else if (host_keyboard_led_state().caps_lock)
    {
        rgb_layer = RGBL_CAPSLOCK;
    }
    else if (is_caps_word_on())
    {
        rgb_layer = RGBL_CAPSWORD;
    }
    else
    {
        rgb_layer = get_rgb_layer(layer_state);
    }

    rgb_matrix_sethsv_noeeprom(bgk_hsv_layers[rgb_layer].h,
                               bgk_hsv_layers[rgb_layer].s,
                               bgk_hsv_layers[rgb_layer].v);

    return true;
}

#endif // RGB_MATRIX_ENABLE


bool process_record_keymap(int16_t keycode, keyrecord_t* record)
{
    return bgk_process_shifted_mod_tap(keycode, record);
}


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
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(bgk_hsv_layers[RGBL_POWERON].h,
                               bgk_hsv_layers[RGBL_POWERON].s,
                               bgk_hsv_layers[RGBL_POWERON].v);
#endif

# ifdef WS2812_POWER_PIN
    setPinOutput(WS2812_POWER_PIN);
    writePinHigh(WS2812_POWER_PIN);
#endif

#ifdef RGBLIGHT_ENABLE
    // Turn off lighting:
    rgblight_disable();
#endif
}
