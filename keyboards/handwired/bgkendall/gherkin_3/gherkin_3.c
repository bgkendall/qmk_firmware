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


/****************************************************************************
 * RGB                                                                       *
 *****************************************************************************/

#ifdef RGBLIGHT_ENABLE

#include "users/bgkendall/bgk_rgb.h"


enum RGB_LAYERS
{
    RGBL_A = 0,
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

const rgblight_segment_t* const PROGMEM bgk_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
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

uint8_t get_rgb_layer(layer_state_t state)
{
    return (uint8_t)(keymap_key_to_keycode(get_highest_layer(state), (keypos_t)RGBLIGHT_LAYER_KEY) - KC_A);
}

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

#endif // RGBLIGHT_ENABLE


void keyboard_post_init_kb(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    debug_matrix = false;
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
