#pragma once

#include "bgk_keycodes.h"

#ifdef BACKLIGHT_PIN
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 8
#endif

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#undef RGBLED_NUM
#define RGBLED_NUM 2
#define RGBLIGHT_INDICATOR 1,1
#define RGBLIGHT_SLEEP
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 15
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
#endif
