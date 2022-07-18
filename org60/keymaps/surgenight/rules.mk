
# QMK Build Options
#   change to "no" to disable the options, or define them in the Makefile in 
#   the appropriate keymap folder that will get included automatically
#
CONSOLE_ENABLE = no         # Enable debugging console
COMMAND_ENABLE = no         # Commands for debug and configuration
TAP_DANCE_ENABLE = yes      # Tap Dance skills
MOUSEKEY_ENABLE = yes       # control over cursor movements and clicks via keycodes/custom functions
EXTRAKEY_ENABLE = yes       # use the system and audio control key codes
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight
KEY_LOCK_ENABLE = yes 

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif


