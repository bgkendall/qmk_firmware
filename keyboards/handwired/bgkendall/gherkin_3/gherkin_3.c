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

#include "gherkin_3.h"

#include "users/bgkendall/bgk_keycodes.h"


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

#endif // ‘CAPS_WORD_ENABLE


#ifndef VIAL_ENABLE


#include "manna-harbour_miryoku.h"


/*****************************************************************************
 * ENCODER                                                                   *
 *****************************************************************************/

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [U_BASE]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT)  },f
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


const rgblight_segment_t* const PROGMEM bgk_gherkinpp_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [U_BASE]    = bgkrgb_white_layer,
    [U_EXTRA]   = bgkrgb_goldenrod_layer,
    [U_TAP]     = bgkrgb_red_layer,
    [U_BUTTON]  = bgkrgb_purple_layer,
    [U_NAV]     = bgkrgb_cyan_layer,
    [U_MOUSE]   = bgkrgb_yellow_layer,
    [U_MEDIA]   = bgkrgb_magenta_layer,
    [U_NUM]     = bgkrgb_blue_layer,
    [U_SYM]     = bgkrgb_green_layer,
    [U_FUN]     = bgkrgb_orangered_layer,
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
    bgkrgb_set_from_layers(state, U_BUTTON, U_FUN);

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
 * COMBOS                                                                    *
 *****************************************************************************/

#ifdef COMBO_ENABLE

const uint16_t PROGMEM combo_z_esc[] = {KC_Z, KC_ESC, COMBO_END};

/*
// Adjacent keys
const uint16_t PROGMEM combo_1[] = {KC_Q, KC_W,     COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_W, KC_R,     COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_R, KC_P,     COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_P, KC_F,     COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_F, KC_G,     COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_M, KC_J,     COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_J, KC_Y,     COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_Y, KC_O,     COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_O, KC_L,     COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_L, TD(QUOT), COMBO_END};
*/
// Surrounding keys
const uint16_t PROGMEM combo_1[] = {LCTL_T(KC_A),       KC_W,  COMBO_END};
const uint16_t PROGMEM combo_2[] = {       KC_Q,        KC_R,  COMBO_END};
const uint16_t PROGMEM combo_3[] = {       KC_W,        KC_P,  COMBO_END};
const uint16_t PROGMEM combo_4[] = {       KC_R,        KC_F,  COMBO_END};
const uint16_t PROGMEM combo_5[] = {       KC_P,        KC_J,  COMBO_END};
const uint16_t PROGMEM combo_6[] = {       KC_F,        KC_Y,  COMBO_END};
const uint16_t PROGMEM combo_7[] = {       KC_J,        KC_O,  COMBO_END};
const uint16_t PROGMEM combo_8[] = {       KC_Y,        KC_L,  COMBO_END};
const uint16_t PROGMEM combo_9[] = {       KC_O,     TD(QUOT), COMBO_END};
const uint16_t PROGMEM combo_0[] = {       KC_L, LCTL_T(KC_U), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

    // Escape from Tap layer
    COMBO(combo_z_esc,  DF(0)),

    // Numbers
    COMBO(combo_1, KC_1),
    COMBO(combo_2, KC_2),
    COMBO(combo_3, KC_3),
    COMBO(combo_4, KC_4),
    COMBO(combo_5, KC_5),
    COMBO(combo_6, KC_6),
    COMBO(combo_7, KC_7),
    COMBO(combo_8, KC_8),
    COMBO(combo_9, KC_9),
    COMBO(combo_0, KC_0)
};

#endif // COMBO_ENABLE


/*****************************************************************************
 * TAP DANCES                                                                *
 *****************************************************************************/

#ifdef TAP_DANCE_ENABLE

qk_tap_dance_action_t tap_dance_actions[] =
{
    [QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRAVE)
};

#endif // TAP_DANCE_ENABLE


/*****************************************************************************
 * KEY OVERRIDES                                                             *
 *****************************************************************************/

#ifdef KEY_OVERRIDE_ENABLE

