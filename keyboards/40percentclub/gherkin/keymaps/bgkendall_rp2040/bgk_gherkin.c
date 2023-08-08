#include "bgk_encoder.h"
#include "bgk_keycommands.h"
#include "bgk_rgb.h"

#ifdef CONSOLE_ENABLE
#include <print.h>
#endif


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

#ifdef RGBLIGHT_ENABLE

const rgblight_segment_t* const PROGMEM bgk_gherkin_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [KL_COLEMAK...KL_QWERTY]      = bgkrgb_white_layer,
    [KL_NUMBER]                   = bgkrgb_springgreen_layer,
    [KL_SYMBOL_CM...KL_SYMBOL_QW] = bgkrgb_magenta_layer,
    [KL_NAVIGATION]               = bgkrgb_blue_layer,
    [KL_FUNCTION]                 = bgkrgb_orange_layer,
    [KL_META]                     = bgkrgb_orangered_layer,
    [RGBL_OK]                     = bgkrgb_green_layer,
    [RGBL_CAPS]                   = bgkrgb_red_indicator_layer
);

layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) <= KL_META)
    {
        rgblight_disable_noeeprom();
        bgkrgb_set_from_highest_layer(state, KL_NUMBER, KL_META);
    }
    else
    {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD+2);
    }

    return state;
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);

    return true;
}

#endif // RGBLIGHT_ENABLE


const key_override_t override_backspace_delete = ko_make_basic(MOD_MASK_SHIFT,   KC_BSPC, KC_DEL);
const key_override_t override_q_command_grave  = ko_make_basic(MOD_BIT(KC_LGUI), KC_Q,    G(KC_GRV));
const key_override_t override_q_alt_shift_tab  = ko_make_basic(MOD_BIT(KC_LALT), KC_Q,    A(S(KC_TAB)));
const key_override_t override_q_ctrl_shift_tab = ko_make_basic(MOD_BIT(KC_LCTL), KC_Q,    C(S(KC_TAB)));
const key_override_t override_w_command_tab    = ko_make_basic(MOD_BIT(KC_LGUI), KC_W,    G(KC_TAB));
const key_override_t override_w_alt_tab        = ko_make_basic(MOD_BIT(KC_LALT), KC_W,    A(KC_TAB));
const key_override_t override_w_control_tab    = ko_make_basic(MOD_BIT(KC_LCTL), KC_W,    C(KC_TAB));
const key_override_t override_comma_semicolon  = ko_make_basic(MOD_MASK_SHIFT,   KC_COMM, KC_SCLN);
const key_override_t override_dot_colon        = ko_make_basic(MOD_MASK_SHIFT,   KC_DOT,  KC_COLN);


// This globally defines all key overrides to be used
const key_override_t** key_overrides = (const key_override_t *[])
{
    &override_backspace_delete,
    &override_q_command_grave,
    &override_q_alt_shift_tab,
    &override_q_ctrl_shift_tab,
    &override_w_command_tab,
    &override_w_alt_tab,
    &override_w_control_tab,
    &override_comma_semicolon,
    &override_dot_colon,
    NULL // Terminate the array of overrides
};


bool process_record_keymap(uint16_t keycode, keyrecord_t* record)
{
    bool process = true;

    if (process && record->event.pressed)
    {
        static bool cursor_vertical = false;

        switch (keycode)
        {
            case KC_WREF:
                // Flip encoder cursor orientation:
                cursor_vertical = !cursor_vertical;
                process = false;
                break;
            case KC_WBAK:
                // Encoder cursor left (down if flipped):
                tap_code16(cursor_vertical ? KC_DOWN : KC_LEFT);
                process = false;
                break;
            case KC_WFWD:
                // Encoder cursor right (up if flipped):
                tap_code16(cursor_vertical ? KC_UP : KC_RIGHT);
                process = false;
                break;
            case KC_UNDO:
                // Command+ or Control+Z depending on state of GUI and Control:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_Z) : G(KC_Z));
                process = false;
                break;
            case KC_CUT:
                // Command+ or Control+X depending on state of GUI and Control:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_X) : G(KC_X));
                process = false;
                break;
            case KC_COPY:
                // Command+ or Control+C depending on state of GUI and Control:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_C) : G(KC_C));
                process = false;
                break;
            case KC_PASTE:
                // Command+ or Control+V depending on state of GUI and Control:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_V) : G(KC_V));
                process = false;
                break;
            default:
                break;
        }
    }

    return process;
}


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
    backlight_enable();

#endif // BACKLIGHT_ENABLE

#ifdef RGBLIGHT_ENABLE

    rgblight_disable();

    // Enable the LED layers:
    rgblight_layers = bgk_gherkin_rgb_layers;

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1000);

#endif // RGBLIGHT_ENABLE
}
