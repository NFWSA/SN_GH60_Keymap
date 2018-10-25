#include "org60.h"
#include "action_layer.h"

// Keyboard Layers
enum keyboard_layers {
	BASE_ = 0,     // Base Layer
	COLEMAK_,  // Calemak Base Layer
	//_DVORAK,   // Dvorak Base Layer
	FUNC_,     // Function Layer
	MOUSE_,    // Mouse Control Layer
	LEFT_,     // Left Hand Control Layer
};

enum custom_tap_dance {
	TD_NAME,
	TD_PHONE,
};

static uint8_t light_song[] = {
	5, 1, 3, 4, 0, 2, 2, 3, 1, 5, 3
};

static uint8_t blFlag = 0;
static int8_t blStep = 1;

void dance_name_finish(qk_tap_dance_state_t *state, void *user_data)
{
	int n = (state->count - 1) % 4;
	switch (n) {
		case 0:
			SEND_STRING("SurgeNight");
			break;
		case 1:
			SEND_STRING("NFWSA");
			break;
		case 2:
			SEND_STRING("surgenight@hotmail.com");
			break;
		case 3:
			SEND_STRING("fuermosi007@qq.com");
			break;
	}
}

void dance_phone_finish(qk_tap_dance_state_t *state, void *user_data)
{
	int n = (state->count - 1) % 2;
	switch (n) {
		case 0:
			SEND_STRING("18810964913");
			break;
		case 1:
			SEND_STRING("17778076537");
			break;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	// ACTION_TAP_DANCE_FN_ADVANCED(each  finish  reset)
	[TD_NAME] = ACTION_TAP_DANCE_FN(dance_name_finish),
	[TD_PHONE] = ACTION_TAP_DANCE_FN(dance_phone_finish),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  LAYOUT(
   // 0: Base Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_GRAVE,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO, KC_ENT,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSPO, KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_RSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_SPC,                                                  MO(FUNC_), MO(MOUSE_),KC_NO,KC_APP, KC_RCTL),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  LAYOUT(
   // 1: Calemak Base Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_GRAVE,      KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_NO, KC_ENT,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSPO, KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_RSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_SPC,                                                  MO(FUNC_), MO(MOUSE_),KC_NO,KC_APP, KC_RCTL),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  LAYOUT(
   // 2: Function Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_INS,     KC_PSCR, KC_PAUS, KC_DEL,TD(TD_NAME),TD(TD_PHONE),KC_NO,KC_NO,KC_PAST, KC_7,    KC_8,    KC_9,    KC_PDOT, TO(0),      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_CAPS,       KC_HOME, KC_PGUP, KC_SLCK,   KC_NO,   KC_NO,   KC_NO,   KC_PPLS, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_NO, KC_ENT,      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSFT, KC_NO,    KC_END,  KC_PGDN, BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, KC_PSLS, KC_1,    KC_2,    KC_3,    KC_NO, KC_UP, KC_NO,    
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_0,                                                    KC_NO,     KC_LEFT, KC_NO, KC_DOWN, KC_RIGHT),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  LAYOUT(
   // 3: Mouse Control Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_SLCK,     KC_WH_L, KC_MS_U, KC_WH_R, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_U, KC_BTN4, KC_BTN5, TO(0),      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_CAPS,       KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, DF(0),  DF(1),   KC_NO,   KC_NO,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, KC_ENT,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSFT, KC_NO,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_WH_D, KC_WH_D, KC_WH_U, KC_NO, KC_MS_U, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   TO(LEFT_),                                               KC_MS_L,   KC_NO,  KC_NO,  KC_MS_D,  KC_MS_R),
   //--------------------------------------------------------------------------------------------------------------------------------------'
   
  LAYOUT(
   // 4: Base Layer With Arrow (For Games)
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_GRAVE,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO, KC_ENT,     
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSPO, KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_UP,   KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_SPC,                                                  TO(0),    KC_LEFT, KC_NO,  KC_DOWN, KC_RIGHT),
   //--------------------------------------------------------------------------------------------------------------------------------------'

};

#define STEPBL if(get_backlight_level() % 5 == 0) \
	blStep = -blStep;\
backlight_level(get_backlight_level() + blStep);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		if (keycode == BL_INC || keycode == BL_DEC)
			return true;
		else if (blFlag == 2 && get_backlight_level() != 6) {
			STEPBL
		}
		switch (keycode) {
			case BL_TOGG:
				{
					++blFlag;
					if (blFlag == 3)
						blFlag = 0;
					return false;
				}
				break;
		}
	}
	return true;
}


static uint16_t light_timer = 0;

// Loop
void matrix_scan_user(void) {
	if (blFlag == 1) {
		int i = timer_elapsed(light_timer) / 100;
		if (i >= sizeof(light_song) / sizeof(uint8_t)) {
			light_timer = timer_read();
			i = 0;
		}
		backlight_level(light_song[i]);
	}
};