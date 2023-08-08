#include "ortho5x12.h"


#ifdef CONSOLE_ENABLE
#include <print.h>
#endif


#ifdef RGBLIGHT_LAYERS

#include "users/bgkendall/bgk_rgb.h"

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

const rgblight_segment_t PROGMEM ortho_5_12_capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {0, 1, HSV_VIVIDPINK}, {RGBLED_NUM-1, 1, HSV_VIVIDPINK}
);

const rgblight_segment_t PROGMEM ortho_5_12_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {0, 1, HSV_RED}, {RGBLED_NUM-1, 1, HSV_RED}
);

#ifndef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m

const rgblight_segment_t* const PROGMEM ortho_5_12_rgb_layers[] = RGBLIGHT_LAYERS_LIST
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

    [RGBL_OK]       = ortho_5_12_ok_layer,
    [RGBL_CAPSWORD] = ortho_5_12_capsword_layer,
    [RGBL_CAPSLOCK] = ortho_5_12_capslock_layer
);

uint8_t get_rgb_layer(layer_state_t state)
{
    return (uint8_t)(keymap_key_to_keycode(get_highest_layer(state), (keypos_t)RGBLIGHT_LAYER_KEY) - KC_A);
}

layer_state_t default_layer_state_set_kb(layer_state_t state)
{
    rgblight_blink_layer(get_highest_layer(state), BGKRGB_BLINK_TIME);

    return default_layer_state_set_user(state);
}

layer_state_t layer_state_set_kb(layer_state_t state)
{
    if (keymap_key_to_keycode(get_highest_layer(state), (keypos_t){3,4}) == RGB_TOG)
    {
        // Meta layer has RGB underglow controls, so only blink layer
        // indicator so that the lighting being selected can be seen clearly:
        bgkrgb_blink_layer(get_rgb_layer(state), RGBL_A, RGBL_S);
    }
    else
    {
        bgkrgb_set_all_layers(get_rgb_layer(state), RGBL_A, RGBL_S);
    }

    return layer_state_set_user(state);
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPSLOCK, led_state.caps_lock);

    return true;
}

void caps_word_set_user(bool active)
{
    rgblight_set_layer_state(RGBL_CAPSWORD, active);
}

#endif // ¬KEYBOARD_handwired_bgkendall_ortho5x12_rev2m


#endif // RGBLIGHT_LAYERS


#ifndef VIAL_ENABLE

#ifdef TAP_DANCE_ENABLE

void td_copy_cut_press(qk_tap_dance_state_t* state, void* user_data)
{
    if ((get_mods() & MOD_MASK_CG) && state->count == 2)
    {
        register_code(KC_X);
    }
    else
    {
        register_code(KC_C);
    }
}

void td_copy_cut_reset(qk_tap_dance_state_t* state, void* user_data)
{
    unregister_code(KC_C);

    if (state->count == 2)
    {
        unregister_code(KC_X);
    }
}


typedef enum
{
    TD_NONE = 0,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

td_state_t td_get_current_state(qk_tap_dance_state_t* td_state)
{
    td_state_t current_state = TD_UNKNOWN;

    if (td_state->count == 1)
    {
        if (td_state->interrupted || !td_state->pressed)
        {
            current_state = TD_SINGLE_TAP;
        }
        else
        {
            current_state = TD_SINGLE_HOLD;
        }
    }
    else if (td_state->count == 2)
    {
        if (td_state->interrupted)
        {
            current_state = TD_DOUBLE_SINGLE_TAP;
        }
        else if (td_state->pressed)
        {
            current_state = TD_DOUBLE_HOLD;
        }
        else
        {
            current_state = TD_DOUBLE_TAP;
        }
    }

    return current_state;
}

static td_state_t td_lrb_state[17];

void td_bracket_layer_finished(qk_tap_dance_state_t* td_state, void* user_data)
{
    uint8_t layer = (uint8_t)(uintptr_t)user_data;
    td_lrb_state[layer] = td_get_current_state(td_state);

    switch (td_lrb_state[layer])
    {
        case TD_SINGLE_TAP:
        {
            register_code(KC_LBRC);
            break;
        }
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
        {
            layer_on(layer);
            break;
        }
        case TD_DOUBLE_TAP:
        {
            register_code(KC_RBRC);
            break;
        }
        case TD_DOUBLE_SINGLE_TAP:
        {
            tap_code(KC_LBRC);
            register_code(KC_LBRC);
            break;
        }
        default:
            break;
    }
}

void td_bracket_layer_reset(qk_tap_dance_state_t* td_state, void* user_data)
{
    uint8_t layer = (uint8_t)(uintptr_t)user_data;

    switch (td_lrb_state[layer])
    {
        case TD_SINGLE_TAP:
        {
            unregister_code(KC_LBRC);
            break;
        }
        case TD_SINGLE_HOLD:
        {
            layer_off(layer);
            break;
        }
        case TD_DOUBLE_TAP:
        {
            unregister_code(KC_RBRC);
            break;
        }
        case TD_DOUBLE_SINGLE_TAP:
        {
            unregister_code(KC_LBRC);
            break;
        }
        default:
            break;
    }

    td_lrb_state[layer] = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] =
{
    [TD_CPCT] = ACTION_TAP_DANCE_FN_ADVANCED(td_copy_cut_press, NULL, td_copy_cut_reset),
    [TD_LRBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_LRB2] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)2, },
    [TD_LRB3] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)3, },
    [TD_LRB4] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)4, },
    [TD_LRB5] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)5, },
    [TD_GESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRAVE)
};

