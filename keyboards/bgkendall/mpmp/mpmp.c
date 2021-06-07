#include "mpmp.h"

#ifdef RGBLIGHT_ENABLE

#include "bgk_rgb.h"

layer_state_t layer_state_set_kb(layer_state_t state)
{
    bgkrgb_set_from_highest_layer(state, KL_CALC, RGBL_OK-1);

    return state;
}

bool led_update_kb(led_t led_state)
{
    rgblight_set_layer_state(RGBL_CAPS, led_state.caps_lock);
    return true;
}

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
    [KL_CALC]      = bgkrgb_blue_indicator_layer,
    [KL_APP]       = mpmp_app_layer,
    [KL_FN]        = bgkrgb_orangered_layer,
    [KL_LED]       = bgkrgb_white_indicator_layer,
    [KL_SHIFT]     = bgkrgb_springgreen_indicator_layer,
    [RGBL_OK]      = mpmp_ok_layer,
    [RGBL_CAPS]    = bgkrgb_pink_indicator_layer,
    [RGBL_CMDTAB]  = bgkrgb_red_indicator_layer
);

void keyboard_post_init_kb(void)
{
    // Enable the LED layers:
    rgblight_layers = mpmp_rgb_layers;

    // Turn off lighting:
    rgblight_disable();

    // Flash OK layer:
    rgblight_blink_layer(RGBL_OK, 1800);
}

#endif // RGBLIGHT_ENABLE


void matrix_scan_kb(void)
{
    bgkey_unregister_command_for_tab();
    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record)
{
    bool result = true;

    if (record->event.pressed)
    {
        switch (keycode)
        {
            case CK_CMDTAB_FORWARD:
                bgkey_register_forward_command_tab();
                result = false;
                break;
            case CK_CMDTAB_BACKWARD:
                bgkey_register_command_for_tab();
                tap_code16(S(KC_TAB));
                result = false;
                break;
            default:
                break;
        }
    }

    return result;
}
