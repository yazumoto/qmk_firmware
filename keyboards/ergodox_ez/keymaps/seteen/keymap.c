#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "config.h"
#include "hk_util.h"
#include "custom_keycodes.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define HACHIKOUME 3

enum custom_functions {
  F_SFT = 1,
  F_CTRL,
  F_LALT,
  F_RALT,
  F_LGUI,
  F_RGUI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   !  |   @  |   {  |   }  |   5  |  &   |           |  *   |   6  |   [  |   ]  |   (  |   )  |   BS   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |  ^   |           |  -   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L1     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|      |           |  =   |------+------+------+------+------+--------|
 * |   :    |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L2|  '"  |AltShf| LGUI | Space|                                       | Enter|  BS  | RGUI |      |  :   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |   ?  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | LSft | Ctrl |------|       |------|RCommand| RSft |
 *                                 |      |      | &    |       | |    |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   S(KC_1),  S(KC_2),       S(KC_LBRC), S(KC_RBRC),  S(KC_5), S(KC_7),
        KC_TAB,   KC_Q,     KC_W,          KC_E,       KC_R,        KC_T,    S(KC_6),
        MO(SYMB), KC_A,     KC_S,          KC_D,       KC_F,        KC_G,
        KC_COLN,  KC_Z,     KC_X,          KC_C,       KC_V,        KC_B,    KC_NO,
        MO(MDIA), KC_QUOT,  LALT(KC_LSFT), KC_LGUI,    KC_SPC,
        // Left Thumb
                                                        ALT_T(KC_APP), KC_LGUI,
                                                                       KC_HOME,
                                               KC_LSFT, KC_LCTL,       S(KC_AMPR),
        // right hand
             TG(HACHIKOUME), KC_6,   KC_LBRC,    KC_RBRC, S(KC_9), S(KC_0), KC_BSPC,
             KC_MINS,        KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS,
                             KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_EQL,         KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, S(KC_MINS),
                                     KC_ENT,     KC_BSPC, KC_RGUI, KC_NO,   KC_COLN,
        // Right Thumb
             KC_LALT,    S(KC_SLSH),
             KC_PGUP,
             S(KC_BSLS), KC_LGUI, KC_RSFT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   `  |   {  |   }  |   |  |      |           |      |   $  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   %  |   ^  |   &  |------|           |------|   #  |   4  |   5  |   6  |   ?  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   %  |   1  |   2  |   3  |   `  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,      KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,S(KC_TILD), KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,    KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,
       KC_TRNS,KC_PERC,    KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          EPRM,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,      KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_DLR,     KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_HASH,    KC_4,   KC_5,    KC_6,    S(KC_SLSH), KC_TRNS,
       KC_TRNS, KC_PERC,    KC_1,   KC_2,    KC_3,    KC_GRV, KC_TRNS,
                            KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|MsLeft|MsDown|MsUp  |MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Japanese layout layer (For JIS)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  [{  |           |  }]  |   Y  |   U  |   I  |   O  |   P  |  @`    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;+  |  :*    |
 * |--------+------+------+------+------+------|  Gui |           | Gui  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  \|  |  ^~  | LAlt | Eisu |                                       | Kana | RAlt |  \_  | Arr  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left |Right |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Up  |       |  Up  |      |      |
 *                                 |LShift|Space |------|       |------| Enter|RShift|
 *                                 |      |      | Down |       | Down |      |      |
 *                                 `--------------------'       `--------------------'
 */
[HACHIKOUME] = LAYOUT_ergodox(  // layer 3 : for hachi-mitsu koume japanese layout
        // left hand
        KC_ESC,     KC_1,    KC_2,   KC_3,      KC_4,        KC_5,    KC_NO,
        KC_TAB,     KC_Q,    KC_W,   KC_E,      KC_R,        KC_T,    JA_LBRC,
        KC_LCTL,    KC_A,    KC_S,   KC_D,      KC_F,        KC_G,
        KC_LSFT,    KC_Z,    KC_X,   KC_C,      KC_V,        KC_B,    F(F_LGUI),
        KC_NO,      KC_JYEN, JA_HAT, KC_TRNS,   M_EISU,
                                                             KC_LEFT, KC_RGHT,
                                                                      KC_UP,
                                     KC_HK_LSPACE,KC_SPACE,  KC_DOWN,
        // right hand
             KC_TRNS,    KC_6,      KC_7,     KC_8,      KC_9,    KC_0,        KC_TRNS,
             JA_RBRC,    KC_Y,      KC_U,     KC_I,      KC_O,    KC_P,        JA_AT,
                         KC_H,      KC_J,     KC_K,      KC_L,    KC_SCLN,     JA_CLN,
             F(F_RGUI),  KC_N,      KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,     KC_RSFT,
                                    KC_ENT,   KC_TRNS,   KC_RGUI, OSL(MDIA),   KC_NO,
             KC_LEFT,    KC_RGHT,
             KC_UP,
             KC_DOWN,    KC_ENTER,  KC_HK_RSPACE
    )
};

const uint16_t PROGMEM fn_actions[] = {
//    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
    [F_SFT] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [F_CTRL] = ACTION_MODS_ONESHOT(MOD_LCTL),
    [F_LALT] = ACTION_MODS_ONESHOT(MOD_LALT),
    [F_RALT] = ACTION_MODS_ONESHOT(MOD_RALT),
    [F_LGUI] = ACTION_MODS_ONESHOT(MOD_LGUI),
    [F_RGUI] = ACTION_MODS_ONESHOT(MOD_RGUI)
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

  uint8_t layer = biton32(layer_state);

  switch (layer) {
    case HACHIKOUME:
      return der_process_hk(keycode, record); break;
    default:
      break;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
//void matrix_init_user(void) {
//#ifdef RGBLIGHT_COLOR_LAYER_0
//  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
//#endif
//};

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
