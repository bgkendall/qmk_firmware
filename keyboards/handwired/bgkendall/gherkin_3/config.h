/*
Copyright 2022 bgkendall

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0003
//#define MANUFACTURER    40 Percent Club / bgkendall
#define PRODUCT         Gherkin+3

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/* pin-out */
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6, D2 }
#define MATRIX_COL_PINS { B4, E6, D7, C6, D4, D0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* encoder pins and settings */
#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 3

#define BACKLIGHT_PIN B5
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 8
#define BACKLIGHT_BREATHING
#endif

/* RGB settings */
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#define RGBLED_NUM 1
#define RGBLIGHT_SLEEP
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 16
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
#endif

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

#define COMBO_COUNT 12
#define COMBO_TERM  30

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* Miryoku settings */
#define MIRYOKU_ALPHAS_AVERAK
#define MIRYOKU_TAP_QWERTY
#define MIRYOKU_CLIPBOARD_MAC
#define MIRYOKU_NAV_INVERTEDT
#define MIRYOKU_LAYER_NAV MIRYOKU_ALTERNATIVES_NAV_INVERTEDT_FLIP
