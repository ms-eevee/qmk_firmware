// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgb_matrix.h"

enum layers {
    BASE,
    SYM,
    NUM,
    GAM
};

// Key overrides are defined here
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
	&delete_key_override
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
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
    [SYM] = LAYOUT(
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
    [NUM] = LAYOUT(
        LSFT(KC_GRAVE), _______, KC_F7, KC_F8, KC_F9, KC_F10,
        RSFT(KC_F12), _______, KC_F4, KC_F5, KC_F6, KC_F11,
        _______, _______, KC_F1, KC_F2, KC_F3, KC_F12,
        _______, TG(GAM), _______, _______, _______, RM_NEXT,
        _______, _______, _______, _______, _______, _______,

        // Right Half
        KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_MINUS, _______,
        KC_KP_SLASH, KC_4, KC_5, KC_6, KC_KP_PLUS, _______,
         _______, KC_1, KC_2, KC_3, _______, _______,
        _______, _______, _______, KC_0, KC_KP_DOT, _______, _______
    ),
    [GAM] = LAYOUT(
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
    )
};

void board_init(void) {
    // wait_ms(10); // Add a 1000 millisecond (1 second) delay
    // You can add other hardware initializations here
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}


#ifdef ENABLE_KEEB_RGB
const is31fl3729_led_t PROGMEM g_is31fl3729_leds[IS31FL3729_LED_COUNT] = {
    { 0, SW2_CS3, SW2_CS2, SW2_CS1 },
    { 0, SW3_CS3, SW3_CS2, SW3_CS1 },
    { 0, SW4_CS3, SW4_CS2, SW4_CS1 },
    { 0, SW5_CS3, SW5_CS2, SW5_CS1 },
    { 0, SW6_CS3, SW6_CS2, SW6_CS1 },
    { 0, SW7_CS3, SW7_CS2, SW7_CS1 },

    { 0, SW2_CS6, SW2_CS5, SW2_CS4 },
    { 0, SW3_CS6, SW3_CS5, SW3_CS4 },
    { 0, SW4_CS6, SW4_CS5, SW4_CS4 },
    { 0, SW5_CS6, SW5_CS5, SW5_CS4 },
    { 0, SW6_CS6, SW6_CS5, SW6_CS4 },
    { 0, SW7_CS6, SW7_CS5, SW7_CS4 },

    { 0, SW2_CS9, SW2_CS8, SW2_CS7 },
    { 0, SW3_CS9, SW3_CS8, SW3_CS7 },
    { 0, SW4_CS9, SW4_CS8, SW4_CS7 },
    { 0, SW5_CS9, SW5_CS8, SW5_CS7 },
    { 0, SW6_CS9, SW6_CS8, SW6_CS7 },
    { 0, SW7_CS9, SW7_CS8, SW7_CS7 },

    { 0, SW2_CS12, SW2_CS11, SW2_CS10 },
    { 0, SW3_CS12, SW3_CS11, SW3_CS10 },
    { 0, SW4_CS12, SW4_CS11, SW4_CS10 },
    { 0, SW5_CS12, SW5_CS11, SW5_CS10 },
    { 0, SW6_CS12, SW6_CS11, SW6_CS10 },
    { 0, SW7_CS12, SW7_CS11, SW7_CS10 },


    { 0, SW1_CS12, SW1_CS11, SW1_CS10 },
    { 0, SW2_CS15, SW2_CS14, SW2_CS13 },
    { 0, SW3_CS15, SW3_CS14, SW3_CS13 },
    { 0, SW4_CS15, SW4_CS14, SW4_CS13 },
    { 0, SW5_CS15, SW5_CS14, SW5_CS13 },
    { 0, SW6_CS15, SW6_CS14, SW6_CS13 },
    { 0, SW7_CS15, SW7_CS14, SW7_CS13 },

};

led_config_t g_led_config = { {
    { NO_LED, 0, 1, 2, 3, 4, 5 },
    { NO_LED, 6, 7, 8, 9, 10, 11 },
    { NO_LED, 12, 13, 14, 15, 16, 17 },
    { NO_LED, 18, 19, 20, 21, 22, 23 },
    { NO_LED, 24, 26, 27, 28, 29, 30 },

    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,NO_LED },
    { NO_LED, 31, 32, 33, 34, 35, 36 },
    { NO_LED, 37, 38, 39, 40, 41, 42 },
    { NO_LED, 43, 44, 45, 46, 47, 48 },
    { 55, 49, 50, 51, 52, 53, 54 },

  }, {
      // Left to Right
      { 0, 0  }, { 17, 0  }, { 34, 0  }, { 51, 0  }, { 68, 0  }, { 86, 0  },
      { 0, 13 }, { 17, 13 }, { 34, 13 }, { 51, 13 }, { 68, 13 }, { 86, 13 },
      { 0, 25 }, { 17, 25 }, { 34, 25 }, { 51, 25 }, { 68, 25 }, { 86, 25 },
      { 0, 38 }, { 17, 38 }, { 34, 38 }, { 51, 38 }, { 68, 38 }, { 86, 38 },
      { 0, 51 }, { 17, 51 }, { 34, 54 }, { 51, 55 }, { 68, 57 }, { 86, 62 },


                   { 137, 0  }, { 155, 0  }, { 172, 0  }, { 189, 0  }, { 206, 0  }, { 224, 0  },
                   { 137, 16 }, { 155, 16 }, { 172, 16 }, { 189, 16 }, { 206, 16 }, { 224, 16 },
                   { 137, 32 }, { 155, 32 }, { 172, 32 }, { 189, 32 }, { 206, 32 }, { 224, 32 },
      { 120, 52 }, { 137, 48 }, { 155, 48 }, { 172, 48 }, { 189, 48 }, { 206, 48 }, { 224, 48 },
  }, {
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,

      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1
  } };
#endif
