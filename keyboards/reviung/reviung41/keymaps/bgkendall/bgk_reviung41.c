
#include QMK_KEYBOARD_H



/*****************************************************************************
 * RGB                                                                       *
 *****************************************************************************/

#ifdef RGBLIGHT_ENABLE

#include "users/bgkendall/bgk_rgb.h"
#include "users/bgkendall/bgk_shifted_mod_tap.h"


// enum RGB_LAYERS
// {
//     RGBL_CAPW = DYNAMIC_KEYMAP_LAYER_COUNT,
//     RGBL_CAPL,
//     RGBL_PROG,
//     RGBL_OK
// };
//
// const rgblight_segment_t* const PROGMEM bgk_rgb_layers[] = RGBLIGHT_LAYERS_LIST
// (
//     [0]         = bgkrgb_black_indicator_layer,
//     [1]         = bgkrgb_red_layer, //bgkrgb_black_indicator_layer,
//     [2]         = bgkrgb_green_layer, //bgkrgb_orangered_indicator_layer,
//     [3]         = bgkrgb_blue_layer, //bgkrgb_black_indicator_layer,
//     [4]         = bgkrgb_green_indicator_layer,
//     [5]         = bgkrgb_teal_indicator_layer,
//     [6]         = bgkrgb_magenta_indicator_layer,
//     [RGBL_CAPW] = bgkrgb_vividpink_indicator_layer,
//     [RGBL_CAPL] = bgkrgb_red_indicator_layer,
//     [RGBL_PROG] = bgkrgb_purple_indicator_layer,
//     [RGBL_OK]   = bgkrgb_green_layer
// );
//
// layer_state_t layer_state_set_kb(layer_state_t new_state)
// {
// //     layer_state_t new_layer = get_highest_layer(new_state);
// //     layer_state_t old_layer = get_highest_layer(layer_state);
// //
// //     if (new_layer > old_layer)
// //     {
// //         rgblight_set_layer_state(new_layer, true);
// //     }
// //     else if (old_layer > 0)
// //     {
// //         rgblight_set_layer_state(old_layer, false);
// //     }
//
//     bgkrgb_set_all_layers(get_highest_layer(new_state), 0, 6);
//
// //    bgkrgb_set_from_highest_layer(new_state, 0, 6);
//
//     return layer_state_set_user(new_state);
// }

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
    RGBL_PROG,
    RGBL_OK
};

const rgblight_segment_t* const PROGMEM bgk_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [RGBL_F] = bgkrgb_white_indicator_layer,
    [RGBL_R] = bgkrgb_red_indicator_layer,
    [RGBL_K] = bgkrgb_coral_indicator_layer,
    [RGBL_J] = bgkrgb_orangered_indicator_layer,
    [RGBL_O] = bgkrgb_orange_indicator_layer,
    [RGBL_N] = bgkrgb_goldenrod_indicator_layer,
    [RGBL_D] = bgkrgb_gold_indicator_layer,
    [RGBL_L] = bgkrgb_yellow_indicator_layer,
    [RGBL_H] = bgkrgb_chartreuse_indicator_layer,
    [RGBL_G] = bgkrgb_green_indicator_layer,
    [RGBL_S] = bgkrgb_springgreen_indicator_layer,
    [RGBL_Q] = bgkrgb_turquoise_indicator_layer,
    [RGBL_E] = bgkrgb_teal_indicator_layer,
    [RGBL_C] = bgkrgb_cyan_indicator_layer,
    [RGBL_A] = bgkrgb_azure_indicator_layer,
    [RGBL_B] = bgkrgb_blue_indicator_layer,
    [RGBL_I] = bgkrgb_purple_indicator_layer,
    [RGBL_M] = bgkrgb_magenta_indicator_layer,
    [RGBL_P] = bgkrgb_pink_indicator_layer,

    [RGBL_CAPW] = bgkrgb_vividpink_indicator_layer,
    [RGBL_CAPL] = bgkrgb_red_indicator_layer,
    [RGBL_PROG] = bgkrgb_purple_indicator_layer,
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



