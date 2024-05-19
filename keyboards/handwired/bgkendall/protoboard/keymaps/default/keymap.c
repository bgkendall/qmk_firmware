#include QMK_KEYBOARD_H

enum LAYERS
{
    KL_DEFAULT = 0,
    KL_FUNC,
    KL_FUNC_LOCK,
    KL_DEFAULT_COPY,
    KL_RGB,
    KL_BACKLIGHT,
    KL_RESET,
    RGB_LAYER_OK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [KL_DEFAULT ... KL_DEFAULT_COPY] = LAYOUT
    (
        RGB_TOG,            RGB_MOD,
        KC_3,               KC_4,
        KC_5,               KC_6,
        KC_X
    ),

    [KL_FUNC ... KL_FUNC_LOCK] = LAYOUT
    (
        KC_E,               KC_F,
        KC_C,               KC_D,
        TO(KL_FUNC_LOCK),   LM(KL_DEFAULT_COPY, MOD_LSFT),
        TO(KL_DEFAULT)
    ),

    [KL_RGB] = LAYOUT
    (
        RGB_RMOD,           RGB_MOD,
        RGB_HUI,            RGB_SAI,
        TO(KL_BACKLIGHT),   KC_LSFT,
        RGB_TOG
    ),

    [KL_BACKLIGHT] = LAYOUT
    (
        XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,
        TO(KL_RESET),       BL_BRTG,
        BL_TOGG
    ),

    [KL_RESET] = LAYOUT
    (
        XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,
        TO(KL_DEFAULT),     XXXXXXX,
        QK_BOOT
	)
};

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0 ... KL_RESET] = { ENCODER_CCW_CW(KC_VOLD,  KC_VOLU) }
};

#endif // ENCODER_MAP_ENABLE

// const rgblight_segment_t* const PROGMEM prototype_rgb_layers[] = RGBLIGHT_LAYERS_LIST
// (
//     [KL_DEFAULT]        = bgkrgb_red_indicator_layer,
//     [KL_FUNC]           = bgkrgb_orange_indicator_layer,
//     [KL_FUNC_LOCK]      = bgkrgb_yellow_indicator_layer,
//     [KL_DEFAULT_COPY]   = bgkrgb_purple_indicator_layer,
//     [KL_RGB]            = bgkrgb_green_indicator_layer,
//     [KL_BACKLIGHT]      = bgkrgb_blue_indicator_layer,
//     [KL_RESET]          = bgkrgb_orangered_layer,
//     [RGB_LAYER_OK]      = bgkrgb_green_layer
// );

void keyboard_post_init_user(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    debug_mouse = false;
#endif

    // Turn off lighting:
    backlight_disable();
    rgblight_disable();

    // Enable the LED layers:
    // rgblight_layers = prototype_rgb_layers;

    // Flash OK layer:
    // rgblight_blink_layer(RGB_LAYER_OK, 1000);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
//     bgkrgb_set_from_highest_layer(state, KL_DEFAULT+1, KL_RESET);
//
//     if (get_highest_layer(state) == KL_DEFAULT)
//     {
//         rgblight_blink_layer(KL_DEFAULT, 333);
//     }

    return state;
}
