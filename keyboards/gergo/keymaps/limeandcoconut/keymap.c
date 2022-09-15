/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define WORKMAN 0 // Default layer
#define ADVANCE 1 // Symbols
#define RAISE 2 // Numbers/Navigation
#define LOWER 3 // Function layer
// #define QWERTY 4 // Qwerty layer

// Blank template at the bottom

enum customKeycodes {
    CMD_TAB = SAFE_RANGE,
    CSH_TAB,
};

// ADD this near the begining of keymap.c
bool cmd_tab_active = false;
// We will be using them soon.
uint16_t cmd_tab_timer = 0;

/* Effort Grading
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |     4  |   4  |   2  |   2  |   3  |   4  |                         |   4  |   3  |   2  |   2  |   4  |     4  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |     3  |  1.5 |   1  |   1  |   1  |   3  |   5  |           |   5  |   3  |   1  |   1  |   1  |  1.5 |     3  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |     3  |   4  |   4  |   3  |   2  |   4  |   5  |           |   5  |   4  |   2  |   3  |   4  |   4  |     3  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    |     2    |   |  1.5  |                                 |  1.5 |   |  2  |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        |   5   |                      |   5   |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      |       |      |
 *                                 |   3  |   4   |                      |    4  |   3  |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Workman layer +
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  ESC   |   Q  |   D  |   R  |   W  |   B  |                         |   J  |   F  |   U  |   P  |   -  |   DEL  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   H  |   T  |   G  | RMB  |           | Win► |   Y  |   N  |   E  |   O  |   I  |  Enter |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   M  |   C  |   V  | LMB  |           | ◄Win |   K  |   L  | ,  < | . >  | /  ? |   Tab  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .-------.   .-------.
 *                    |   Super  |   |ADVANCE|                                 | RAISE |   | Space |
 *                    '----------'   '-------'                                 `-------'   '-------'
 *                                        ,-------.                      ,-------.
 *                                        | EMOJI |                      | LOWER |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      | Enter |      |
 *                                 |  ALT |  ESC  |                      | LOWER | BKSP |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[WORKMAN] = LAYOUT_gergo(
    KC_ESC,  KC_Q, KC_D, KC_R, KC_W, KC_B,                                                 KC_J, KC_F, KC_U,    KC_P,   KC_MINS, KC_DEL,
    KC_LSFT, KC_A, KC_S, KC_H, KC_T, KC_G, KC_BTN2,                          G(KC_GRV),    KC_Y, KC_N, KC_E,    KC_O,   KC_I,    KC_ENT,
    KC_LCTL, KC_Z, KC_X, KC_M, KC_C , KC_V, KC_BTN1, C(G(KC_SPC)), TT(LOWER), KC_BTN3, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_TAB,
                    KC_LGUI,  TT(ADVANCE), KC_LALT, KC_ESC,       LT(LOWER, KC_ENT), KC_BSPC, TT(RAISE), KC_SPC
    ),
/* Keymap 1: ADVANCE (Symbols layer) +
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  *   |  !   |  =   |  +   |  \   |                         |   #  |  >   |  <   |  ;   |  ~   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  App►  |  ,   |  {   |  }   |  /   |  ?   |      |           |      |   "  |  .   |  )   |  (   |  `   |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  ◄App  |  $   |  &   |  |   |  '   |  @   |      |           |      |   ^  |  :   |  ]   |  [   |  -   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .-------.   .-------.
 *                    |   Super  |   |ADVANCE|                                 | RAISE |   | Space |
 *                    '----------'   '-------'                                 `-------'   '-------'
 *                                        ,-------.                      ,-------.
 *                                        | EMOJI |                      | LOWER |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      | Enter |      |
 *                                 |  ALT |  ESC  |                      | LOWER | BKSP |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[ADVANCE] = LAYOUT_gergo(
    KC_TRNS, KC_ASTR, KC_EXLM, KC_EQL,  KC_PLUS, KC_BSLS,                                            KC_HASH, KC_RABK, KC_LABK, KC_SCLN, KC_TILD, KC_TRNS,
    CMD_TAB, KC_COMM, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES, KC_TRNS,                          KC_TRNS, KC_DQT,  KC_DOT,  KC_RPRN, KC_LPRN, KC_GRV,  KC_TRNS,
    CSH_TAB, KC_DLR,  KC_AMPR, KC_PIPE, KC_QUOT, KC_AT,   KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_CIRC, KC_COLN, KC_RBRC, KC_LBRC, KC_MINS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: RAISE (Num/Navigation layer) +
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |BRGHT-|   7  |   8  |  9   |BRGHT+|                         | MUTE | << M | PlyPS| M >> | -Vol |  +Vol  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |   0  |   4  |   5  |  6   | Find |      |           |      | Spot | LEFT | DOWN |  UP  | RIGHT|  PgUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |   1  |   2  |  3   |  +   |      |           |      | CPLK | MLFT | MDWN | MUP  | MRGHT|  PgDn  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .-------.   .-------.
 *                    |   Super  |   |ADVANCE|                                 | RAISE |   | Space |
 *                    '----------'   '-------'                                 `-------'   '-------'
 *                                        ,-------.                      ,-------.
 *                                        | EMOJI |                      | LOWER |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      | Enter |      |
 *                                 |  ALT |  ESC  |                      | LOWER | BKSP |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[RAISE] = LAYOUT_gergo(
    KC_TRNS, KC_BRID, KC_7, KC_8, KC_9, KC_BRIU,                                       KC_MUTE,   KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_0,    KC_4, KC_5, KC_6, KC_FIND,  KC_TRNS,                    KC_TRNS, G(KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP,
    KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_PLUS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_CAPS,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_PGDN,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 3: LOWER (Function layer)
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |BRGHT-|BRGHT+|                         | MUTE | << M | PlyPS| M >> | -Vol |  +Vol  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   | F6   |           |      | Spot | LEFT | DOWN |  UP  | RIGHT|  PgUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F7  |  F8  | F9   | F10  | F11  | F12  |           |      | CPLK | MLFT | MDWN | MUP  | MRGHT|  PgDn  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .-------.   .-------.
 *                    |   Super  |   |ADVANCE|                                 | RAISE |   | Space |
 *                    '----------'   '-------'                                 `-------'   '-------'
 *                                        ,-------.                      ,-------.
 *                                        | EMOJI |                      | LOWER |
 *                                 ,------|-------|                      |-------|------.
 *                                 |      |       |                      | Enter |      |
 *                                 |  ALT |  ESC  |                      | LOWER | BKSP |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[LOWER] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU,                                          KC_MUTE,   KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_TRNS,  G(KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_TRNS,  KC_CAPS,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_PGDN,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
// /* Keymap 4: Qwerty layer
//  *
//  * ,-------------------------------------------.                         ,-------------------------------------------.
//  * |        |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |        |
//  * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
//  * |        |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  | ;  : |        |
//  * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
//  * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,  < | . >  | /  ? |        |
//  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
//  *                    .----------.   .-------.                                 .-------.   .-------.
//  *                    |   Super  |   |ADVANCE|                                 | RAISE |   | Space |
//  *                    '----------'   '-------'                                 `-------'   '-------'
//  *                                        ,-------.                      ,-------.
//  *                                        | EMOJI |                      | LOWER |
//  *                                 ,------|-------|                      |-------|------.
//  *                                 |      |       |                      | Enter |      |
//  *                                 |  ALT |  ESC  |                      | LOWER | BKSP |
//  *                                 |      |       |                      |       |      |
//  *                                 `--------------'                      `--------------'
//  */
// [QWERTY] = LAYOUT_gergo(
//     KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T,                                     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_PIPE,
//     KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TRNS,                   KC_TRNS, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
//     KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
//                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//     ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Debug logging
    // print("keycode");
    // return true;
    switch (keycode) {

        case CSH_TAB:
            if (record->event.pressed) {
                if (!cmd_tab_active) {
                    cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_TAB);
            }
            break;
            return false;
        case CMD_TAB:
            if (record->event.pressed) {
                if (!cmd_tab_active) {
                    cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_TAB);
                // unregister_code(KC_LSFT);
            } else {
                unregister_code(KC_TAB);
            }
            break;
            return false;
        // case QWERTY:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(QWERTY);
        //     }
        //     return false;
        //     break;
        case WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(WORKMAN);
            }
            return false;
            break;
    }
    return true;
}

// The very important timer.
void matrix_scan_user(void) {
    if (cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 1200) {
            unregister_code(KC_LGUI);
            cmd_tab_active = false;
        }
    }
}

