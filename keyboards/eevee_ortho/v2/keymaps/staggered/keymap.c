// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NUM,
    GAM
};
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Leaders are defined here
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_1)) {
    }
    if (leader_sequence_one_key(KC_2)) {
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
        CW_TOGG, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_LEFT_CTRL, KC_LALT, KC_LGUI, MO(SYM), KC_SPACE, KC_BSPC,

        // RIGHT HALF
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENTER,
        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,
        KC_N, KC_M, KC_COMMA, KC_DOT, KC_UP, KC_SLASH,
        KC_SPACE, KC_BSPC, MO(NUM), MO(SYM), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [SYM] = LAYOUT_default(
        KC_GRAVE, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),
        _______, LSFT(KC_BACKSLASH), LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET), _______, _______,
        KC_CAPS_LOCK, LSFT(KC_EQUAL), LSFT(KC_MINUS),  LSFT(KC_QUOTE), LSFT(KC_SEMICOLON), _______,
        _______, LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(KC_SLASH), _______, _______,
        _______, _______, _______, _______, _______, _______,

        // Right half
        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),_______,
        _______, KC_SEMICOLON, KC_QUOTE, KC_MINUS, KC_EQUAL, _______,
        _______, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,  _______, KC_PAGE_UP, KC_BACKSLASH,
        _______,  _______, _______, _______, KC_HOME, KC_PAGE_DOWN, KC_END
    ),
    [NUM] = LAYOUT_default(
        LSFT(KC_GRAVE), _______, KC_F7, KC_F8, KC_F9, KC_F10,
        RSFT(KC_F12), _______, KC_F4, KC_F5, KC_F6, KC_F11,
        _______, _______, KC_F1, KC_F2, KC_F3, KC_F12,
        _______, TG(GAM), _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,

        // Right Half
        KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_MINUS, _______,
        KC_KP_SLASH, KC_4, KC_5, KC_6, KC_KP_PLUS, _______,
         _______, KC_1, KC_2, KC_3, _______, _______,
        _______, _______, _______, KC_0, KC_KP_DOT, _______, _______
    ),
    [GAM] = LAYOUT_default(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_V, _______, KC_B,

        // Right Half
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______
    ),
};
