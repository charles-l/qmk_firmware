#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

#define QWERTY_LAYER 0
#define LW   1
#define UU   2
#define STR  3 // starcraft bindings
#define CSGO 4 // starcraft bindings

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY_LAYER] = { /* Qwerty */
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
    {KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(LW),  KC_SPC,  KC_SPC,  MO(UU),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  [LW] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELETE},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD, KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
  },
  [UU] = {
    {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11},
    {KC_TRNS, KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TILD, KC_LBRC, KC_RBRC,  KC_TRNS, RESET},
    {KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_MINS, KC_EQL,   KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  TG(CSGO),TG(STR)}
  },
  [STR] = {
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_BSPC},
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSLS},
    {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_SPC,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS}
  },
  [CSGO] = {
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_BSPC},
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSLS},
    {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_SPC,  KC_B,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS}
  },
};

const uint16_t PROGMEM fn_actions[] = {
//  [1] = ACTION_LAYER_TAP_KEY(LOWER_LAYER, KC_BSPC),  // Tap for backspace, hold for LOWER
//  [2] = ACTION_LAYER_TAP_KEY(UPPER_LAYER, KC_ENT),  // Tap for enter, hold for RAISE
//  [3] = ACTION_LAYER_TAP_KEY(TABFN_LAYER, KC_TAB),  // Tap for tab, hold for TABFN
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        backlight_step();
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};
