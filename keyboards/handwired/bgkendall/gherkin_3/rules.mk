# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MAGIC_ENABLE = no           # "Magic" keyboard setting support
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
ENCODER_ENABLE = yes        # Enable rotary encoder support
ENCODER_MAP_ENABLE = yes
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
CAPS_WORD_ENABLE = yes      # Caps Word support
COMBO_ENABLE = yes          # Combo support
KEY_OVERRIDE_ENABLE = yes   # Key Override support
TAP_DANCE_ENABLE = yes      # Tap Dance support
LTO_ENABLE = yes            # Link Time Optimization
AVR_USE_MINIMAL_PRINTF = yes # Use smaller printf implementations from AVRs libc
AUTO_SHIFT_ENABLE = yes

LAYOUTS = ortho_4x10

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += users/bgkendall/bgk_rgb.c
endif

SRC += users/bgkendall/bgk_keycommands.c
