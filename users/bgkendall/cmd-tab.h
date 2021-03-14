//
//  cmd-tab.h
//  qmk-keyboard
//
//  Created by Barnaby on 2021-02-19.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#pragma once

#include "quantum.h"


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

// Example use:
//
//void matrix_scan_user(void)
//{
//    bgkey_unregister_command_for_tab();
//}
//
//bool process_record_user(uint16_t keycode, keyrecord_t* record)
//{
//    bool result = true;
//
//    if (record->pressed)
//    {
//        switch (keycode)
//        {
//            case KC_CMDTAB_FORWARD:
//                bgkey_register_command_for_tab();
//                tap_code16(KC_TAB);
//                result = false;
//                break;
//            case KC_CMDTAB_BACKWARD:
//                bgkey_register_command_for_tab();
//                tap_code16(S(KC_TAB));
//                result = false;
//                break;
//            default:
//                break;
//        }
//    }
//
//    return result;
//}
