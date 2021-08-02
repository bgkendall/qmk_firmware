//
//  bgk_keycommands.h
//  qmk-keyboard
//
//  Created by Barnaby on 2021-08-01.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#pragma once

#include "quantum.h"


// Command-Tab simulation
//
void bgkey_register_command_for_tab(void);

bool bgkey_unregister_command_for_tab(void);

bool bgkey_register_forward_command_tab(void);

bool bgkey_register_backward_command_tab(void);


// Send text commands to build this keyboards firmware
//
bool bgkey_make(void);


// Grave/Escape, but with any keys and modifiers
//
bool bgkey_mod_munge(bool pressed,
                     uint16_t natural_key,
                     uint16_t modified_key,
                     uint8_t trigger_modifiers,
                     bool release_modifiers);
