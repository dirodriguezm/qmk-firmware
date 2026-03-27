/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_spanish_latin_america.h"
#include "sendstring_spanish_latin_america.h"

enum layers {
  BASE,
  SYM,
  NAV,
  NUM,
  WIN,
  FUN,
};

enum keycode_aliases {
  // The "magic" key is the Alternate Repeat Key.
  MAGIC = QK_AREP,
  // Short aliases for home row mods and other tap-hold keys.
  HRM_Z = LGUI_T(ES_Z),
  HRM_X = LALT_T(ES_X),
  HRM_C = LCTL_T(ES_C),

  HRM_M = RCTL_T(ES_M),
  HRM_COM = LALT_T(ES_COMM),
  HRM_DOT = RGUI_T(ES_DOT),

  NAV_EQL = LT(NAV, ES_EQL),
};


enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  // Macros invoked through the Magic key.
  M_DOCSTR,
  M_EQEQ,
  M_INCLUDE,
  M_ION,
  M_MENT,
  M_MKGRVS,
  M_QUEN,
  M_THE,
  M_TMENT,
  M_UPDIR,
  M_NBSP,
  M_NOOP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                         ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,     ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSL(SYM), ES_A,   ES_S,   ES_D,   ES_F,      ES_G,                         ES_H,    ES_J,    ES_K,    ES_L,   ES_B,   OSL(SYM),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ES_NTIL, OS_LSFT, HRM_Z,  HRM_X,   HRM_C,   ES_V,                          ES_N,    HRM_M,   HRM_COM, HRM_DOT, OS_RSFT, LT(WIN, KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   CW_TOGG,   LT(NAV, ES_UNDS),  KC_SPC,     QK_REP,   LT(NUM, KC_ESC), QK_AREP
                                      //`--------------------------'  `--------------------------'

  ),

    [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, ES_GRV, ES_LABK, ES_RABK, ES_MINS, ES_PIPE,                        ES_CIRC, ES_LCBR, ES_RCBR, ES_DLR,  ES_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_EXLM, ES_ASTR, ES_SLSH, ES_EQL, ES_AMPR,                        ES_NUMB, ES_LPRN, ES_RPRN, ES_SCLN, ES_DQUO, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_TILD, ES_PLUS, ES_LBRC, ES_RBRC, ES_PERC,                       ES_AT,   ES_COLN, ES_COMM, ES_DOT,  ES_QUOT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     QK_REP,  KC_ESC, QK_AREP
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, LCTL(ES_Q), LCTL(ES_W), XXXXXXX, XXXXXXX, XXXXXXX,                 KC_PGUP, KC_HOME, KC_UP,   KC_END,   KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX,                      XXXXXXX, SELWBAK, SELLINE, SELWORD,  OS_RSFT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   XXXXXXX,  XXXXXXX,     QK_REP, QK_LLCK, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, ES_SLSH, ES_9, ES_8, ES_7, ES_ASTR,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_MINS, ES_3, ES_2, ES_1, ES_PLUS,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, ES_DOT, ES_6, ES_5, ES_4, ES_PERC,                               XXXXXXX, KC_RCTL,  KC_LALT, KC_RGUI, OS_RSFT, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, ES_UNDS,  KC_SPC,     ES_0, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [WIN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      UG_SATU, UG_NEXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, UG_HUEU, G(ES_3), G(ES_2), G(ES_1), XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, UG_TOGG, G(ES_6), G(ES_5), G(ES_4), XXXXXXX,                     XXXXXXX, S(A(KC_TAB)), A(KC_TAB), XXXXXXX, OS_RSFT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_MPLY,  G(KC_SPC),     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F12,  KC_F9,   KC_F8,   KC_F7,   XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F10,  KC_F3,   KC_F2,   KC_F1,   XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F11,  KC_F6,   KC_F5,   KC_F4,   XXXXXXX,                     XXXXXXX, KC_RCTL, KC_LALT, KC_RGUI, KC_RSFT, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
};

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case ES_A ... ES_Z:
      add_weak_mods(MOD_BIT_LSHIFT);  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case ES_1 ... ES_0:
    case KC_BSPC:
    case KC_DEL:
    case ES_UNDS:
    case ES_COLN:
    case M_THE:
    case M_ION:
    case M_MENT:
    case M_QUEN:
    case M_TMENT:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  keycode = get_tap_keycode(keycode);

  if ((mods & ~MOD_MASK_SHIFT) == 0) {
    // This is where most of the "magic" for the MAGIC key is implemented.
    switch (keycode) {
      case KC_SPC:  // spc -> THE
      case KC_ENT:
      case KC_TAB:
        return M_THE;

      // For navigating next/previous search results in Vim:
      // N -> Shift + N, Shift + N -> N.
      case ES_N:
        if ((mods & MOD_MASK_SHIFT) == 0) {
          return S(ES_N);
        }
        return ES_N;

      // Fix SFBs and awkward strokes.
      case ES_A: return ES_O;         // A -> O
      case ES_O: return ES_A;         // O -> A
      case ES_E: return ES_U;         // E -> U
      case ES_U: return ES_E;         // U -> E
      case ES_I:
        if ((mods & MOD_MASK_SHIFT) == 0) {
          return M_ION;  // I -> ON
        } else {
          return ES_QUOT;  // Shift I -> '
        }
      case ES_M: return M_MENT;       // M -> ENT
      case ES_Q: return M_QUEN;       // Q -> UEN
      case ES_T: return M_TMENT;      // T -> TMENT

      case ES_C: return ES_Y;         // C -> Y
      case ES_D: return ES_Y;         // D -> Y
      case ES_G: return ES_Y;         // G -> Y
      case ES_P: return ES_Y;         // P -> Y
      case ES_Y: return ES_P;         // Y -> P

      case ES_L: return ES_K;         // L -> K
      case ES_S: return ES_K;         // S -> K

      case ES_R: return ES_L;         // R -> L
      case ES_DOT:
        if ((mods & MOD_MASK_SHIFT) == 0) {
          return M_UPDIR;  // . -> ./
        }
        return M_NOOP;
      case ES_EQL: return M_EQEQ;      // = -> ==
      case ES_RBRC: return ES_SCLN;    // ] -> ;

      case ES_COMM:
        if ((mods & MOD_MASK_SHIFT) != 0) {
          return ES_EQL;  // ! -> =
        }
        return M_NOOP;
      case ES_QUOT:
        if ((mods & MOD_MASK_SHIFT) != 0) {
          return M_DOCSTR;  // " -> ""<cursor>"""
        }
        return M_NOOP;
      case ES_GRV:  // ` -> ``<cursor>``` (for Markdown code)
        return M_MKGRVS;
      case ES_LABK:  // < -> - (for Haskell)
        return ES_MINS;
      case ES_SLSH:
        return ES_SLSH;  // / -> / (easier reach than Repeat)

      case ES_PLUS:
      case ES_MINS:
      case ES_ASTR:
      case ES_PERC:
      case ES_PIPE:
      case ES_CIRC:
      case ES_TILD:
      case ES_EXLM:
      case ES_DLR:
      case ES_RABK:
      case ES_LPRN:
      case ES_RPRN:
      case ES_UNDS:
      case ES_COLN:
        return ES_EQL;

      case ES_F:
      case ES_V:
      case ES_X:
      case ES_SCLN:
      case ES_1 ... ES_0:
        return M_NOOP;
    }
  }

  switch (keycode) {
    case MS_WHLU: return MS_WHLD;
    case MS_WHLD: return MS_WHLU;
    case SELWBAK: return SELWORD;
    case SELWORD: return SELWBAK;
  }
  return KC_TRNS;
}

// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`. This helper is
// used for several macros below in my process_record_user() function.
#define MAGIC_STRING(str, repeat_keycode) \
  magic_send_string_P(PSTR(str), (repeat_keycode))
static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
  uint8_t saved_mods = 0;
  // If Caps Word is on, save the mods and hold Shift.
  if (is_caps_word_on()) {
    saved_mods = get_mods();
    register_mods(MOD_BIT_LSHIFT);
  }

  send_string_P(str);  // Send the string.
  set_last_keycode(repeat_keycode);

  // If Caps Word is on, restore the mods.
  if (is_caps_word_on()) {
    set_mods(saved_mods);
  }
}

KEYCODE_STRING_NAMES_USER(
  KEYCODE_STRING_NAME(UPDIR),
  KEYCODE_STRING_NAME(SELWORD),
  KEYCODE_STRING_NAME(SELWBAK),
  KEYCODE_STRING_NAME(SELLINE),
);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
  );
  const uint8_t layer = read_source_layers_cache(record->event.key);

  if (layer == SYM && record->event.pressed) {
    clear_weak_mods();
    send_keyboard_report();
  }

  // If alt repeating key A, E, I, O, U, Y with no mods other than Shift, set
  // the last key to KC_N. Above, alternate repeat of KC_N is defined to be
  // again KC_N. This way, either tapping alt repeat and then repeat (or
  // equivalently double tapping alt repeat) is useful to type certain patterns
  // without SFBs:
  //
  //   D <altrep> <rep> -> DYN (as in "dynamic")
  //   O <altrep> <rep> -> OAN (as in "loan")
  if (get_repeat_key_count() < 0 && (all_mods & ~MOD_MASK_SHIFT) == 0 &&
      (keycode == ES_A || keycode == ES_E || keycode == ES_I ||
       keycode == ES_O || keycode == ES_U || keycode == ES_Y)) {
    set_last_keycode(ES_N);
    set_last_mods(0);
  }

  switch (keycode) {
    // When the Repeat key follows Space, it behaves as one-shot shift.
    case KC_SPC:
      if (get_repeat_key_count() > 0) {
        if (record->event.pressed) {
          add_oneshot_mods(MOD_LSFT);
          register_mods(MOD_LSFT);
        } else {
          unregister_mods(MOD_LSFT);
        }
        return false;
      }
      break;
  }

  if (record->event.pressed) {
    switch (keycode) {
      case UPDIR:
        SEND_STRING_DELAY("../", TAP_CODE_DELAY);
        return false;

      // Macros invoked through the MAGIC key.
      case M_THE:     MAGIC_STRING(/* */"the", ES_N); break;
      case M_ION:     MAGIC_STRING(/*i*/"on", ES_S); break;
      case M_MENT:    MAGIC_STRING(/*m*/"ent", ES_S); break;
      case M_QUEN:    MAGIC_STRING(/*q*/"uen", ES_C); break;
      case M_TMENT:   MAGIC_STRING(/*t*/"ment", ES_S); break;
      case M_UPDIR:   MAGIC_STRING(/*.*/"./", UPDIR); break;
      case M_EQEQ:    SEND_STRING_DELAY(/*=*/"==", TAP_CODE_DELAY); break;
      case M_NBSP:    SEND_STRING_DELAY(/*&*/"nbsp;", TAP_CODE_DELAY); break;

      case M_DOCSTR:
        SEND_STRING_DELAY(/*"*/"\"\"\"\"\""
            SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), TAP_CODE_DELAY);
        break;
      case M_MKGRVS:
        SEND_STRING_DELAY(/*`*/"``\n\n```" SS_TAP(X_UP), TAP_CODE_DELAY);
        break;

    }
  }

  return true;
}
