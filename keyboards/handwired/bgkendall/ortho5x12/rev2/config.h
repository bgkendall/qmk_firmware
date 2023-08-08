#pragma once

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0002

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, F6, B4, D2, E6, NO_PIN /* dummy row for encoder */ }
#define MATRIX_COL_PINS { D3, D7, B5, D0, D4, D1, C6, F7, D5, B3, B2, B6 }

/* encoder pins and settings */
#define ENCODERS_PAD_A { C7 }
#define ENCODERS_PAD_B { F1 }

#define RGB_DI_PIN F5
