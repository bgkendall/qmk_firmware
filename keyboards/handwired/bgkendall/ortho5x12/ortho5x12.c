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

static td_state_t td_lrb_state[KL_META];

void td_bracket_layer_finished(qk_tap_dance_state_t* td_state, void* user_data)
{
    uint8_t layer = (uint16_t)user_data;
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
    uint8_t layer = (uint16_t)user_data;

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
    [TD_LRB2] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)KL_NUM, },
    [TD_LRB3] = { .fn = { NULL, td_bracket_layer_finished, td_bracket_layer_reset}, .user_data = (void*)KL_NP,  },
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
