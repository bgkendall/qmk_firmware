//
//  bgk_cmd-tab.h
//  qmk-keyboard
//
//  Created by Barnaby on 2021-02-19.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#pragma once

#include "quantum.h"


void bgkey_register_command_for_tab(void);

void bgkey_register_forward_command_tab(void);

void bgkey_register_backward_command_tab(void);

void bgkey_unregister_command_for_tab(void);

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
//                bgkey_register_forward_command_tab();
//                result = false;
//                break;
//            case KC_CMDTAB_BACKWARD:
//                bgkey_register_backward_command_tab();
//                result = false;
//                break;
//            default:
//                break;
//        }
//    }
//
//    return result;
//}