#endif // TAP_DANCE_ENABLE



#ifdef KEY_OVERRIDE_ENABLE

bool disabled = false;

// Use with suppressed_mods to clear the modifiers
// BEFORE the replacement key is sent.
bool flush_modifiers(bool key_down, void* context)
{
    send_keyboard_report();
    return true;
}

const key_override_t override_cmd_esc_grave = {
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    .trigger            = LT(U_MEDIA,KC_ESC),
#else
    .trigger            = KC_ESC,
#endif
    .trigger_mods       = MOD_MASK_GUI,
    .negative_mod_mask  = MOD_MASK_ALT,
    .layers             = ~0,
    .suppressed_mods    = 0,
    .replacement        = KC_GRAVE,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_alt_esc_stab = {
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    .trigger            = LT(U_MEDIA,KC_ESC),
#else
    .trigger            = KC_ESC,
#endif
    .trigger_mods       = MOD_MASK_ALT,
    .negative_mod_mask  = MOD_MASK_GUI,
    .layers             = ~0,
    .suppressed_mods    = 0,
    .replacement        = S(KC_TAB),
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_ctl_esc_grave = {
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    .trigger            = LT(U_MEDIA,KC_ESC),
#else
    .trigger            = KC_ESC,
#endif
    .trigger_mods       = MOD_MASK_CTRL,
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_CTRL,
    .custom_action      = flush_modifiers,
    .replacement        = KC_GRAVE,
    .options            = ko_options_default,
    .enabled            = NULL
};
const key_override_t override_sft_esc_tilde = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRAVE));

const key_override_t override_backspace_delete = {
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    .trigger            = LT(U_SYM,KC_BSPC),
#else
    .trigger            = KC_BSPC,
#endif
    .trigger_mods       = MOD_MASK_SHIFT,
    .layers             = ~0,
    .suppressed_mods    = MOD_MASK_SHIFT,
    .custom_action      = flush_modifiers,
    .replacement        = KC_DEL,
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
    &override_cmd_esc_grave,
    &override_alt_esc_stab,
    &override_ctl_esc_grave,
    &override_sft_esc_tilde,
    &override_backspace_delete,
#ifdef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    &override_comma_semi,
    &override_dot_colon,
    &override_comma_paren,
    &override_dot_paren,
    &override_comma_angle,
    &override_dot_angle,
    &override_comma_brace,
    &override_dot_brace,
#endif // KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
    NULL // Terminate the array of overrides
};

#endif // KEY_OVERRIDE_ENABLE

#endif // ¬VIAL_ENABLE


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
        case QK_TAP_DANCE: // Only apply to first tap dance key
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


#ifndef KEYBOARD_handwired_bgkendall_ortho5x12_rev2m

void keyboard_post_init_kb(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    //debug_matrix = true;
#endif

#ifdef RGBLIGHT_LAYERS
    // Enable the LED layers:
    rgblight_layers = ortho_5_12_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 800);
#endif
}

#endif // ¬KEYBOARD_handwired_bgkendall_ortho5x12_rev2m
