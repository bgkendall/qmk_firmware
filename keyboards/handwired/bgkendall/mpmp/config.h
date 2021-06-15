#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x424B  // "BK"
#define PRODUCT_ID      0x4D50  // "MP"
#define DEVICE_VER      0x0001
#define MANUFACTURER    bgkendall
#define PRODUCT         MPMP
#define DESCRIPTION     Madame Pearl’s Macro Pad

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins                                 ProMicro pins */
#define MATRIX_ROW_PINS { F7, D7, E6, B4, B5 }  // A0,  6,  7,  8,  9
#define MATRIX_COL_PINS { B1, D1, C6, D4     }  // 15,  2,  5,  4
#define UNUSED_PINS

/* encoder pins and settings */
#define ENCODERS_PAD_A { D3 }                   // TX0
#define ENCODERS_PAD_B { D2 }                   // RX1

#define ENCODERS_CLOCKWISE_KEY      { {0,1} }
#define ENCODERS_ANTI_CLOCKWISE_KEY { {0,2} }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
// #define BACKLIGHT_PIN B5
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 16
#define BACKLIGHT_BREATHING
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

#define LAYER_MOD_USE_RIGHT

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Number of times a layer toggle key must be tapped */
#define TAPPING_TOGGLE 3

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN F4                           // A3
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
/*
    RGB LEDs snake from top left key:

         1 -->  2 -->  3 --
                           |
      -- 6 <--  5 <--  4 <-
     |
      -> 7 -->  8 -->  9 --
                           |
        12 <-- 11 <-- 10 <-

    LED map numbers them to match the number pad keys 0-9, with Enter/App = 10 and Dot/Fn = 11
 */
#define RGBLIGHT_LED_MAP { 7, 8, 9, 6, 5, 4, 1, 2, 3, 11, 0, 10 }
#define RGBLIGHT_INDICATOR 10, 2
#define RGBLIGHT_HUE_STEP 4
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
#endif

#endif
