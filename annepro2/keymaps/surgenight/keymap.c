#include QMK_KEYBOARD_H
#include "action_layer.h"

#define KCAB1 KC_AP2_BT1
#define KCAB2 KC_AP2_BT2
#define KCAB3 KC_AP2_BT3
#define KCAB4 KC_AP2_BT4
#define KCUAB KC_AP2_BT_UNPAIR
#define KCUSB KC_AP2_USB
#define KCALT KC_AP_LED_ON
#define KCALF KC_AP_LED_OFF

// Keyboard Layers
enum anne_pro_layers {
	BASE_ = 0,     // Base Layer
	COLEMAK_,  // Calemak Base Layer
	//_DVORAK,   // Dvorak Base Layer
	FUNC_,     // Function Layer
	MOUSE_,    // Mouse Control Layer
	GAME_,     // Left Hand Control Layer
};

enum custom_tap_dance {
	TNA, //ME,
	TPH, //ONE,
	TCO, //MBO,
};

enum combo_state {
	COMBO_NONE,
	COMBO_SHORT_WAIT,
	COMBO_LONG_WAIT,
	COMBO_SHORT_EXEC,
	COMBO_LONG_EXEC,
};

static uint8_t comboState = COMBO_NONE;
static uint16_t comboKeyCode = 0;
static uint16_t comboInterval = 0;
static uint16_t comboTimer = 0;

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
			SEND_STRING("16601274913");
			break;
	}
}

void dance_combo_finish(qk_tap_dance_state_t *state, void *user_data)
{
	comboInterval = state->count * 100;
	if (state->pressed)
		comboState = COMBO_LONG_WAIT;
	else
		comboState = COMBO_SHORT_WAIT;
}

qk_tap_dance_action_t tap_dance_actions[] = {
	// ACTION_TAP_DANCE_FN_ADVANCED(each  finish  reset)
	[TNA] = ACTION_TAP_DANCE_FN(dance_name_finish),
	[TPH] = ACTION_TAP_DANCE_FN(dance_phone_finish),
	[TCO] = ACTION_TAP_DANCE_FN(dance_combo_finish),
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Win  |  Alt  |               space             |  FN1  |  FN2  |  UP  |  Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |     (      |     |     |     |     |     |     |     |     |     |     |       )        |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |  LEFT |  DOWN |  UP  |  RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE_] = LAYOUT_60_ansi( // 0: Base Layer
    KC_ESC,   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_GRAVE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSPO,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,// RSFT_T(KC_UP)
    KC_LCTL, KC_LGUI,  KC_LALT,           KC_SPC,      LT(FUNC_, KC_LEFT), LT(MOUSE_, KC_DOWN), KC_UP, RCTL_T(KC_RGHT)
),
[COLEMAK_] = LAYOUT_60_ansi( // 1: Colemak Layer
    KC_ESC,   KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,   KC_Q,  KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_GRAVE, KC_A,  KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E,    KC_I,   KC_O,    KC_QUOT, KC_ENT,
    KC_LSPO,  KC_Z,  KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
    KC_LCTL, KC_LGUI, KC_LALT,           KC_SPC,       LT(FUNC_, KC_LEFT), LT(MOUSE_, KC_DOWN), KC_UP, RCTL_T(KC_RGHT)
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Win  |  Alt  |               space             |  FN1  |  FN2  |  UP  |  Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
[FUNC_] = LAYOUT_60_ansi( // 2: Function Layer
    KC_ESC, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,  KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,  KC_BSPC,
    KC_INS, KC_PSCR,KC_PAUS,KC_DEL,  KC_NUM,  TD(TNA), TD(TPH),KC_NUM, KC_PAST, KC_P7, KC_P8,  KC_P9,  KC_PDOT, TO(0),
    KC_CAPS,KC_HOME,KC_PGUP,KC_SLCK, KC_LOCK, TD(TCO), KC_NO,  KC_PPLS,KC_PMNS, KC_P4, KC_P5,  KC_P6,  KC_ENT,
    KC_LSFT,KC_END, KC_PGDN,RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI,KC_PSLS,KC_P1,    KC_P2, KC_P3,  KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,           KC_P0,        KC_NO,              KC_LEFT,             KC_DOWN, KC_RIGHT
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  Win  |  Alt  |               space             |  FN1  |  FN2  |  UP  |  Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
[MOUSE_] = LAYOUT_60_ansi( // 3: Mouse Control Layer
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,
    KC_APP, KC_WH_L,KC_MS_U,KC_WH_R,KC_VOLU,KCAB1,  KCAB2,  KCAB3, KCAB4,   KCUAB,   KC_WH_U, KC_BTN4, KC_BTN5, TO(0),
    KC_CAPS,KC_MS_L,KC_MS_D,KC_MS_R,KC_VOLD,DF(0),  DF(1),  KC_NO, KC_NO,   KC_BTN1, KC_BTN3, KC_BTN2, KC_ENT,
    KC_LSFT,KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,RGB_TOG,RGB_MOD,KCUSB, KC_WH_D, KC_WH_D, KC_WH_U, KC_MS_U,
    KC_LCTL, KC_LGUI, KC_LALT,           TO(GAME_),    KC_MS_L,            KC_NO,               KC_MS_D, KC_MS_R
),
[GAME_] = LAYOUT_60_ansi( // 4: Base Layer With Arrow (For Games)
    KC_ESC,   KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,   KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_GRAVE, KC_A,  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSPO,  KC_Z,  KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,           KC_SPC,       TO(0),              KC_LEFT,             KC_DOWN, KC_RIGHT
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		if (comboState == COMBO_SHORT_WAIT || comboState == COMBO_LONG_WAIT) {
			comboKeyCode = keycode;
			comboTimer = timer_read();
			comboState += 2;
			register_code(comboKeyCode);
			if (comboState == COMBO_SHORT_EXEC)
				unregister_code(comboKeyCode);
		}
		else if ((comboState == COMBO_SHORT_EXEC || comboState == COMBO_LONG_EXEC) && keycode == comboKeyCode) {
			comboState = COMBO_NONE;
			unregister_code(comboKeyCode);
		}
	}
	return true;
}

// Loop
void matrix_scan_user(void) {
	if (comboState == COMBO_SHORT_EXEC) {
		if (timer_elapsed(comboTimer) >= comboInterval) {
			register_code(comboKeyCode);
			unregister_code(comboKeyCode);
			comboTimer = timer_read();
		}
	}
	else if (comboState == COMBO_LONG_EXEC) {
		if (timer_elapsed(comboTimer) >= comboInterval) {
			unregister_code(comboKeyCode);
			register_code(comboKeyCode);
			comboTimer = timer_read();
		}
	}
};
