#include "ortho5x12.h"

#include "bgk_cmd-tab.h"
#include "bgk_rgb.h"
#include "users/bgkendall/private/texts.h"

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

const rgblight_segment_t PROGMEM ortho_5_12_apps_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {  1, 1, HSV_1PASSWORD },
    {  2, 1, HSV_MS_OUTLOOK },
    {  3, 1, HSV_MS_TEAMS },
    {  4, 1, HSV_MS_ONENOTE },
    {  5, 1, HSV_REMOTE_SESSION },
    {  6, 1, HSV_SAFARI },
    {  7, 1, HSV_MS_WORD },
    {  8, 1, HSV_MS_EXCEL },
    {  9, 1, HSV_MS_PROJECT }
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
    [RGBL_CAPS] = ortho_5_12_caps_layer,
    [RGBL_APPS] = ortho_5_12_apps_layer
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

void matrix_scan_kb(void)
{
    bgkey_unregister_command_for_tab();
    matrix_scan_user();
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

bool process_record_kb(uint16_t keycode, keyrecord_t* record)
{
    bool process = true;
    const uint8_t modifiers = get_mods();

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case CK_M1:
            {
                SEND_STRING(TEXT_STRING_1 "\n");
                process = false;
                break;
            }
            case CK_M2:
            {
                SEND_STRING(TEXT_STRING_2 "\n");
                process = false;
                break;
            }
            case CK_M3:
            {
                if (modifiers & MOD_BIT(KC_LGUI))
                {
                    unregister_code(KC_LGUI);
                    SEND_STRING(TEXT_STRING_3g);
                    register_code(KC_LGUI);
                }
                else if (modifiers & MOD_BIT(KC_RGUI))
                {
                    unregister_code(KC_RGUI);
                    SEND_STRING(TEXT_STRING_3g);
                    register_code(KC_RGUI);
                }
                else if (modifiers & MOD_BIT(KC_LALT))
                {
                    unregister_code(KC_LALT);
                    SEND_STRING(TEXT_STRING_3a);
                    register_code(KC_LALT);
                }
                else if (modifiers & MOD_BIT(KC_RALT))
                {
                    unregister_code(KC_RALT);
                    SEND_STRING(TEXT_STRING_3a);
                    register_code(KC_RALT);
                }
                else if (modifiers & MOD_BIT(KC_LCTL))
                {
                    unregister_code(KC_LCTL);
                    SEND_STRING(TEXT_STRING_3c);
                    register_code(KC_LCTL);
                }
                else if (modifiers & MOD_BIT(KC_RCTL))
                {
                    unregister_code(KC_RCTL);
                    SEND_STRING(TEXT_STRING_3c);
                    register_code(KC_RCTL);
                }
                else
                {
                    SEND_STRING(TEXT_STRING_3);
                }
                process = false;
                break;
            }
            case CK_MULT:
            {
                tap_code16(C(KC_SPACE));  // Switch to Unicode input (hopefully)
                register_code(KC_RALT);   // Hold down right alt
                SEND_STRING("00d7");      // Send Unicode for multiplication sign
                unregister_code(KC_RALT); // Release right alt
                tap_code16(C(KC_SPACE));  // Switch away from Unicode input
                process = false;
                break;
            }
            case CK_THOU:
            {
                tap_code16(KC_P0);
                tap_code16(KC_P0);
                tap_code16(KC_P0);
                process = false;
                break;
            }
            case CK_TONL:
            {
                uint8_t new_layer = get_highest_layer(layer_state) + 1;
                if (new_layer > KL_DEF4) { new_layer = KL_DEF; }
                layer_move(new_layer);
                process = false;
                break;
            }
            case KC_TAB:
            {
                if (get_highest_layer(layer_state) >= KL_FN &&
                    get_highest_layer(layer_state) <= KL_FN2)
                {
                    bgkey_register_command_for_tab();
                }
                break;
            }
            case RGB_TGVAD:
            {
                rgblight_decrease_val();
                if (rgblight_get_val() == 0)
                {
                    rgblight_disable();
                }
                process = false;
                break;
            }
            case RGB_TGVAI:
            {
                if (!rgblight_is_enabled())
                {
                    rgblight_enable();
                }
                rgblight_increase_val();
                process = false;
                break;
            }
            default:
                break;
        }
    }

    if (process)
    {
        static bool is_left_shift_pressed = false;

        switch (keycode)
        {
            case KC_LSFT:
            {
                is_left_shift_pressed = record->event.pressed;
                break;
            }
            case CK_COMDOT:
            {
                static bool comma_dot_was_shifted = false;
                if (record->event.pressed)
                {
                    comma_dot_was_shifted = is_left_shift_pressed;
                    if (is_left_shift_pressed)
                    {
                        unregister_code(KC_LSHIFT);
                    }
                    add_key(comma_dot_was_shifted ? KC_DOT : KC_COMM);
                }
                else
                {
                    del_key(comma_dot_was_shifted ? KC_DOT : KC_COMM);
                    if (is_left_shift_pressed)
                    {
                        register_code(KC_LSHIFT);
                    }
                }
                send_keyboard_report();
                process = false;
                break;
            }
            case CK_GDEL:
            {
                static bool grave_del_was_shifted = false;
                if (record->event.pressed)
                {
                    if (modifiers & MOD_BIT(KC_LCTL))
                    {
                        unregister_code(KC_LCTL);
                        tap_code16(KC_ESCAPE);
                        register_code(KC_LCTL);
                    }
                    else
                    {
                        grave_del_was_shifted = modifiers & MOD_MASK_SG;
                        add_key(grave_del_was_shifted ? KC_GRAVE : KC_DELETE);
                    }
                }
                else
                {
                    if (!(modifiers & MOD_BIT(KC_LCTL)))
                    {
                        del_key(grave_del_was_shifted ? KC_GRAVE : KC_DELETE);
                    }
                }
                send_keyboard_report();
                process = false;
                break;
            }
            case CK_PAREN:
            {
                static bool paren_was_shifted = false;
                if (record->event.pressed)
                {
                    paren_was_shifted  = modifiers & MOD_MASK_SHIFT;
                    add_key(paren_was_shifted ? KC_RIGHT_PAREN : KC_LEFT_PAREN);
                }
                else
                {
                    del_key(paren_was_shifted ? KC_RIGHT_PAREN : KC_LEFT_PAREN);
                }
                send_keyboard_report();
                process = false;
                break;
            }
            default:
                break;
        }
    }

    return process;
}

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}
