//
//  bgk_encoder.c
//  qmk-keyboard
//
//  Created by Barnaby on 2021-04-19.
//  © 2020 Barnaby Kendall. All rights reserved.
//

#include "bgk_encoder.h"

#include "mousekey.h"


bool (*bgkencoder_custom_keycode_handler)(uint16_t,bool) = NULL;


void bgkencoder_init(bool (*custom_keycode_handler)(uint16_t,bool))
{
    bgkencoder_custom_keycode_handler = custom_keycode_handler;
}

void bgkencoder_update(uint8_t encoder_index, bool clockwise)
{
    const uint16_t keycode =
        pgm_read_word(&encodermaps[get_highest_layer(layer_state)][encoder_index][(clockwise ? 1 : 0)]);

    bool handle_update = true;

    if (bgkencoder_custom_keycode_handler != NULL)
    {
        handle_update = (*bgkencoder_custom_keycode_handler)(keycode, /* pressed = */true);
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
    bgkencoder_update(encoder_index, clockwise);
}
