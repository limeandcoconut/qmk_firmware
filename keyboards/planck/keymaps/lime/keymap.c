/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _WORKMAN,
  _QWERTY,
//   _COLEMAK,
//   _DVORAK,
  _LOWER,
  _RAISE,
//   _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
//   COLEMAK,
//   DVORAK,
//   PLOVER,
//   BACKLIT,kslkjdsfasdf
//   EXT_PLV
};

//Tap Dance Declarations
enum {
  TD_LBRC_LCBR = 0,
  TD_RBRC_RCBR,
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
// TD(TD_ESC_CAPS)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | GUI  | Copy |Paste |Lower |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,     KC_B,  KC_J,   KC_F,  KC_U,    KC_P,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_H,    KC_T,     KC_G,  KC_Y,   KC_N,  KC_E,    KC_O,    KC_I,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,     KC_V,  KC_K,   KC_L,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_COPY, KC_PASTE, LOWER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

// /* Workman Dead Layer
//  * ,-----------------------------------------------------------------------------------.
//  * |      |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |      |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |      |   /  |   (  |   =  |   0  |   {  |   }  |   1  |   *  |   )  |   -  |  "   |
//  * |------+------+------+------+------+------|------+------+------+------+------+------|
//  * |      |   6  |   7  |   8  |   9  |   |  |   \  |   2  |   3  |   4  |   5  |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |   <  |   ~  |   `  |      ,      |   #  |   ^  |   >  |      |      |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_DEAD] = LAYOUT_planck_grid(
//     XXXXXXX,  KC_PERC, KC_AMPR, KC_QUES, KC_PLUS, KC_AT,   KC_DLR,  KC_UNDS, KC_LBRC, KC_RBRC,  KC_EXLM, XXXXXXX,
//     XXXXXXX,  KC_SLSH, KC_LPRN, KC_EQL,  KC_0,    KC_LCBR, KC_RCBR, KC_1,    KC_ASTR, KC_RPRN,  KC_MINS, XXXXXXX,
//     XXXXXXX,  KC_6,    KC_7,    KC_8,    KC_9,    KC_PIPE, KC_BSLS, KC_2,    KC_3,    KC_4,     KC_5,    XXXXXXX,
//     XXXXXXX,  XXXXXXX, KC_LT,   KC_TILD, KC_GRV,  KC_COMM, KC_COMM, KC_HASH, KC_CIRC, KC_GT,    XXXXXXX, XXXXXXX
// ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |  UP  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  | Left | Down |Right |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Ctrl | RAlt | GUI  |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
// [_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_UP,   KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR,          KC_ASTR,          KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_F5,   KC_F6,   TD(TD_LBRC_LCBR), TD(TD_LBRC_LCBR), KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  S(KC_NUHS),       S(KC_NUBS),       KC_HOME, KC_END,  _______,
    _______, _______, KC_LCTL, KC_LALT, KC_LGUI,  _______, _______, _______,          KC_MNXT,          KC_VOLD, KC_VOLU, KC_MPLY
),
// _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_MFFD, KC_VOLD, KC_VOLU, KC_MPLY
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   -  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Prev | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
// [_RAISE] = LAYOUT_planck_grid(
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6,    KC_MINS, KC_EQL,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3,    KC_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  WORKMAN,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

};

// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
      return false;
      break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE &= ~(1<<6);
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE |= (1<<6);
    //     #endif
    //   }
    //   return false;
    //   break;
//     case PLOVER:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//           PLAY_SONG(plover_song);
//         #endif
//         layer_off(_RAISE);
//         layer_off(_LOWER);
//         layer_off(_ADJUST);
//         layer_on(_PLOVER);
//         if (!eeconfig_is_enabled()) {
//             eeconfig_init();
//         }
//         keymap_config.raw = eeconfig_read_keymap();
//         keymap_config.nkro = 1;
//         eeconfig_update_keymap(keymap_config.raw);
//       }
//       return false;
//       break;
//     case EXT_PLV:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_PLOVER);
//       }
//       return false;
//       break;
  }
  return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// void encoder_update(bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_DOWN);
//       #else
//         tap_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_UP);
//       #else
//         tap_code(KC_PGUP);
//       #endif
//     }
//   }
// }

// void dip_update(uint8_t index, bool active) {
//   switch (index) {
//     case 0:
//       if (active) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_song);
//         #endif
//         layer_on(_ADJUST);
//       } else {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_ADJUST);
//       }
//       break;
//     case 1:
//       if (active) {
//         muse_mode = true;
//       } else {
//         muse_mode = false;
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//         #endif
//       }
//    }
// }

// void matrix_scan_user(void) {
//   #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//       if (muse_counter == 0) {
//         uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//         if (muse_note != last_muse_note) {
//           stop_note(compute_freq_for_midi_note(last_muse_note));
//           play_note(compute_freq_for_midi_note(muse_note), 0xF);
//           last_muse_note = muse_note;
//         }
//       }
//       muse_counter = (muse_counter + 1) % muse_tempo;
//     }
//   #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
