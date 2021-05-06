//
//  bgk_rgb.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-04-19.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#include "bgk_rgb.h"


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


void bgkrgb_set_all_layers(uint16_t on_layer, uint16_t lowest_layer, uint16_t highest_layer)
{
    for (uint16_t layer = highest_layer; layer >= lowest_layer; layer--)
    {
        rgblight_set_layer_state(layer, layer == on_layer);
    }
}

void bgkrgb_set_from_highest_layer(layer_state_t state, uint16_t lowest_layer, uint16_t highest_layer)
{
    bgkrgb_set_all_layers(get_highest_layer(state), lowest_layer, highest_layer);
}

void bgkrgb_blink_highest_layer(layer_state_t state, uint16_t lowest_layer, uint16_t highest_layer)
{
    uint16_t current_highest_layer = get_highest_layer(state);

    bgkrgb_set_all_layers(-1, lowest_layer, highest_layer); // All RGB layers off

    if (current_highest_layer >= lowest_layer && current_highest_layer <= highest_layer)
    {
        rgblight_blink_layer(current_highest_layer, BGKRGB_BLINK_TIME);
    }
}
