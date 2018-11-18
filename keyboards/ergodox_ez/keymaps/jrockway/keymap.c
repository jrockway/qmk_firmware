#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
  MAC_NE = SAFE_RANGE, // "!= "
  FMT_QUOTE, // %q
  FMT_DEC, // %d
  FMT_STR, // %s
  FMT_VAL, // %v
  MAC_ERR, // "err "
  MAC_NIL, // nil
  MAC_ASSIGN, // := or !=
};

#define BASE 0
#define LOWER 1
#define RAISE 2
#define FKEYS 3
#define GAME 4
#define CAPS 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
                       KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,OSL(FKEYS),
                       KC_EQUAL,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TAB,
                       KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
                       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MINUS,
                       KC_LGUI,KC_GRAVE,KC_DEL,MO(RAISE),MO(RAISE),
                       KC_DEL,KC_INS,
                       KC_PGUP,
                       KC_LALT,KC_SPACE, // big thumb keys
                       KC_PGDOWN,

                       KC_PAUSE,KC_6,KC_7,KC_8,KC_9,KC_0,MAC_ASSIGN,
                       KC_UNDERSCORE,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,
                       KC_ENTER,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
                       MO(LOWER),MO(LOWER),KC_PLUS,KC_PSCREEN,KC_RCTL,
                       KC_LEFT,KC_RIGHT,
                       KC_UP,KC_DOWN,
                       KC_BSPACE,KC_SPACE), // big thumb keys

  [FKEYS] = LAYOUT_ergodox(
                       _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,TO(GAME),
                       _______,_______,_______,_______,_______,_______,KC_NUMLOCK,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
                       KC_SCROLLLOCK,_______,_______,_______,_______,_______,KC_F12,
                       _______,_______,_______,_______,_______,KC_F13,
                       _______,_______,_______,_______,_______,_______,KC_F14,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [GAME] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,TO(BASE),
                       KC_TAB,_______,_______,_______,_______,_______,KC_Y,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,KC_H,
                       _______,KC_SPACE,KC_SPACE,KC_SPACE,KC_SPACE,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [RAISE] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,KC_CIRCUMFLEX,KC_AMPERSAND,KC_ASTERISK,KC_GRAVE,KC_TILDE,KC_PIPE,
                               KC_PERCENT,KC_LPRN,KC_LCBR,KC_RCBR,KC_RPRN,KC_DOUBLE_QUOTE,
                       _______,_______,KC_LBRACKET,KC_RBRACKET,_______,_______,_______,
                       TO(CAPS),_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [LOWER] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,KC_EXCLAIM,KC_AT,KC_HASH,KC_DOLLAR,MAC_NIL,_______,
                       _______,FMT_QUOTE,FMT_STR,FMT_DEC,FMT_VAL,MAC_NE,
                       _______,_______,_______,_______,_______,MAC_ERR,_______,
                       _______,_______,_______,_______,TO(CAPS),
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,KC_7,KC_8,KC_9,KC_ASTERISK,_______,
                       _______,_______,KC_4,KC_5,KC_6,KC_MINUS,_______,
                               _______,KC_1,KC_2,KC_3,KC_PLUS,_______,
                       _______,_______,KC_0,KC_0,KC_DOT,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [CAPS] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,TO(BASE),
                       _______,_______,
                       _______,
                       KC_SPACE,KC_SPACE, // big
                       _______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       TO(BASE),_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       KC_SPACE,KC_SPACE), // big
};
/* EMPTY
  [X] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big
*/

qk_tap_dance_action_t tap_dance_actions[] = {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  if (record->event.pressed) {
    if (biton32(layer_state) == CAPS && (keycode < KC_A || keycode > KC_Z) && (keycode != KC_UNDERSCORE && keycode != KC_BSPACE)) {
      layer_clear();
      return true;
    }
    switch(keycode) {
    case MAC_ASSIGN:
      if (get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))) {
        SEND_STRING("!=");
      } else {
        SEND_STRING(":=");
      }
      return false;
    case MAC_ERR:
      SEND_STRING("err ");
      return false;
    case MAC_NE:
      SEND_STRING("!= ");
      return false;
    case MAC_NIL:
      SEND_STRING("nil {");
      return false;
    case FMT_QUOTE:
      SEND_STRING("%q");
      return false;
    case FMT_DEC:
      SEND_STRING("%d");
      return false;
    case FMT_STR:
      SEND_STRING("%s");
      return false;
    case FMT_VAL:
      SEND_STRING("%v");
      return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_set(15);
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

uint8_t caps_on = 0;

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  if (layer == CAPS) {
    if (!caps_on) {
      caps_on = 1;
      add_key(KC_CAPS);
      send_keyboard_report();
    }
  } else {
    if (caps_on) {
      caps_on = 0;
      add_key(KC_CAPS);
      send_keyboard_report();
    }
  }

  if (layer & 1) {
    ergodox_right_led_3_on();
  }
  if (layer & 2) {
    ergodox_right_led_2_on();
  }
  if (layer & 4) {
    ergodox_right_led_1_on();
  }
  return state;
};
