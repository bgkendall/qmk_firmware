#include QMK_KEYBOARD_H

void keyboard_post_init_kb(void)
{
    setPinOutput(GP25);
    writePinHigh(GP25);
}
