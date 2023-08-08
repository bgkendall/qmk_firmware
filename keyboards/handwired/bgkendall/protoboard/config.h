#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x424B  // "BK"
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0010
#define MANUFACTURER    bgkendall
#define PRODUCT         protoboard
#define DESCRIPTION     B.G. Kendall Prototype Pro Micro Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/* key matrix pins                             ProMicro pins */
#define MATRIX_ROW_PINS { F6, F7, B3, B4 }  // A1, A0, 14, 8
#define MATRIX_COL_PINS { B2, B1, B5     }  // 16, 15, 9
#define UNUSED_PINS

/* encoder pins and settings */
#define ENCODERS_PAD_A { F5 }               // A2
#define ENCODERS_PAD_B { F4 }               // A3

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_PIN B6                    // 10
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 16
#define BACKLIGHT_BREATHING
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN D7                   // 6
#ifdef RGB_DI_PIN
/* #define RGBLIGHT_INDICATOR 1,1 */
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 6
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
#endif

#endif
