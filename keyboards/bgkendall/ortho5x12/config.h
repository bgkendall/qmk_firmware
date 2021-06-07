#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x424B  // "BK"
#define PRODUCT_ID      0x005C  // "5.12"
#define DEVICE_VER      0x0001
#define MANUFACTURER    bgkendall
#define PRODUCT         Ortho5x12
#define DESCRIPTION     B.G. Kendall Ortho 5×12

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 12

/* Bootmagic reset key */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 11

/* key matrix pins                                                             Pro Micro pins */
#define MATRIX_ROW_PINS { D2, D7, B3, C6, E6, NO_PIN }                      // RX1, 6, 14, 5, 7, dummy row for encoder
#define MATRIX_COL_PINS { D3, B5, B6, B2, F7, B1, F4, D1, F5, D0, F6, D4 }  // TX0, 9, 10, 16, A0, 15, A3, 2, A2, 3, A1, 4
#define UNUSED_PINS

/* encoder pins and settings */
#define ENCODERS_PAD_A { D5 }                                               // TxLED
#define ENCODERS_PAD_B { B0 }                                               // RxLED

#define ENCODERS_CLOCKWISE_KEY      { {1,5} }
#define ENCODERS_ANTI_CLOCKWISE_KEY { {2,5} }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Use right-hand modifiers for LM() */
#define LAYER_MOD_USE_RIGHT

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* Number of taps before a tap-toggle layer locks */
#define TAPPING_TOGGLE 2

#define RGB_DI_PIN B4                                                       // 8
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 15
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
#endif
