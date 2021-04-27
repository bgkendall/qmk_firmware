//
//  rgb.h
//  qmk-keyboard
//
//  Created by Barnaby on 2020-09-09.
//  © 2020 Barnaby Kendall. All rights reserved.
//

#pragma once

#include "quantum.h"

#ifdef RGBLIGHT_ENABLE

#define BGKRGB_DEGREES_TO_INT(h)    (((h*255UL)/359UL))
#define BGKRGB_PERCENT_TO_INT(s)    (((s*255UL)/100UL))
#define BGKRGB_PCNT_OF_MAX_VALUE(v) ((RGBLIGHT_LIMIT_VAL*(v)*10UL))/1000UL
#define BGKRGB_HSV_MAC_TO_QMK(h,s,v) BGKRGB_DEGREES_TO_INT(h),\
                                     BGKRGB_PERCENT_TO_INT(s),\
                                     BGKRGB_PCNT_OF_MAX_VALUE(v)
#define BGKRGB_RAINBOW_PIXEL(p)     { p, 1, ((255UL/RGBLED_NUM) *  p), 255, 255 }

#define HSV_1PASSWORD           BGKRGB_HSV_MAC_TO_QMK(209,  0,100)
#define HSV_MS_EXCEL            BGKRGB_HSV_MAC_TO_QMK(148, 84, 50)
#define HSV_MS_ONENOTE          BGKRGB_HSV_MAC_TO_QMK(278, 85, 64)
#define HSV_MS_OUTLOOK          BGKRGB_HSV_MAC_TO_QMK(208, 92, 83)
#define HSV_MS_PROJECT          BGKRGB_HSV_MAC_TO_QMK(148, 87, 47)
#define HSV_MS_TEAMS            BGKRGB_HSV_MAC_TO_QMK(235, 58, 74)
#define HSV_MS_WORD             BGKRGB_HSV_MAC_TO_QMK(215, 84, 76)
#define HSV_REMOTE_SESSION      BGKRGB_HSV_MAC_TO_QMK( 16,100, 90)
#define HSV_SAFARI              BGKRGB_HSV_MAC_TO_QMK(193, 93, 93)
#define HSV_TOGGL               BGKRGB_HSV_MAC_TO_QMK(307, 54, 88)
#define HSV_TOGGLE_TOGGL        BGKRGB_HSV_MAC_TO_QMK(358, 94, 86)

#define HSV_ORANGERED           9, 255, 255


#define BGKRGB_ALL(c) RGBLIGHT_LAYER_SEGMENTS( {0, RGBLED_NUM, c} )

const rgblight_segment_t PROGMEM bgkrgb_white_layer[]       = BGKRGB_ALL(HSV_WHITE);
const rgblight_segment_t PROGMEM bgkrgb_red_layer[]         = BGKRGB_ALL(HSV_RED);
const rgblight_segment_t PROGMEM bgkrgb_coral_layer[]       = BGKRGB_ALL(HSV_CORAL);
const rgblight_segment_t PROGMEM bgkrgb_orangered_layer[]   = BGKRGB_ALL(HSV_ORANGERED);
const rgblight_segment_t PROGMEM bgkrgb_orange_layer[]      = BGKRGB_ALL(HSV_ORANGE);
const rgblight_segment_t PROGMEM bgkrgb_goldenrod_layer[]   = BGKRGB_ALL(HSV_GOLDENROD);
const rgblight_segment_t PROGMEM bgkrgb_gold_layer[]        = BGKRGB_ALL(HSV_GOLD);
const rgblight_segment_t PROGMEM bgkrgb_yellow_layer[]      = BGKRGB_ALL(HSV_YELLOW);
const rgblight_segment_t PROGMEM bgkrgb_chartreuse_layer[]  = BGKRGB_ALL(HSV_CHARTREUSE);
const rgblight_segment_t PROGMEM bgkrgb_green_layer[]       = BGKRGB_ALL(HSV_GREEN);
const rgblight_segment_t PROGMEM bgkrgb_springgreen_layer[] = BGKRGB_ALL(HSV_SPRINGGREEN);
const rgblight_segment_t PROGMEM bgkrgb_turquoise_layer[]   = BGKRGB_ALL(HSV_TURQUOISE);
const rgblight_segment_t PROGMEM bgkrgb_teal_layer[]        = BGKRGB_ALL(HSV_TEAL);
const rgblight_segment_t PROGMEM bgkrgb_cyan_layer[]        = BGKRGB_ALL(HSV_CYAN);
const rgblight_segment_t PROGMEM bgkrgb_azure_layer[]       = BGKRGB_ALL(HSV_AZURE);
const rgblight_segment_t PROGMEM bgkrgb_blue_layer[]        = BGKRGB_ALL(HSV_BLUE);
const rgblight_segment_t PROGMEM bgkrgb_purple_layer[]      = BGKRGB_ALL(HSV_PURPLE);
const rgblight_segment_t PROGMEM bgkrgb_magenta_layer[]     = BGKRGB_ALL(HSV_MAGENTA);
const rgblight_segment_t PROGMEM bgkrgb_pink_layer[]        = BGKRGB_ALL(HSV_PINK);


