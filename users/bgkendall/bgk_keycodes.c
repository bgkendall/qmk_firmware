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


#ifndef DYNAMIC_KEYMAP_MACRO_COUNT
#  define BGK_MACRO_COUNT 16
#else
#  define BGK_MACRO_COUNT DYNAMIC_KEYMAP_MACRO_COUNT
#endif


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
#ifndef NO_ACTION_ONESHOT
                    clear_oneshot_mods();
#endif
                    send_keyboard_report();

                    if (modifiers & MOD_MASK_GUI)
                    {
#ifdef VIA_ENABLE
                        dynamic_keymap_macro_send(BGK_MACRO_COUNT-1);
#else
                        SEND_STRING(TEXT_STRING_3g);
#endif
                    }
                    else if (modifiers & MOD_MASK_ALT)
                    {
#ifdef VIA_ENABLE
                        dynamic_keymap_macro_send(BGK_MACRO_COUNT-2);
#else
                        SEND_STRING(TEXT_STRING_3a);
#endif
                    }
                    else if (modifiers & MOD_MASK_SHIFT)
                    {
#ifdef VIA_ENABLE
                        dynamic_keymap_macro_send(BGK_MACRO_COUNT-3);
#else
                        SEND_STRING(TEXT_STRING_3s);
#endif
                    }
                    else if (modifiers & MOD_MASK_CTRL)
                    {
#ifdef VIA_ENABLE
                        dynamic_keymap_macro_send(BGK_MACRO_COUNT-4);
#else
                        SEND_STRING(TEXT_STRING_3c);
#endif
                    }
                    else
                    {
#ifdef VIA_ENABLE
                        dynamic_keymap_macro_send(BGK_MACRO_COUNT-5);
#else
                        SEND_STRING(TEXT_STRING_3);
#endif
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
                case BK_LOCK:
                {
                    // Tap to lock current layer, tap again to return to default layer
                    // If the current default layer is 0, set the current highest layer as the default,
                    // otherwise reset the default layer to 0
                    // A simpler method would be to do `default_layer_set(layer_state)`,
                    // but this will not reset the default layer if, say, MO(n) is currently being held
                    //
                    default_layer_set
                    (
                        1 << (get_highest_layer(default_layer_state) == 0 ? get_highest_layer(layer_state) : 0)
                    );
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
                default:
                    break;
            }
        }
    }

    return process;
}
