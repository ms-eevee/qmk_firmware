// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NUM,
    DEL,
};
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Leaders are defined here
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_1)) {
        layer_off(DEL);
    }
    if (leader_sequence_one_key(KC_2)) {
        layer_on(DEL);
    }
}

// Key overrides are defined here
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
	&delete_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_default(
        // LEFT HALF
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_LEFT_CTRL, KC_A, KC_S, KC_D, KC_F, KC_G, QK_LEAD,
        KC_LEFT_SHIFT, MT(MOD_LGUI, KC_Z), MT(MOD_LALT, KC_X), LT(SYM, KC_C), LT(NUM, KC_V), MT(MOD_LCTL, KC_B), KC_SPACE,

        // RIGHT HALF
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENTER,
        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,
        KC_ENTER, KC_N, KC_M, KC_COMMA, KC_DOT, KC_UP, KC_SLASH,
        KC_SPACE, KC_BSPC, MO(NUM), MO(SYM), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [SYM] = LAYOUT_default(
        KC_GRAVE, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),
        _______, _______, _______, LSFT(KC_BACKSLASH), LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET),
        _______, _______, LSFT(KC_EQUAL), LSFT(KC_MINUS),  LSFT(KC_QUOTE), LSFT(KC_SEMICOLON), _______,
        _______, _______, _______, LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(KC_SLASH), _______,

        // Right half
        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),_______,
        _______, KC_SEMICOLON, KC_QUOTE, KC_MINUS, KC_EQUAL, _______,
        _______, _______, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,  _______, KC_PAGE_UP, KC_BACKSLASH,
        _______,  _______, _______, _______, KC_HOME, KC_PAGE_DOWN, KC_END
    ),
    [NUM] = LAYOUT_default(
        LSFT(KC_GRAVE), _______, KC_F7, KC_F8, KC_F9, KC_F10,
        _______, _______, KC_F4, KC_F5, KC_F6, KC_F11,
        _______, _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
        _______, _______, _______, _______, _______, _______, KC_DELETE,

        // Right Half
        KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_MINUS, _______,
        KC_KP_SLASH, KC_4, KC_5, KC_6, KC_KP_PLUS, _______,
        _______, _______, KC_1, KC_2, KC_3, _______, _______,
        _______, _______, _______, KC_0, KC_KP_DOT, _______, _______
    ),
    [DEL] = LAYOUT_default(
        _______, _______, _______, _______, _______, _______,
        _______, _______, KC_UP, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_ENTER,

        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    )
};
