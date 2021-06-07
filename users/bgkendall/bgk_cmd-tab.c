//
//  bgk_cmd-tab.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-06-06.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#include "bgk_cmd-tab.h"


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
