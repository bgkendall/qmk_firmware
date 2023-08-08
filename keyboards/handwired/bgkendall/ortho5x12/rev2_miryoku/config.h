#pragma once

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0003

#undef MATRIX_ROWS
#define MATRIX_ROWS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, F6, B4, D2, E6 }
#define MATRIX_COL_PINS { D3, D7, B5, D0, D4, D1, C6, F7, D5, B3, B2, B6 }

/* encoder pins and settings */
#define ENCODERS_PAD_A { C7 }
#define ENCODERS_PAD_B { F1 }

#define RGB_DI_PIN F5

#define BGKRGB_INDICATOR(c) RGBLIGHT_LAYER_SEGMENTS ( {3, 1, c}, {RGBLED_NUM-3, 1, c} )

/* Miryoku settings */
#define MIRYOKU_ALPHAS_AVERAK
#define MIRYOKU_TAP_QWERTY
#define MIRYOKU_CLIPBOARD_MAC
#define MIRYOKU_NAV_INVERTEDT
#define MIRYOKU_LAYER_NAV MIRYOKU_ALTERNATIVES_NAV_INVERTEDT_FLIP
