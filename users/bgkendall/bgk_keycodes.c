//
//  bgk_keycodes.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-06-06.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#include "bgk_keycodes.h"

#include "quantum.h"
#include "users/bgkendall/private/texts.h"


// Global variables and functions for Cmd+Tab via encoder or other non-standard mechanism.
// Adapted from https://docs.splitkb.com/hc/en-us/articles/360010513760
//
const int16_t bgkey_command_tab_hold_time = 800; // ms
bool bgkey_is_command_tab_active = false;
uint16_t bgkey_command_tab_timer = 0;

void bgkey_register_command_for_tab(void)
{
    if (!bgkey_is_command_tab_active)
    {
        // Register Command for Cmd+Tab handling:
        bgkey_is_command_tab_active = true;
        register_code(KC_LCMD);
    }
    bgkey_command_tab_timer = timer_read();
}

void bgkey_register_forward_command_tab(void)
{
    bgkey_register_command_for_tab();
    tap_code16(KC_TAB);
}

void bgkey_register_backward_command_tab(void)
{
    bgkey_register_command_for_tab();
    tap_code16(S(KC_TAB));
}

void bgkey_unregister_command_for_tab(void)
{
    if (bgkey_is_command_tab_active)
    {
        // Unregister Command after Cmd+Tab times out:
        if (timer_elapsed(bgkey_command_tab_timer) > bgkey_command_tab_hold_time)
        {
            bgkey_is_command_tab_active = false;
            unregister_code(KC_LCMD);
        }
    }
}


__attribute__ ((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record)
{
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    bool process = true;
    const uint8_t modifiers = get_mods();

    if (process_record_keymap(keycode, record))
    {
        if (record->event.pressed)
        {
            switch (keycode)
            {
                case BK_000:
                {
                    tap_code16(KC_P0);
                    tap_code16(KC_P0);
                    tap_code16(KC_P0);
                    process = false;
                    break;
                }
                case BK_M1:
                {
                    SEND_STRING(TEXT_STRING_1 "\n");
                    process = false;
                    break;
                }
                case BK_M2:
                {
                    SEND_STRING(TEXT_STRING_2 "\n");
                    process = false;
                    break;
                }
                case BK_M3:
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
                case BK_CMDTAB_FORWARD:
                {
                    bgkey_register_forward_command_tab();
                    process = false;
                    break;
                }
                case BK_CMDTAB_BACKWARD:
                {
                    bgkey_register_backward_command_tab();
                    process = false;
                    break;
                }
                case BK_TIMES:
                {
                    tap_code16(C(KC_SPACE));  // Switch to Unicode input (hopefully)
                    register_code(KC_RALT);   // Hold down right alt
                    SEND_STRING("00d7");      // Send Unicode for multiplication sign
                    unregister_code(KC_RALT); // Release right alt
                    tap_code16(C(KC_SPACE));  // Switch away from Unicode input
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
                case BK_COMDOT:
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
                case BK_GDEL:
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
                case BK_PAREN:
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
    }

    return process;
}
