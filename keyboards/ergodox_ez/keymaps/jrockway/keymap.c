#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes {
    MAC_NE = SAFE_RANGE,  // "!= "
    FMT_QUOTE,            // %q
    FMT_DEC,              // %d
    FMT_STR,              // %s
    FMT_VAL,              // %v
    FMT_ERR,              // %w
    MAC_ASSIGN,           // := or !=
    MAC_METAX,            // M-x
    MAC_SUPERJUMP,        // shift and alt
    MAC_SHIFTINSERT,      // shift + insert
};

#define BASE 0
#define LOWER 1
#define RAISE 2
#define FKEYS 3
#define GAME 4
#define CAPS 7

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
                       KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,OSL(FKEYS),
                       KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_UNDERSCORE,
                       KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
                       KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_MINUS,
                       KC_LGUI,KC_BSLASH,MAC_METAX,SH_MON,MO(RAISE),
                       KC_DEL,KC_INS,
                       KC_PGUP,
                       KC_LALT,KC_SPACE, // big thumb keys
                       KC_PGDOWN,

                       KC_PAUSE,KC_6,KC_7,KC_8,KC_9,KC_0,MAC_NE,
                       KC_EQUAL,KC_Y,KC_U,KC_I,KC_O,KC_P,MAC_ASSIGN,
                       KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,
                       KC_BSPACE,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
                       MO(LOWER),SH_MON,KC_HOME,KC_END,KC_RGUI,
                       KC_LEFT,KC_RIGHT,
                       KC_UP,KC_DOWN,
                       KC_ENTER,KC_SPACE), // big thumb keys

  [FKEYS] = LAYOUT_ergodox(
                       RESET,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,TO(GAME),
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
                       KC_PSCREEN,_______,_______,_______,_______,_______,KC_F14,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [GAME] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,TO(BASE),
                       _______,_______,_______,_______,_______,_______,KC_Y,
                       MAC_SUPERJUMP,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,KC_M,
                       KC_LSHIFT,KC_SPACE,KC_SPACE,KC_SPACE,KC_SPACE,
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
                       RGB_TOG,_______,_______,_______,_______,_______,_______,
                       RGB_MOD,RGB_RMOD,_______,_______,KC_WH_U,_______,_______,
                       RGB_HUI,RGB_HUD,_______,_______,KC_WH_D,MAC_SHIFTINSERT,
                       RGB_SAI,RGB_SAD,_______,_______,_______,_______,_______,
                       RGB_VAI,RGB_VAD,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______,_______,KC_AMPERSAND,_______,_______,_______,_______,
                       _______,KC_CIRCUMFLEX,KC_AMPERSAND,KC_ASTERISK,KC_GRAVE,KC_TILDE,KC_PIPE,
                               KC_PERCENT,KC_LPRN,KC_LCBR,KC_RCBR,KC_RPRN,KC_DOUBLE_QUOTE,
                       _______,_______,KC_LBRACKET,KC_RBRACKET,KC_RBRACKET,_______,KC_BSLASH,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,_______,
                       _______,_______), // big

  [LOWER] = LAYOUT_ergodox(
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,KC_EXCLAIM,KC_AT,KC_HASH,KC_DOLLAR,_______,_______,
                       _______,FMT_QUOTE,FMT_STR,FMT_DEC,FMT_VAL,FMT_ERR,
                       _______,_______,_______,_______,FMT_VAL,_______,_______,
                       _______,_______,_______,_______,_______,
                       _______,_______,
                       _______,
                       _______,_______, // big
                       _______,

                       _______, KC_SLCK,   KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,_______,
                       _______, _______,   KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,_______,
                                KC_BSPACE, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,_______,
                       _______, KC_BSPACE, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER,_______,
                                  _______, _______,    KC_KP_0,     KC_KP_DOT,      KC_KP_ENTER,
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
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MAC_SUPERJUMP) {
        int rand = TCNT0 % 3;
        if (record->event.pressed) {
            if (rand == 0) {
                add_key(KC_LSHIFT);
                add_key(KC_LALT);
                send_keyboard_report();
            } else if (rand == 1) {
                add_key(KC_LSHIFT);
                send_keyboard_report();
                add_key(KC_LALT);
                send_keyboard_report();
            } else {
                add_key(KC_LALT);
                send_keyboard_report();
                add_key(KC_LSHIFT);
                send_keyboard_report();
            }
        } else {
            if (rand == 0) {
                del_key(KC_LSHIFT);
                del_key(KC_LALT);
                send_keyboard_report();
            } else if (rand == 1) {
                del_key(KC_LSHIFT);
                send_keyboard_report();
                del_key(KC_LALT);
                send_keyboard_report();
            } else {
                del_key(KC_LALT);
                send_keyboard_report();
                del_key(KC_LSHIFT);
                send_keyboard_report();
            }
        }
        return false;
    }

    if (record->event.pressed) {
        if (biton32(layer_state) == CAPS && (keycode < KC_A || keycode > KC_Z) && (keycode != KC_UNDERSCORE && keycode != KC_BSPACE)) {
            layer_clear();
            return true;
        }
        switch (keycode) {
            case MAC_ASSIGN:
                SEND_STRING(":= ");
                return false;
            case MAC_NE:
                SEND_STRING("!= ");
                return false;
            case MAC_METAX:
                SEND_STRING(SS_LALT("x"));
                return false;
            case MAC_SHIFTINSERT:
                SEND_STRING(SS_LSFT(SS_TAP(X_INS)));
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
            case FMT_ERR:
                SEND_STRING("%w");
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) { ergodox_led_all_set(15); };

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){};

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
