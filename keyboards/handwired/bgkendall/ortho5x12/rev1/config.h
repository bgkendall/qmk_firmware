#pragma once

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0001

/* key matrix pins                                                             Pro Micro pins */
#define MATRIX_ROW_PINS { D2, D7, B3, C6, E6, NO_PIN }                      // RX1, 6, 14, 5, 7, dummy row for encoder
#define MATRIX_COL_PINS { D3, B5, B6, B2, F7, B1, F4, D1, F5, D0, F6, D4 }  // TX0, 9, 10, 16, A0, 15, A3, 2, A2, 3, A1, 4

/* encoder pins and settings */
#define ENCODERS_PAD_A { D5 }                                               // TxLED
#define ENCODERS_PAD_B { B0 }                                               // RxLED

#define RGB_DI_PIN B4                                                       // 8
