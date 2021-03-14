#include "users/bgkendall/cmd-tab.h"
#include "users/bgkendall/encoder.h"


const uint16_t PROGMEM encodermaps[][1][2] =
{
    [KL_NUM]  = { { keymaps[KL_NUM] [2][0], keymaps[KL_NUM] [1][0] } },
    [KL_CALC] = { { keymaps[KL_CALC][2][0], keymaps[KL_CALC][1][0] } },
    [KL_APP]  = { { keymaps[KL_APP] [2][0], keymaps[KL_APP] [1][0] } },
    [KL_FN]   = { { keymaps[KL_FN]  [2][0], keymaps[KL_FN]  [1][0] } },
    [KL_LED]  = { { keymaps[KL_LED] [2][0], keymaps[KL_LED] [1][0] } }
};

void matrix_scan_user(void)
{
    bgkey_unregister_command_for_tab();
}

bool handle_custom_keys(uint16_t keycode, bool pressed)
{
    bool result = true;

    if (pressed)
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

void keyboard_pre_init_user(void)
{
    bgkencoder_init(&handle_custom_keys);
}
