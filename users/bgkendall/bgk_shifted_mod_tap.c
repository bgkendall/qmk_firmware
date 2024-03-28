//
//  bgk_shifted_mod_tap.c
//
//  © 2024 Barnaby Kendall
//

#include "bgk_shifted_mod_tap.h"

#ifndef BGK_SHIFT_NUM_START
#   define BGK_SHIFT_NUM_START KC_KP_EQUAL_AS400
#endif

#ifndef BGK_SHIFT_SYM_START
#   define BGK_SHIFT_SYM_START (BGK_SHIFT_NUM_START + 10)
#endif


bool bgk_process_shifted_mod_tap(int16_t keycode, keyrecord_t* record)
{
    bool process = true;

    if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) &&
        record->tap.count > 0)
    {
        const int16_t base_keycode = keycode & QK_BASIC_MAX;

        if (base_keycode >= BGK_SHIFT_NUM_START && base_keycode < (BGK_SHIFT_NUM_START+10))
        {
            if (record->event.pressed)
            {
                register_code16(S((base_keycode - BGK_SHIFT_NUM_START) + KC_1));
            }
            else
            {
                unregister_code16(S((base_keycode - BGK_SHIFT_NUM_START) + KC_1));
            }
            process = false;
        }
        else if (base_keycode >= BGK_SHIFT_SYM_START && base_keycode < (BGK_SHIFT_SYM_START+12))
        {
            if (record->event.pressed)
            {
                register_code16(S((base_keycode - BGK_SHIFT_SYM_START) + KC_MINUS));
            }
            else
            {
                unregister_code16(S((base_keycode - BGK_SHIFT_SYM_START) + KC_MINUS));
            }
            process = false;
        }
    }

    return process;
}
