#include "gherkin.h"

//#include "users/bgkendall/rgb.h"

//const rgblight_segment_t* const PROGMEM gherkin_rgb_layers[] = RGBLIGHT_LAYERS_LIST
//(
//    [0 ... 1]  = bgkrgb_white_layer,
//    [2]        = bgkrgb_cyan_layer,
//    [3 ... 4]  = bgkrgb_magenta_layer,
//    [5]        = bgkrgb_yellow_layer,
//    [6]        = bgkrgb_orange_layer,
//    [7]        = bgkrgb_purple_layer,
//
//    [RGBL_OK]   = bgkrgb_green_layer,
//    [RGBL_CAPS] = bgkrgb_red_layer
//);

void keyboard_post_init_user(void)
{
    // Turn off lighting:
    backlight_disable();
    rgblight_disable();

    // Enable the LED layers:
//    rgblight_layers = gherkin_rgb_layers;

    // Flash OK layer:
//    rgblight_blink_layer(RGBL_OK, 1000);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
//    bgkrgb_set_from_highest_layer(state, 2, 7);

    return state;
}

bool led_update_user(led_t led_state)
{
//    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);

    return true;
}

bool process_custom_keycode(uint16_t keycode, bool pressed)
{
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    return process_custom_keycode(keycode, record->event.pressed);
};
