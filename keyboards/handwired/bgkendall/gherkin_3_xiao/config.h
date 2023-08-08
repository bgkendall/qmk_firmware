// Copyright 2023 bgkendall (@bgkendall)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define MATRIX_MASKED

#define RGBLIGHT_POWER_PIN  GP11

// Set layer indicator key to key that is unused because of nav. switch
#define RGBLIGHT_LAYER_KEY  {3,2}

// For Vial version of QMK:
#define BACKLIGHT_LEVELS 5
