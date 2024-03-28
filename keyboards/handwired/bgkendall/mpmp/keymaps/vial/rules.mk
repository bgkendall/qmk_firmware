VIA_ENABLE = yes
VIAL_ENABLE = yes

ifeq ($(MCU), atmega32u4)

	QMK_SETTINGS = no
	GRAVE_ESC_ENABLE = no

endif
