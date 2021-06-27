#include "bgk_encoder.h"
#include "bgk_rgb.h"

#ifdef CONSOLE_ENABLE
#include <print.h>
#endif


bool CURSOR_VERTICAL = false;


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
    [KL_META]                     = bgkrgb_white_layer,
    [RGBL_OK]                     = bgkrgb_green_layer,
    [RGBL_CAPS]                   = bgkrgb_red_indicator_layer
);

layer_state_t layer_state_set_user(layer_state_t state)
{
    if (get_highest_layer(state) <= KL_META)
    {
        bgkrgb_set_from_highest_layer(state, KL_NUMBER, KL_FUNCTION);
    }

    if (get_highest_layer(state) == KL_META)
    {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD+2);
    }
    else
    {
        rgblight_disable();
    }

    return state;
}

bool led_update_user(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);

    return true;
}

#endif // RGBLIGHT_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t* record)
{
    bool process = true;

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case KC_WREF:
                CURSOR_VERTICAL = !CURSOR_VERTICAL;
                process = false;
                break;
            case KC_WBAK:
                tap_code16(CURSOR_VERTICAL ? KC_DOWN : KC_LEFT);
                process = false;
                break;
            case KC_WFWD:
                tap_code16(CURSOR_VERTICAL ? KC_UP : KC_RIGHT);
                process = false;
                break;
            case KC_CUT:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_X) : G(KC_X));
                process = false;
                break;
            case KC_COPY:
                tap_code16(keymap_config.swap_lctl_lgui ? C(KC_C) : G(KC_C));
                process = false;
                break;
            case KC_PASTE:
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

    // Turn off lighting:
    backlight_disable();

#ifdef RGBLIGHT_ENABLE

    rgblight_disable();

    // Enable the LED layers:
    rgblight_layers = bgk_gherkin_rgb_layers;

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1000);

#endif // RGBLIGHT_ENABLE
}
