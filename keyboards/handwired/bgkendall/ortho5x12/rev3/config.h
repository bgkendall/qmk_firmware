#pragma once

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0003

/* key matrix pins */
#define MATRIX_ROW_PINS { GP29, GP27, GP8, GP1, GP7, NO_PIN }
#define MATRIX_COL_PINS { GP0, GP6, GP9, GP3, GP4, GP2, GP5, GP26, GP18, GP20, GP19, GP10 }

/* encoder pins and settings */
#define ENCODERS_PAD_A { GP12 }
#define ENCODERS_PAD_B { GP13 }

#define RGB_DI_PIN GP28
