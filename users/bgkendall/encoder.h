//
//  encoder.h
//  qmk-keyboard
//
//  Created by Barnaby on 2020-10-10.
//  © 2020 Barnaby Kendall. All rights reserved.
//

#pragma once

#ifdef ENCODERS_PAD_A

#include "quantum.h"
#include "mousekey.h"

static pin_t bgkencoders_pad_a[] = ENCODERS_PAD_A;
const uint16_t encodermaps[][sizeof(bgkencoders_pad_a)/sizeof(pin_t)][2];

void bgkencoder_update(uint8_t encoder_index, bool clockwise, bool (*custom_keycode_handler)(uint16_t,bool))
{
    const uint16_t keycode =
        pgm_read_word(&encodermaps[get_highest_layer(layer_state)][encoder_index][(clockwise ? 1 : 0)]);

    bool handle_update = true;

    if (custom_keycode_handler != NULL)
    {
        handle_update = (*custom_keycode_handler)(keycode, /* pressed = */true);
    }

    if (handle_update)
    {
#ifdef BACKLIGHT_ENABLE
        if (keycode >= BL_ON && keycode <= BL_BRTG)
        {
            // Special handling for backlight key codes:
            keyrecord_t record = { .event = (keyevent_t){ .pressed = true } };
            process_backlight(keycode, &record);
        }
        else
#endif
#ifdef RGBLIGHT_ENABLE
        if (keycode >= RGB_TOG && keycode <= RGB_MODE_RGBTEST)
        {
            // Special handling for RGB key codes:
            keyrecord_t record = { .event = (keyevent_t){ .pressed = true } };
            process_rgb(keycode, &record);
        }
        else
#endif
#ifdef MOUSEKEY_ENABLE
        if (IS_MOUSEKEY(keycode))
        {
            // Special handling for mouse key codes:
            mousekey_on(keycode);
            mousekey_send();
            mousekey_off(keycode);
            mousekey_send();
        }
        else
#endif
        {
            tap_code16(keycode);
        }
    }
}

void encoder_update_user(uint8_t encoder_index, bool clockwise)
{
    bgkencoder_update(encoder_index, clockwise, &process_custom_keycode);
}

# endif /* encoders_pad_a */
