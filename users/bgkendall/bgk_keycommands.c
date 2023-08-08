//
//  bgk_keycommands.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-08-01.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#include "bgk_keycommands.h"

#include "quantum.h"


// Global variables and functions for Cmd+Tab via encoder or other non-standard mechanism.
// Adapted from https://docs.splitkb.com/hc/en-us/articles/360010513760
//
const uint16_t bgkey_command_tab_hold_time = 800; // ms
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

bool bgkey_unregister_command_for_tab(bool immediate)
{
    if (bgkey_is_command_tab_active)
    {
        // Unregister Command after Cmd+Tab times out:
        if (immediate || timer_elapsed(bgkey_command_tab_timer) > bgkey_command_tab_hold_time)
        {
            bgkey_is_command_tab_active = false;
            unregister_code(KC_LCMD);
        }
    }

    return false;
}

bool bgkey_register_forward_command_tab(void)
{
    bgkey_register_command_for_tab();
    tap_code16(BGKEY_FORWARD_TAB);

    return false;
}

bool bgkey_register_backward_command_tab(void)
{
    bgkey_register_command_for_tab();
    tap_code16(BGKEY_BACKWARD_TAB);

    return false;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    if (state == 0)
    {
        bgkey_unregister_command_for_tab(true);
    }

    return state;
}



// Sends natural key (or does nothing) unless trigger modifiers are held, in
// which case it sends the modified key (in other words it works like Grave/Escape)
//
//bool bgkey_mod_munge(bool pressed,
//                     uint16_t natural_key,
//                     uint16_t modified_key,
//                     uint8_t trigger_modifiers,
//                     bool release_modifiers)
//{
//    static bool was_key_shifted[KC_F24];
//
//    bool continue_processing = true;
//
//    if (modified_key <= KC_F24)
//    {
//        const uint8_t current_modifiers = get_mods();
//
//        if (pressed)
//        {
//            was_key_shifted[modified_key] = (current_modifiers & trigger_modifiers);
//            if (was_key_shifted[modified_key])
//            {
//                if (release_modifiers)
//                {
//                    del_mods(trigger_modifiers);
//                }
//                register_code(modified_key);
//                send_keyboard_report();
//                if (release_modifiers)
//                {
//                    set_mods(current_modifiers);
//                }
//                continue_processing = false;
//            }
//            else if (natural_key != KC_TRNS)
//            {
//                if (natural_key & QK_LSFT)
//                {
//                    register_code(KC_LSFT);
//                }
//                register_code(natural_key);
//                continue_processing = false;
//            }
//        }
//        else  // released
//        {
//            if (was_key_shifted[modified_key])
//            {
//                was_key_shifted[modified_key] = false;
//                unregister_code(modified_key);
//                continue_processing = false;
//            }
//            else if (natural_key != KC_TRNS)
//            {
//                unregister_code(natural_key);
//                if (natural_key & QK_LSFT)
//                {
//                    unregister_code(KC_LSFT);
//                }
//                continue_processing = false;
//            }
//        }
//    }
//
//    return continue_processing;
//}
