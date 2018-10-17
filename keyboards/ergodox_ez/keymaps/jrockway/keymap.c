#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0
#define FKEYS 1
#define MEDIA 2
#define MODS 3

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
                       KC_EQUAL,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,
                       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,TG(FKEYS),
                       KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
                       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_BSPACE,
                       KC_GRAVE,KC_QUOTE,KC_LEFT,KC_RIGHT,KC_LALT,
                       KC_APPLICATION,KC_LGUI,
                       KC_HOME,
                       LT(MODS,KC_SPACE),KC_SPACE, // big thumb keys
                       KC_END,

                       KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
                       TG(MEDIA),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,
                       KC_H,KC_J,KC_K,KC_L,KC_SCOLON,GUI_T(KC_QUOTE),
                       KC_BSPACE,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_SFTENT,
                       KC_UP,KC_DOWN,KC_LBRACKET,KC_RBRACKET,KC_PSCREEN,
                       KC_DEL,KC_ESCAPE,
                       KC_PGUP,KC_PGDOWN,
                       KC_SPACE,KC_SPACE), // big thumb keys

  [MODS] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,_______,_______,_______,_______,KC_BSLASH,
                       _______,_______,_______,_______,KC_LBRACKET,KC_RBRACKET,KC_BSPACE,
                       _______,_______,_______,_______,_______,KC_ENTER,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [FKEYS] = LAYOUT_ergodox(
                       _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_NUMLOCK,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       KC_SCROLLLOCK,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
                       _______,_______,_______,_______,_______,_______,KC_F12,
                       _______,_______,_______,_______,_______,KC_F13,
                       _______,_______,_______,_______,_______,_______,KC_F14,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [MEDIA] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       // mpv/media stuff
                       KC_ESCAPE,_______,_______,_______,_______,_______,_______,
                       _______,_______,KC_1,KC_UP,KC_2,_______,_______,
                       KC_PGUP,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,
                       KC_PAUSE,KC_PGDOWN,MEH(KC_PGDOWN),MEH(KC_LEFT),MEH(KC_RIGHT),MEH(KC_PGUP),_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big
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

const uint16_t PROGMEM fn_actions[] = {
  [BASE] = ACTION_LAYER_TAP_TOGGLE(BASE),
  [MODS] = ACTION_LAYER_TAP_TOGGLE(MODS),
  [FKEYS] = ACTION_LAYER_TAP_TOGGLE(FKEYS),
  [MEDIA] = ACTION_LAYER_TAP_TOGGLE(MEDIA),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
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

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
