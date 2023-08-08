/*
Copyright 2022 bgkendall

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


/*****************************************************************************
 * DEFAULT LAYERS                                                            *
 *****************************************************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x10(
    KC_Q,    KC_W,    KC_R,    KC_P,    KC_F,    KC_J,    KC_Y,    KC_O,    KC_L,    KC_BSPC,
    KC_A,    KC_S,    KC_D,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_U,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_COMM, KC_DOT,  KC_H,    KC_B,    KC_K,    LT(1, KC_ESC),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_SPC,  KC_TRNS, KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [1 ... (DYNAMIC_KEYMAP_LAYER_COUNT - 1)] = LAYOUT_ortho_4x10(
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};


// enum DOT_MODES
// {
//     DOT = 0,
//     COMMA,
//     FULL_STOP
// };


/*****************************************************************************
 * ENCODER                                                                   *
 *****************************************************************************/

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0 ... (DYNAMIC_KEYMAP_LAYER_COUNT - 1)] = { ENCODER_CCW_CW(KC_NO, KC_NO) }
};

#endif // ENCODER_MAP_ENABLE


/*****************************************************************************
 * RGB                                                                       *
 *****************************************************************************/

#ifdef RGBLIGHT_ENABLE

#include "users/bgkendall/bgk_rgb.h"

enum RGB_LAYERS
{
    RGBL_LTRT = (DYNAMIC_KEYMAP_LAYER_COUNT+1),
    RGBL_UPDN,
    // RGBL_DOT,
    // RGBL_COMM,
    // RGBL_STOP,
    RGBL_CAPW,
    RGBL_CAPL,
    RGBL_OK
};


const rgblight_segment_t* const PROGMEM bgk_gherkinpp_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [0]         = bgkrgb_white_layer,
    [1]         = bgkrgb_orangered_layer,
    [2]         = bgkrgb_cyan_layer,
    [3]         = bgkrgb_green_layer,
    [4]         = bgkrgb_magenta_layer,
    [RGBL_LTRT] = bgkrgb_yellow_layer,
    [RGBL_UPDN] = bgkrgb_blue_layer,
    // [RGBL_DOT]  = bgkrgb_cyan_layer,
    // [RGBL_COMM] = bgkrgb_magenta_layer,
    // [RGBL_STOP] = bgkrgb_yellow_layer,
    [RGBL_CAPW] = bgkrgb_vividpink_layer,
    [RGBL_CAPL] = bgkrgb_red_layer,
    [RGBL_OK]   = bgkrgb_green_layer
);

layer_state_t default_layer_state_set_kb(layer_state_t state)
{
    rgblight_blink_layer(get_highest_layer(state), BGKRGB_BLINK_TIME);

    return default_layer_state_set_user(state);
}

layer_state_t layer_state_set_kb(layer_state_t state)
{
    bgkrgb_set_from_layers(state, 1, (DYNAMIC_KEYMAP_LAYER_COUNT-1));

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
 * CUSTOM KEY BEHAVIOUR                                                      *
 *****************************************************************************/

bool process_record_kb(uint16_t keycode, keyrecord_t* record)
{
    bool process = true;

    static bool flip_encoder_navigation = false;
    // static int dot_mode = DOT;

    uint16_t new_keycode = KC_NO;

    switch (keycode)
    {
        case USER00:
            if (record->event.pressed)
            {
                // Flip encoder cursor orientation:
                flip_encoder_navigation = !flip_encoder_navigation;
#ifdef RGBLIGHT_ENABLE
                rgblight_blink_layer((flip_encoder_navigation ? RGBL_UPDN : RGBL_LTRT), 250);
#endif
            }
            process = false;
            break;
        case USER01:
            // Encoder cursor left (down if flipped):
            new_keycode = (flip_encoder_navigation ? KC_DOWN : KC_LEFT);
            break;
        case USER02:
            // Encoder cursor right (up if flipped):
            new_keycode = (flip_encoder_navigation ? KC_UP : KC_RIGHT);
            break;
        case USER03:
            // Encoder page down (home if flipped):
            new_keycode = (flip_encoder_navigation ? KC_HOME : KC_PGDN);
            break;
        case USER04:
            // Encoder page up (end if flipped):
            new_keycode = (flip_encoder_navigation ? KC_END : KC_PGUP);
            break;

//         case USER05:
//             if (record->event.pressed)
//             {
//                 // Increment dot mode:
//                 if ( (++dot_mode) > FULL_STOP ) { dot_mode = DOT; }
// #ifdef RGBLIGHT_ENABLE
//                 rgblight_blink_layer(RGBL_DOT + dot_mode, 250);
// #endif
//             }
//             process = false;
//             break;
//         case KC_KP_DOT:
//             switch (dot_mode)
//             {
//                 case DOT:
//                     new_keycode = KC_KP_DOT;
//                     break;
//                 case COMMA:
//                     new_keycode = KC_COMMA;
//                     break;
//                 case FULL_STOP:
//                     new_keycode = KC_DOT;
//                     break;
//                 default:
//                     dot_mode = DOT;
//                     break;
//             }
//             break;

        default:
            break;
    }

    if (process && new_keycode != KC_NO)
    {
        if (record->event.pressed)
        {
            register_code(new_keycode);
        }
        else
        {
            unregister_code(new_keycode);
        }
        process = false;
    }

     return (process &= process_record_user(keycode, record));
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
#endif

#ifdef BACKLIGHT_ENABLE

    // Turn off lighting:
    backlight_disable();

#endif // BACKLIGHT_ENABLE

#ifdef RGBLIGHT_ENABLE

    rgblight_disable();

    // Enable the LED layers:
    rgblight_layers = bgk_gherkinpp_rgb_layers;

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, BGKRGB_BLINK_TIME);

#endif // RGBLIGHT_ENABLE
}
