//
//  bgk_keycodes.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-06-06.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#include "bgk_keycodes.h"
#include "bgk_keycommands.h"
#include "users/bgkendall/private/texts.h"


__attribute__ ((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record)
{
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    bool process = process_record_keymap(keycode, record);

    if (process)
    {
        const uint8_t modifiers = get_mods();

        if (record->event.pressed)
        {
            switch (keycode)
            {
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
                    clear_mods();
                    clear_oneshot_mods();
                    if (modifiers & MOD_MASK_GUI)
                    {
                        SEND_STRING(TEXT_STRING_3g);
                    }
                    else if (modifiers & MOD_MASK_ALT)
                    {
                        SEND_STRING(TEXT_STRING_3a);
                    }
                    else if (modifiers & MOD_MASK_CTRL)
                    {
                        SEND_STRING(TEXT_STRING_3c);
                    }
                    else
                    {
                        SEND_STRING(TEXT_STRING_3);
                    }
                    set_mods(modifiers);
                    process = false;
                    break;
                }
                case BK_CMDTAB_FORWARD:
                {
                    process = bgkey_register_forward_command_tab();
                    break;
                }
                case BK_CMDTAB_BACKWARD:
                {
                    process = bgkey_register_backward_command_tab();
                    break;
                }
                case BK_MAKE:
                {
                    process = bgkey_make();
                    break;
                }
                case BK_TIMES:
                {
                    // Somewhat brittle multiplication sign (×) key
                    // Relies on only two Input Sources being enabled — the one in use and Unicode Hex Input
                    // May sometimes not switch to the Unicode source before sending the Unicode string, or
                    // may not switch back to the usual Input Source
                    //
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
            switch (keycode)
            {
                case BK_000:
                {
                    // Thousands (000) key
                    //
                    if (record->event.pressed)
                    {
                        tap_code(KC_P0);
                        tap_code(KC_P0);
                        register_code(KC_P0);
                    }
                    else
                    {
                        unregister_code(KC_P0);
                    }
                    process = false;
                    break;
                }
                case BK_COMDOT:
                {
                    // Sends Comma normally, Dot when Left Shift is held
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_COMM, KC_DOT, MOD_BIT(KC_LSFT), true);
                    break;
                }
                case BK_BSDEL:
                {
                    // Sends Backspace normally, Delete when Shift is held
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_BSPACE, KC_DEL, MOD_MASK_SHIFT, true);
                    break;
                }
                case BK_GRVDEL:
                {
                    // Like Grave-Escape, but for Delete
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_DELETE, KC_GRAVE, MOD_MASK_SG, false);
                    break;
                }
                case BK_GRVEQ:
                {
                    // Sends Equals normally, Grave when Left GUI is held
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_DELETE, KC_GRAVE, MOD_BIT(KC_LGUI), false);
                    break;
                }
                case BK_GRVQUO:
                {
                    // Sends Apostrophe normally, Grave when Left GUI is held
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_QUOT, KC_GRAVE, MOD_BIT(KC_LGUI), false);
                    break;
                }
                case BK_PAREN:
                {
                    // Sends '(' normally, ')' when Shift is held
                    //
                    process = bgkey_mod_munge(record->event.pressed, KC_LEFT_PAREN, KC_0, MOD_MASK_SHIFT, false);
                    break;
                }
                default:
                    break;
            }
        }
    }

    return process;
}
