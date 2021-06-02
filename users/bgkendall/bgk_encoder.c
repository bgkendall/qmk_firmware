/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * "ENCODERS_CLOCKWISE_KEY" logic based on
 * keyboards/nightly_boards/.../encoder_action.h/c by Neil Brian Ramirez.
 */

#include "bgk_encoder.h"


#if defined(ENCODERS_CLOCKWISE_KEY) || defined(ENCODERS_KEY_LAYER)

static uint8_t encoder_state[BGK_NUM_ENCODERS] = {0};


#ifdef ENCODERS_CLOCKWISE_KEY

static keypos_t encoder_keys[2][BGK_NUM_ENCODERS] = { ENCODERS_ANTI_CLOCKWISE_KEY, ENCODERS_CLOCKWISE_KEY };

keypos_t get_key_position(uint8_t index, bool clockwise)
{
    return encoder_keys[(clockwise ? 1 : 0)][index];
}

#endif // ENCODERS_CLOCKWISE_KEY

#ifdef ENCODERS_KEY_LAYER

static keypos_t encoder_layers[BGK_NUM_ENCODERS] = { ENCODERS_KEY_LAYER };
// Allow setting of which keys are mapped for each layer **IF** this is needed (test by messing with mapping)

keypos_t get_key_position(uint8_t index, bool clockwise)
{
    set_oneshot_layer(encoder_layers[index], ONESHOT_START);

    return (keypos_t)
    {
        (clockwise ? 0 : 1),
        get_highest_layer(layer_state)
    };
}

#endif // ENCODERS_KEY_LAYER

void encoder_action_register(uint8_t index, bool clockwise)
{
    keyevent_t encoder_event =
        (keyevent_t)
        {
            .key = get_key_position(index, clockwise),
            .pressed = true,
            .time = (timer_read() | 1)
        };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);

    action_exec(encoder_event);
}

void encoder_action_unregister(void)
{
    for (int index = 0; index < BGK_NUM_ENCODERS; index++)
    {
        if (encoder_state[index])
        {
            keyevent_t encoder_event =
                (keyevent_t)
                {
                    .key = get_key_position(index, (encoder_state[index] >> 1)),
                    .pressed = false,
                    .time = (timer_read() | 1)
                };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void matrix_scan_kb(void)
{
    encoder_action_unregister();
    matrix_scan_user();
}

void encoder_update_kb(uint8_t index, bool clockwise)
{
    encoder_action_register(index, clockwise);
};


#else  // ! ENCODERS_CLOCKWISE_KEY || ENCODERS_KEY_LAYER


#include "mousekey.h"


bool (*bgkencoder_custom_keycode_handler)(uint16_t, bool) = NULL;


void bgkencoder_init(bool (*custom_keycode_handler)(uint16_t, bool))
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

void encoder_update_kb(uint8_t encoder_index, bool clockwise)
{
    bgkencoder_update(encoder_index, clockwise);
}


#endif // ENCODERS_CLOCKWISE_KEY || ENCODERS_KEY_LAYER
