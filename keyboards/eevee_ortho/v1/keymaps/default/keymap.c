// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NUM,
    GAY,
};

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_W)) {
        SEND_STRING(":w\n");
    }
    if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING(":q\n");
    }
    if (leader_sequence_two_keys(KC_W, KC_Q)) {
        SEND_STRING(":wq\n");
    }
    if (leader_sequence_three_keys(KC_W, KC_Q, KC_A)) {
        SEND_STRING(":wqa\n");
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┐
     * │ e │ 1 │ 2 │ 3 │ 4 │ 5 │         │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤         ├───┼───┼───┼───┼───┼───┤
     * │ t │ q │ w │ e │ r │ t │         │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┴───┤         ├───┼───┼───┼───┼───┴───┤
     * │ A │ a │ s │ d │ f │ g           │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┴───┤ ├───┼───┼───┼───┼───┼───┴───┤
     * │ A │ z │ x │ c │ v │ F │ G   │   │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┴───┤ ├───┼───┼───┼───┼───┼───┴───┤
     * │ A │ B │ C │ D │ E │ F │ H   │   │   │   │   │   │   │   │
     * └───┴───┴───┴───┴───┴───┴───┘ └───┴───┴───┴───┴───┴───┴───┘
     */
    [BASE] = LAYOUT_default(
        // LEFT HALF
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, QK_LEAD,
        KC_LEFT_CTRL, KC_LEFT_GUI, KC_LALT, TG(GAY), MO(SYM), MO(NUM), KC_BACKSPACE,
        // RIGHT HALF

        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENTER,
        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,
        KC_ENTER, KC_N, KC_M, KC_COMMA, KC_DOT, KC_UP, KC_SLASH,
        KC_SPACE, MO(NUM), MO(SYM), TG(GAY), KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [SYM] = LAYOUT_default(
        KC_GRAVE, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),
        _______, _______, _______, LSFT(KC_BACKSLASH), LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET),
        _______, _______, LSFT(KC_EQUAL), LSFT(KC_MINUS),  LSFT(KC_QUOTE), LSFT(KC_SEMICOLON), _______,
        _______, _______, _______, LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(KC_SLASH), _______,

        // Right half
        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),_______,
        KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_BACKSLASH, _______, _______, _______,
        _______, KC_SEMICOLON, KC_QUOTE, KC_MINUS, KC_EQUAL, KC_PAGE_UP, _______,
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
        _______, _______, KC_KP_DOT, KC_0, _______, _______, _______
    ),
    [GAY] = LAYOUT_default(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, _______,
        KC_LEFT_CTRL, KC_Z, MT(MOD_LALT, KC_X), KC_C, KC_V, KC_B, KC_SPACE,

        // Right
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        KC_BACKSPACE, _______, _______, _______, _______, _______, _______
    )
};
