//
//  bgk_rgb.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-04-19.
//  © 2021 Barnaby Kendall. All rights reserved.
//

#ifdef RGBLIGHT_LAYERS

#include "bgk_rgb.h"


const rgblight_segment_t PROGMEM bgkrgb_black_layer[]       = BGKRGB_ALL(HSV_BLACK);
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
const rgblight_segment_t PROGMEM bgkrgb_vividpink_layer[]   = BGKRGB_ALL(HSV_VIVIDPINK);

const rgblight_segment_t PROGMEM bgkrgb_black_indicator_layer[]       = BGKRGB_INDICATOR(HSV_BLACK);
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
const rgblight_segment_t PROGMEM bgkrgb_vividpink_indicator_layer[]   = BGKRGB_INDICATOR(HSV_VIVIDPINK);


void bgkrgb_set_all_layers(uint8_t on_layer, uint8_t lowest_layer, uint8_t highest_layer)
{
    // NOTE: layer must be signed otherwise layer-- could cause failure
    for (int16_t layer = highest_layer; layer >= lowest_layer; layer--)
    {
        rgblight_set_layer_state(layer, layer == on_layer);
    }
}

void bgkrgb_set_from_layers(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer)
{
    // NOTE: layer must be signed otherwise layer-- could cause failure
    for (int16_t layer = lowest_layer; layer <= highest_layer; layer++)
    {
        rgblight_set_layer_state(layer, layer_state_cmp(state, layer));
    }
}

void bgkrgb_set_from_highest_layer(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer)
{
    bgkrgb_set_all_layers(get_highest_layer(state), lowest_layer, highest_layer);
}

void bgkrgb_blink_layer(uint8_t blink_layer, uint8_t lowest_layer, uint8_t highest_layer)
{
    bgkrgb_set_all_layers(highest_layer+1, lowest_layer, highest_layer); // All RGB layers off

    if (blink_layer >= lowest_layer && blink_layer <= highest_layer)
    {
        rgblight_blink_layer(blink_layer, BGKRGB_BLINK_TIME);
    }
}

void bgkrgb_blink_highest_layer(layer_state_t state, uint8_t lowest_layer, uint8_t highest_layer)
{
    bgkrgb_blink_layer(get_highest_layer(state), lowest_layer, highest_layer);
}

#endif /* RGB layers enabled */
