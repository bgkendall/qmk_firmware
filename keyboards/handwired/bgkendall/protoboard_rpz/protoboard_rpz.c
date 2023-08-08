#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE

enum RGB_LAYERS
{
    RGBL_CAPS = 0
};

const rgblight_segment_t PROGMEM rgb_pink_layer[] =
        RGBLIGHT_LAYER_SEGMENTS( {0, RGBLED_NUM, 0, 224, 255} );

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [RGBL_CAPS] = rgb_pink_layer
);

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}

#endif // RGBLIGHT_ENABLE


void keyboard_post_init_kb(void)
{
#ifdef RGBLIGHT_ENABLE
    rgblight_layers = rgb_layers;
#endif // RGBLIGHT_ENABLE
}