// Use with suppressed_mods to clear the modifiers
// BEFORE the replacement key is sent.
bool flush_modifiers(bool key_down, void* context)
{
    send_keyboard_report();
    return true;
}

const key_override_t override_cmd_grave = {
    .trigger            = LT(U_MOUSE,KC_MINS),
    .trigger_mods       = MOD_MASK_GUI,
    .negative_mod_mask  = MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = 0,
    .replacement        = KC_GRAVE,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_alt_backtab = {
    .trigger            = LT(U_MOUSE,KC_MINS),
    .trigger_mods       = MOD_BIT(KC_LALT),
    .negative_mod_mask  = MOD_MASK_GUI,
    .layers             = ~0,
    .suppressed_mods    = 0,
    .replacement        = S(KC_TAB),
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_backspace_delete = {
    .trigger            = LT(U_FUN,KC_BSPC),
    .trigger_mods       = MOD_MASK_SHIFT,
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_SHIFT,
    .custom_action      = flush_modifiers,
    .replacement        = KC_DEL,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_escape_tap = {
    .trigger            = KC_ESC,
    .trigger_mods       = 0,
    .layers             = (1 << U_TAP),
    .suppressed_mods    = 0,
    .replacement        = DF(0),
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_comma_semi = {
    .trigger            = KC_COMM,
    .trigger_mods       = MOD_MASK_SHIFT,
    .negative_mod_mask  = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_SHIFT,
    .custom_action      = flush_modifiers,
    .replacement        = KC_SCLN,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_dot_colon = {
    .trigger            = KC_DOT,
    .trigger_mods       = MOD_MASK_SHIFT,
    .negative_mod_mask  = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = 0,
    .replacement        = KC_COLN,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_comma_paren = {
    .trigger            = KC_COMM,
    .trigger_mods       = MOD_MASK_CTRL,
    .negative_mod_mask  = MOD_MASK_SHIFT | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_CTRL,
    .custom_action      = flush_modifiers,
    .replacement        = KC_LPRN,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_dot_paren = {
    .trigger            = KC_DOT,
    .trigger_mods       = MOD_MASK_CTRL,
    .negative_mod_mask  = MOD_MASK_SHIFT | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_CTRL,
    .custom_action      = flush_modifiers,
    .replacement        = KC_RPRN,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_comma_angle = {
    .trigger            = KC_COMM,
    .trigger_mods       = MOD_BIT(KC_LALT),
    .negative_mod_mask  = MOD_MASK_SHIFT | MOD_MASK_CTRL,
    .layers             = ~0,
    .suppressed_mods    = MOD_BIT(KC_LALT),
    .custom_action      = flush_modifiers,
    .replacement        = KC_LT,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_dot_angle = {
    .trigger            = KC_DOT,
    .trigger_mods       = MOD_BIT(KC_LALT),
    .negative_mod_mask  = MOD_MASK_SHIFT | MOD_MASK_CTRL,
    .layers             = ~0,
    .suppressed_mods    = MOD_BIT(KC_LALT),
    .custom_action      = flush_modifiers,
    .replacement        = KC_GT,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_comma_brace = {
    .trigger            = KC_COMM,
    .trigger_mods       = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .custom_action      = flush_modifiers,
    .replacement        = KC_LBRC,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_dot_brace = {
    .trigger            = KC_DOT,
    .trigger_mods       = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_CTRL | MOD_BIT(KC_LALT),
    .custom_action      = flush_modifiers,
    .replacement        = KC_RBRC,
    .options            = ko_options_default,
    .enabled            = NULL
};

// This globally defines all key overrides to be used
const key_override_t** key_overrides = (const key_override_t *[])
{
    &override_cmd_grave,
    &override_alt_backtab,
    &override_backspace_delete,
    &override_escape_tap,
    &override_comma_semi,
    &override_dot_colon,
    &override_comma_paren,
    &override_dot_paren,
    &override_comma_angle,
    &override_dot_angle,
    &override_comma_brace,
    &override_dot_brace,
    NULL // Terminate the array of overrides
};

#endif // KEY_OVERRIDE_ENABLE


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


#endif // ¬VIAL_ENABLE
