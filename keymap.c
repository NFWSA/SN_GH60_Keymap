#include "org60.h"
#include "action_layer.h"

// Keyboard Layers
enum keyboard_layers {
  _BASE,     // Base Layer
  _COLEMAK,  // Calemak Base Layer
  //_DVORAK,   // Dvorak Base Layer
  _FUNC,     // Function Layer
  _MOUSE,    // Mouse Control Layer
  _LEFT,     // Left Hand Control Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KEYMAP(
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
      KC_LSFT, KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_RSFT, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_SPC,                                                  MO(_FUNC), MO(_MOUSE),KC_NO,KC_APP, KC_RCTL),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  [_COLEMAK] = KEYMAP(
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
      KC_LSFT, KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, KC_RSFT, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_SPC,                                                  MO(_FUNC), MO(_MOUSE),KC_NO,KC_APP, KC_RCTL),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  [_FUNC] = KEYMAP(
   // 2: Function Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_SLCK,    KC_PAUS, KC_PSCR, KC_DEL,  KC_NO,   TO(0),   TO(1),   KC_NO,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_PDOT, KC_INS,      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_CAPS,       KC_HOME, KC_PGUP, KC_UNDO, KC_NO,   KC_NO,   KC_NO,   KC_PPLS, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_NO, TO(0),      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSFT, KC_NO,    KC_END,  KC_PGDN, BL_TOGG, BL_INC,  BL_DEC,  BL_BRTG, KC_PSLS, KC_1,    KC_2,    KC_3,    KC_NO, KC_UP, KC_NO,    
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_0,                                                    MO(_FUNC), KC_LEFT, KC_NO, KC_DOWN, KC_RIGHT),
   //--------------------------------------------------------------------------------------------------------------------------------------'

  [_MOUSE] = KEYMAP(
   // 3: Mouse Control Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_DEL,     KC_WH_L, KC_MS_U, KC_WH_R, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_U, KC_BTN4, KC_BTN5, KC_NO,       
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_CAPS,       KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN1, KC_BTN3, KC_BTN2, KC_NO, TO(0),      
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSFT, KC_NO,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_WH_D, KC_WH_D, KC_WH_U, KC_NO, KC_NO,   KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   TO(_LEFT),                                               KC_NO,     MO(_MOUSE),KC_NO,KC_NO,  KC_NO),
   //--------------------------------------------------------------------------------------------------------------------------------------'
   
  [_LEFT] = KEYMAP(
   // 3: Mouse Control Layer
   //--------------------------------------------------------------------------------------------------------------------------------------.
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
   //        |        |        |        |        |        |        |        |        |        |        |        |        |                 |
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
   //            |        |        |        |        |        |        |        |        |        |        |        |        |             |
      KC_TAB,     KC_WH_D, KC_UP,   KC_WH_U, KC_7,    KC_8,    KC_9,    KC_PAST, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),       
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
   //               |        |        |        |        |        |        |        |        |        |        |        |                   |
      KC_ENT,        KC_LEFT, KC_DOWN, KC_RIGHT,KC_4,    KC_5,    KC_6,   KC_PPLS,  KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PENT,    
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
   //                   |        |        |        |        |        |        |        |        |        |        |░░░░░░|        |░░░░░░░░|
      KC_LSFT, KC_NO,    KC_NO,   KC_NO,   KC_PDOT, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,  
   //--------------------------------------------------------------------------------------------------------------------------------------|
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
   //          |          |          |                                                        |          |        |░░░░░░|        |        |
      KC_LCTL,  KC_LGUI,   KC_LALT,   KC_0,                                                    KC_NO,     KC_NO,   KC_NO, KC_NO,   KC_NO),
   //--------------------------------------------------------------------------------------------------------------------------------------'
};


// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    //[0] = ACTION_LAYER_MOMENTARY(_FUNC1),  // to Function overlay
};


// Loop
void matrix_scan_user(void) {
  // Empty
};