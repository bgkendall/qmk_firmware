ifeq ($(strip $(ENCODER_ENABLE)), yes)
    ifneq ($(strip $(VIAL_ENCODERS_ENABLE)), yes)
        SRC += bgk_encoder.c
    endif
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += bgk_rgb.c
endif

ifeq ($(strip $(RGB_STATUS_WS2812_ENABLE)), yes)

    SRC += bgk_status_ws2812.c bgk_ws2812_driver.c
    CFLAGS += -DRGB_STATUS_WS2812_ENABLE

endif


SRC += bgk_keycommands.c bgk_keycodes.c
