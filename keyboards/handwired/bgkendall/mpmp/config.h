#pragma once

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
#define RGBLIGHT_LAYER_KEY {0,4}
