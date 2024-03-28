// Copyright 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID {0x23, 0x36, 0x18, 0x8B, 0x34, 0x31, 0x47, 0x44}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 1 } // Top left and right corners
#define VIAL_UNLOCK_COMBO_COLS { 0, 3 }

#ifndef KEYBOARD_handwired_bgkendall_gherkin_3_micro
  #pragma warning("Incompatible keyboard and keymap")
#endif

// Save space

#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 7

#define VIAL_TAP_DANCE_ENTRIES 4
#define VIAL_COMBO_ENTRIES 5
#define VIAL_KEY_OVERRIDE_ENTRIES 9
