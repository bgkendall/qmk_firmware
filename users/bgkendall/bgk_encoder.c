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

#include "bgk_keycommands.h"

#include "debug.h"


void debug_encoder_event(uint8_t index, bool clockwise, keyevent_t event)
{
    dprintf("Sending encoder %d %s turn as %s event: (%d, %d) with layers ",
            index, (clockwise ? "clockwise" : "anticlock" ),
            (event.pressed ? "-press-" : "release"), event.key.row, event.key.col);
    debug_bin32(layer_state);
    dprint("\n");
}


#if defined(ENCODERS_CLOCKWISE_KEY) || defined(ENCODERS_KEY_LAYER)


#ifdef ENCODERS_CLOCKWISE_KEY

static keypos_t encoder_keys[2][BGK_NUM_ENCODERS] = { ENCODERS_ANTI_CLOCKWISE_KEY, ENCODERS_CLOCKWISE_KEY };

keypos_t get_key_position(uint8_t index, bool clockwise)
{
    return encoder_keys[(clockwise ? 1 : 0)][index];
}

#define PRE_ACTION  // No-op
#define POST_ACTION // No-op

#endif // ENCODERS_CLOCKWISE_KEY


#ifdef ENCODERS_KEY_LAYER

static uint8_t encoder_layer = ENCODERS_KEY_LAYER;
// TODO: Allow configuration of which keys on the encoder layer map to the actions for a key layer.

keypos_t get_key_position(uint8_t index, bool clockwise)
{
    uint8_t current_layer = get_highest_layer(layer_state);

    return (keypos_t)
        {
            (current_layer % MATRIX_COLS),
            ((clockwise ? 0 : 1) + ((current_layer / MATRIX_COLS) * 2))
        };
}

#define PRE_ACTION  layer_on(encoder_layer);
#define POST_ACTION layer_off(encoder_layer);

#endif // ENCODERS_KEY_LAYER


enum ENCODER_STATES
{
    OFF = 0,
    ANTICLOCKWISE,
    CLOCKWISE,
};

static uint8_t encoder_state[BGK_NUM_ENCODERS] = {OFF};


void do_encoder_action(uint8_t index, bool clockwise, keyevent_t event)
{
    PRE_ACTION
    debug_encoder_event(index, clockwise, event);
    action_exec(event);
    POST_ACTION
}

void encoder_action_register(uint8_t index, bool clockwise)
{
    keyevent_t encoder_event =
        (keyevent_t)
        {
            .key = get_key_position(index, clockwise),
            .pressed = true,
            .time = (timer_read() | 1)
        };

    do_encoder_action(index, clockwise, encoder_event);
    encoder_state[index] = (clockwise ? CLOCKWISE : ANTICLOCKWISE);
}

void encoder_action_unregister(void)
{
    for (int index = 0; index < BGK_NUM_ENCODERS; index++)
    {
        if (encoder_state[index] != OFF)
        {
            keyevent_t encoder_event =
                (keyevent_t)
                {
                    .key = get_key_position(index, (encoder_state[index] == CLOCKWISE)),
                    .pressed = false,
                    .time = (timer_read() | 1)
                };

            do_encoder_action(index, (encoder_state[index] == CLOCKWISE), encoder_event);
            encoder_state[index] = OFF;
        }
    }
}

void matrix_scan_user(void)
{
    encoder_action_unregister();
    bgkey_unregister_command_for_tab(false);
}

bool encoder_update_user(uint8_t index, bool clockwise)
{
    encoder_action_register(index, clockwise);
    return false;
};


#else  // ! ENCODERS_CLOCKWISE_KEY || ENCODERS_KEY_LAYER


#include "mousekey.h"


bool (*bgkencoder_custom_keycode_handler)(uint16_t, bool) = NULL;


void bgkencoder_init(bool (*custom_keycode_handler)(uint16_t, bool))
{
    bgkencoder_custom_keycode_handler = custom_keycode_handler;
}

bool encoder_update_user(uint8_t encoder_index, bool clockwise)
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

    return false;
}


#endif // ENCODERS_CLOCKWISE_KEY || ENCODERS_KEY_LAYER