#ifndef BGKRGB_INDICATOR

    // If BGKRGB_INDICATOR has been defined, use it as is.

#ifdef RGBLIGHT_INDICATOR

    // If RGBLIGHT_INDICATOR has been defined, use it to create indictor layers for each named
    // colour. Note that RGBLIGHT_INDICATOR can only define a continuous series of LEDs.

    #define BGKRGB_INDICATOR(c) RGBLIGHT_LAYER_SEGMENTS ( { RGBLIGHT_INDICATOR, c } )

#else

    // If RGBLIGHT_INDICATOR has not been defined, create indicator layers with the first and last
    // LED.

    #define BGKRGB_INDICATOR(c) RGBLIGHT_LAYER_SEGMENTS ( {0, 1, c}, {RGBLED_NUM-1, 1, c} )

#endif /* RGBLIGHT_INDICATOR */
#endif /* BGKRGB_INDICATOR */

const rgblight_segment_t PROGMEM bgkrgb_white_indicator_layer[]       = BGKRGB_INDICATOR(HSV_WHITE);
const rgblight_segment_t PROGMEM bgkrgb_red_indicator_layer[]         = BGKRGB_INDICATOR(HSV_RED);
const rgblight_segment_t PROGMEM bgkrgb_coral_indicator_layer[]       = BGKRGB_INDICATOR(HSV_CORAL);
const rgblight_segment_t PROGMEM bgkrgb_orangered_indicator_layer[]   = BGKRGB_INDICATOR(HSV_ORANGERED);
const rgblight_segment_t PROGMEM bgkrgb_orange_indicator_layer[]      = BGKRGB_INDICATOR(HSV_ORANGE);
const rgblight_segment_t PROGMEM bgkrgb_goldenrod_indicator_layer[]   = BGKRGB_INDICATOR(HSV_GOLDENROD);
const rgblight_segment_t PROGMEM bgkrgb_gold_indicator_layer[]        = BGKRGB_INDICATOR(HSV_GOLD);
const rgblight_segment_t PROGMEM bgkrgb_yellow_indicator_layer[]      = BGKRGB_INDICATOR(HSV_YELLOW);
const rgblight_segment_t PROGMEM bgkrgb_chartreuse_indicator_layer[]  = BGKRGB_INDICATOR(HSV_CHARTREUSE);
const rgblight_segment_t PROGMEM bgkrgb_green_indicator_layer[]       = BGKRGB_INDICATOR(HSV_GREEN);
const rgblight_segment_t PROGMEM bgkrgb_springgreen_indicator_layer[] = BGKRGB_INDICATOR(HSV_SPRINGGREEN);
const rgblight_segment_t PROGMEM bgkrgb_turquoise_indicator_layer[]   = BGKRGB_INDICATOR(HSV_TURQUOISE);
const rgblight_segment_t PROGMEM bgkrgb_teal_indicator_layer[]        = BGKRGB_INDICATOR(HSV_TEAL);
const rgblight_segment_t PROGMEM bgkrgb_cyan_indicator_layer[]        = BGKRGB_INDICATOR(HSV_CYAN);
const rgblight_segment_t PROGMEM bgkrgb_azure_indicator_layer[]       = BGKRGB_INDICATOR(HSV_AZURE);
const rgblight_segment_t PROGMEM bgkrgb_blue_indicator_layer[]        = BGKRGB_INDICATOR(HSV_BLUE);
const rgblight_segment_t PROGMEM bgkrgb_purple_indicator_layer[]      = BGKRGB_INDICATOR(HSV_PURPLE);
const rgblight_segment_t PROGMEM bgkrgb_magenta_indicator_layer[]     = BGKRGB_INDICATOR(HSV_MAGENTA);
const rgblight_segment_t PROGMEM bgkrgb_pink_indicator_layer[]        = BGKRGB_INDICATOR(HSV_PINK);


void bgkrgb_set_from_highest_layer(layer_state_t state, uint16_t lowest_layer, uint16_t highest_layer)
{
    for (int l = highest_layer; l >= lowest_layer; l--)
    {
        rgblight_set_layer_state(l, get_highest_layer(state) == l);
    }
}


#endif /* RGB enabled */
