#include QMK_KEYBOARD_H


#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)

#include "bgk_rgb.h"

const rgblight_segment_t PROGMEM mpmp_app_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    {  0, 1, HSV_TOGGLE_TOGGL },
    {  1, 1, HSV_1PASSWORD },
    {  2, 1, HSV_MS_OUTLOOK },
    {  3, 1, HSV_MS_TEAMS },
    {  4, 1, HSV_MS_ONENOTE },
    {  5, 1, HSV_REMOTE_SESSION },
    {  6, 1, HSV_SAFARI },
    {  7, 1, HSV_MS_WORD },
    {  8, 1, HSV_MS_EXCEL },
    {  9, 1, HSV_MS_PROJECT },

    { 10, 2, HSV_CORAL }
);

const rgblight_segment_t PROGMEM mpmp_ok_layer[] = RGBLIGHT_LAYER_SEGMENTS
(
    BGKRGB_RAINBOW_PIXEL(0),
    BGKRGB_RAINBOW_PIXEL(1),
    BGKRGB_RAINBOW_PIXEL(2),
    BGKRGB_RAINBOW_PIXEL(3),
    BGKRGB_RAINBOW_PIXEL(4),
    BGKRGB_RAINBOW_PIXEL(5),
    BGKRGB_RAINBOW_PIXEL(6),
    BGKRGB_RAINBOW_PIXEL(7),
    BGKRGB_RAINBOW_PIXEL(8),
    BGKRGB_RAINBOW_PIXEL(9),

    { 10, 2, HSV_WHITE }
);

const rgblight_segment_t* const PROGMEM mpmp_rgb_layers[] = RGBLIGHT_LAYERS_LIST
(
    [RGBL_F] = bgkrgb_white_indicator_layer,
    [RGBL_R] = bgkrgb_red_indicator_layer,
    [RGBL_K] = bgkrgb_coral_indicator_layer,
    [RGBL_J] = bgkrgb_orangered_indicator_layer,
    [RGBL_O] = bgkrgb_orange_indicator_layer,
    [RGBL_N] = bgkrgb_goldenrod_indicator_layer,
    [RGBL_D] = bgkrgb_gold_indicator_layer,
    [RGBL_L] = bgkrgb_yellow_indicator_layer,
    [RGBL_H] = bgkrgb_chartreuse_indicator_layer,
    [RGBL_G] = bgkrgb_green_indicator_layer,
    [RGBL_S] = bgkrgb_springgreen_indicator_layer,
    [RGBL_Q] = bgkrgb_turquoise_indicator_layer,
    [RGBL_E] = bgkrgb_teal_indicator_layer,
    [RGBL_C] = bgkrgb_cyan_indicator_layer,
    [RGBL_A] = bgkrgb_azure_indicator_layer,
    [RGBL_B] = bgkrgb_blue_indicator_layer,
    [RGBL_I] = bgkrgb_purple_indicator_layer,
    [RGBL_M] = bgkrgb_magenta_indicator_layer,
    [RGBL_P] = bgkrgb_pink_indicator_layer,

    [RGBL_APP]  = mpmp_app_layer,
    [RGBL_OK]   = mpmp_ok_layer,
    [RGBL_CAPS] = bgkrgb_pink_indicator_layer
);

int16_t get_rgb_layer(layer_state_t state)
{
    return (keymap_key_to_keycode(get_highest_layer(state), (keypos_t)RGBLIGHT_LAYER_KEY) - KC_A);
}

layer_state_t layer_state_set_kb(layer_state_t state)
{
    bgkrgb_set_all_layers(get_rgb_layer(state), RGBL_A, RGBL_APP);

    return state;
}

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}

#endif // RGBLIGHT_ENABLED && RGBLIGHT_LAYERS


void keyboard_post_init_kb(void)
{
#ifdef CONSOLE_ENABLE
    // Enable/disable debugging:
    debug_enable = true;
    //debug_matrix = true;
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    // Enable the LED layers:
    rgblight_layers = mpmp_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1800);
#endif
}
