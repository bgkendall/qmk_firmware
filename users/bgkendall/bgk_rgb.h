//
//  bgk_rgb.h
//  qmk-keyboard
//
//  Created by Barnaby on 2020-09-09.
//  © 2020 Barnaby Kendall. All rights reserved.
//

#pragma once

#define HSV_VIVIDPINK           0, 224, 255
#define HSV_ORANGERED           9, 255, 255

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#include "quantum.h"


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


#define BGKRGB_ALL(c) RGBLIGHT_LAYER_SEGMENTS( {0, RGBLED_NUM, c} )

extern const rgblight_segment_t PROGMEM bgkrgb_black_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_white_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_red_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_coral_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_orangered_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_orange_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_goldenrod_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_gold_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_yellow_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_chartreuse_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_green_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_springgreen_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_turquoise_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_teal_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_cyan_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_azure_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_blue_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_purple_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_magenta_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_pink_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_vividpink_layer[];


#ifndef BGKRGB_BLINK_TIME

    #define BGKRGB_BLINK_TIME 2500

#endif /* BGKRGB_BLINK_TIME */


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


extern const rgblight_segment_t PROGMEM bgkrgb_black_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_white_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_red_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_coral_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_orangered_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_orange_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_goldenrod_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_gold_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_yellow_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_chartreuse_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_green_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_springgreen_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_turquoise_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_teal_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_cyan_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_azure_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_blue_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_purple_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_magenta_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_pink_indicator_layer[];
extern const rgblight_segment_t PROGMEM bgkrgb_vividpink_indicator_layer[];


void bgkrgb_set_all_layers(uint8_t on_layer, uint8_t lowest_layer, uint8_t highest_layer);
void bgkrgb_set_from_layers(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer);
void bgkrgb_set_from_highest_layer(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer);
void bgkrgb_blink_layer(uint8_t blink_layer, uint8_t lowest_layer, uint8_t highest_layer);
void bgkrgb_blink_highest_layer(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer);


#endif /* RGB light and layers enabled */
