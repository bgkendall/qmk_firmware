
uint16_t SPECIAL_SHIFT_KEYS[MATRIX_ROWS * MATRIX_COLS];
uint16_t SPECIAL_SHIFT_KEY_COUNT = 0;

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    bool result = true;

    if (record->event.pressed &&
        !IS_MOD(keycode) &&
        get_highest_layer(layer_state) == KL_SHIFT &&
        pgm_read_word(&keymaps[KL_SHIFT][record->event.key.row][record->event.key.col]) == KC_TRNS)
    {
        register_code16(S(keycode));
        result = false;
    }
//            bool special_key = false;
//            for (uint16_t index = 0; index < SPECIAL_SHIFT_KEY_COUNT; index++)
//            {
//                if (keycode == SPECIAL_SHIFT_KEYS[index])
//                {
//                    special_key = true;
//                    break;
//                }
//            }
//
//            if (!special_key)
//            {
//                register_code16(S(keycode));
//                result = false;
//            }
//        }
//    }

    return result;
}
