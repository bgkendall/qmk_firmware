MCU = RP2040
BOOTLOADER = rp2040
BACKLIGHT_DRIVER = software
WS2812_DRIVER = vendor

ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes
RGBLIGHT_SUPPORTED = yes
CONSOLE_ENABLE = no
KEY_OVERRIDE_ENABLE = yes

SRC += bgk_gherkin.c

USER_NAME := bgkendall