layer_state_t default_layer_state_set_kb(layer_state_t new_state)
{
    // rgblight_blink_layer(get_highest_layer(new_state), BGKRGB_BLINK_TIME);

    return default_layer_state_set_user(new_state);
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



/*****************************************************************************
 * KEY CODE HANDLING                                                         *
 *****************************************************************************/

int16_t td_semicolon = KC_NO;
int16_t td_dot_colon = KC_NO;

const int16_t dot_colon_overrides[][3] =
{
   // Key 1  Key 2          Cancelled by
    { KC_C,  KC_D,          KC_SPACE },
    { KC_C,  KC_P,          KC_NO    },
    { KC_M,  KC_V,          KC_NO    },
    { KC_R,  KC_M,          KC_NO    },
    { KC_P,  KC_4,          KC_NO    },
    { KC_NO, KC_NO,         KC_NO    }  // List terminator
};

int16_t dot_colon_override_state[] =
{
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO
};

bool is_dot_colon_override(uint8_t override, int16_t keycode)
{
    bool isOverride = false;

    if (keycode == dot_colon_overrides[override][0] &&
        dot_colon_override_state[override] == KC_NO)
    {
        dot_colon_override_state[override] = keycode;
    }
    else if (keycode == dot_colon_overrides[override][1] &&
             dot_colon_override_state[override] == dot_colon_overrides[override][0])
    {
        dot_colon_override_state[override] = keycode;
    }
    else if (keycode == KC_SPACE &&
             dot_colon_override_state[override] == dot_colon_overrides[override][1])
    {
        dot_colon_override_state[override] = keycode;
    }
    else if (keycode == td_dot_colon && dot_colon_override_state[override] == KC_SPACE)
    {
        isOverride = true;
    }
    // else if (keycode == dot_colon_overrides[override][2] ||
    //          keycode == KC_SCOLON ||
    //          keycode == td_semicolon ||
    //          keycode == KC_ENTER ||
    //          keycode == KC_KP_ENTER ||
    //          keycode == KC_ESCAPE)
    // {
    //     // Special keys will reset behaviour:
    //     dot_colon_override_state[override] = KC_NO;
    // }
    else if (dot_colon_override_state[override] == dot_colon_overrides[override][0] ||
             dot_colon_override_state[override] == dot_colon_overrides[override][1] )
    {
        // key1, key2, <space> is not consecutive:
        dot_colon_override_state[override] = KC_NO;
    }

    return isOverride;
}

bool override_dotcolon(int16_t keycode, keyrecord_t* record)
{
    bool process = true;

    if (record->event.pressed)
    {
        if ((keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) ||
            (keycode >= QK_MODS      && keycode <= QK_MODS_MAX)      ||
            (keycode >= QK_MOD_TAP   && keycode <= QK_MOD_TAP_MAX)   )
        {
            keycode &= QK_BASIC_MAX;
        }

        bool isOverride = false;

        for (uint8_t o = 0; dot_colon_overrides[o][0] != KC_NO; o++)
        {
            // is_dot_colon_override() must be called for every override,
            // so do not exit loop early

            isOverride |= is_dot_colon_override(o, keycode);
        }

        if (isOverride)
        {
            tap_code(KC_DOT);
            process = false;
        }
    }

    return process;
}

bool process_programmable_key(int16_t keycode, keyrecord_t* record)
{
    bool process = true;

    // The programmable key must be in the basic key code range to work with,
    // for example, Mod-Taps; we cannot use keys like USER00
    const  int16_t programableKey = KC_WWW_FAVORITES;
    const  int16_t programmingKey = KC_WWW_REFRESH;
    static int16_t overrideKey    = KC_DOLLAR;
    static bool    isProgramming  = false;

    int16_t base_keycode = keycode;

    if (IS_QK_MODS(keycode)    ||
        IS_QK_MOD_TAP(keycode) ||
        IS_QK_LAYER_TAP(keycode))
    {
        base_keycode &= QK_BASIC_MAX;
    }

    if (!isProgramming &&
        (keycode == programableKey ||
         (record->tap.count > 0 && base_keycode == programableKey)))
    {
        if (!process_key_override(keycode, record))
        {
            // Key Override triggered - do not send the programmed key
        }
        else if (record->event.pressed)
        {
            register_code16(overrideKey);
        }
        else
        {
            unregister_code16(overrideKey);
        }
        process = false;
    }
    else if (record->event.pressed &&
             (keycode == programmingKey || (record->tap.count == 1 && base_keycode == programmingKey) ||
              keycode == programableKey || (record->tap.count == 1 && base_keycode == programableKey)))
    {
        isProgramming = !isProgramming;
        rgblight_set_layer_state(RGBL_PROG, isProgramming);
        process = false;
    }
    else if (isProgramming &&
             record->event.pressed &&
             (keycode <= QK_MODS_MAX || IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) &&
             !IS_MODIFIER_KEYCODE(keycode))
             // TODO: Use record->tap.count to only trigger on tap NOT hold?
    {
        if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode))
        {
            // keycode includes mod/layer tap data that we want to exclude:
            overrideKey = ((get_mods()<<8) | base_keycode);
        }
        else
        {
            // keycode may include modifiers that we want to keep:
            overrideKey = ((get_mods()<<8) | keycode);
        }
        isProgramming = false;
        rgblight_set_layer_state(RGBL_PROG, isProgramming);
        process = false;
    }

    return process;
}

bool process_record_keymap(int16_t keycode, keyrecord_t* record)
{
    bool process = true;

    process &= process_programmable_key(keycode, record);
    // process &= override_dotcolon(keycode, record);
    process &= bgk_process_shifted_mod_tap(keycode, record);

    return process;
}



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
    debug_mouse = false;
#endif

#ifdef VIAL_TAP_DANCE_ENABLE
    for (uint8_t t = 0; t < VIAL_TAP_DANCE_ENTRIES; t++)
    {
        vial_tap_dance_entry_t td_entry = { 0 };
        if (dynamic_keymap_get_tap_dance(t, &td_entry) == 0)
        {
            if (td_entry.on_double_tap == KC_SEMICOLON)
            {
                td_semicolon = (QK_TAP_DANCE + t);
            }
            else if (td_entry.on_tap == KC_DOT && td_entry.on_double_tap == KC_COLON)
            {
                td_dot_colon = (QK_TAP_DANCE + t);
            }
        }
     }
#endif

#ifdef RGBLIGHT_ENABLE

    // Enable the LED layers:
    rgblight_layers = bgk_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer_repeat(RGBL_OK, 500, 3);

    // Exclude top-side indicator light from effects:
    // rgblight_set_effect_range(0, RGBLED_NUM-1);
    // rgblight_set_layer_state(0, true);

#endif // RGBLIGHT_ENABLE
}
