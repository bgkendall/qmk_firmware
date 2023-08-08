# MCU name
MCU = atmega32u4

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MAGIC_ENABLE = no           # "Magic" keyboard setting support
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CAPS_WORD_ENABLE = yes
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
COMBO_ENABLE = no           # Combo support
ENCODER_ENABLE = yes        # Enable rotary encoder support
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
MIDI_ENABLE = no            # MIDI support
TAP_DANCE_ENABLE = yes      # Tap Dance support
SPACE_CADET_ENABLE = no     # Space Cadet Shift support
KEY_OVERRIDE_ENABLE = yes   # Key Override support
LTO_ENABLE = yes            # Link Time Optimization
AVR_USE_MINIMAL_PRINTF = yes # Use smaller printf implementations from AVRs libc

#LAYOUTS = ortho_5x12
DEFAULT_FOLDER = handwired/bgkendall/ortho5x12/rev2
USER_NAME := bgkendall
