/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    MKEYS,
};

enum custom_keycodes {
    WINLOCK = SAFE_RANGE,
    RGB_STEALTH,
    RGB_VISIBLE,
};

enum td_keycodes {
    TD_WINAPP,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_WINAPP] = ACTION_TAP_DANCE_DOUBLE(KC_RWIN, KC_APP),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12,         KC_MUTE,    KC_PSCR,  WINLOCK,  KC_F13,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,     KC_EQL,         KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,        KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                     KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                     KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(MAC_FN),  TD(TD_WINAPP),  KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,      KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,    _______,  TG(MKEYS),  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,    _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  RGB_STEALTH,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,    _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  RGB_VISIBLE,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,      NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                    _______,  _______,  _______,    _______,    _______,  _______,    _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,       KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,      KC_F12,         KC_MUTE,    KC_PSCR,  WINLOCK,  KC_F13,
        KC_GRV,   KC_1,        KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,     KC_EQL,         KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,        KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,        KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,        KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                     KC_ENT,
        KC_LSFT,               KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                     KC_RSFT,              KC_UP,
        KC_LCTL,  MO(WIN_FN),  KC_LALT,                                KC_SPC,                                 KC_RALT,  TG(WIN_FN),  TD(TD_WINAPP),  KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,      KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,    _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,    _______,    KC_WH_L,  KC_WH_R,  KC_WH_U,
        RGB_TOG,  _______,  _______,  _______,  _______,  _______,  RGB_STEALTH,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    KC_BTN1,  KC_BTN2,  KC_WH_D,
        _______,  KC_BTN3,  _______,  _______,  _______,  _______,  RGB_VISIBLE,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            KC_BTN2,  KC_BTN1,  _______,  _______,  BAT_LVL,      NK_TOGG,  _______,  _______,  _______,  _______,              _______,              KC_MS_U,
        _______,  _______,  _______,                                _______,                                    _______,  _______,  _______,    _______,    KC_MS_L,  KC_MS_D,  KC_MS_R),

    [MKEYS] = LAYOUT_tkl_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,    _______,  TG(MKEYS),  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,    _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]     = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]     = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [MKEYS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t winlock_timer;

    switch (keycode) {
        // Win+L Tap-Hold emulation - only send combo when held over 200ms
        case WINLOCK:
            if (record->event.pressed) {
                winlock_timer = timer_read();
            } else {
                if (timer_elapsed(winlock_timer) >= 200) {
                    SEND_STRING(SS_LGUI("l"));
                }
            }
            return false;

        // RGB stealth mode - set HSV to be all zero for retaining layer indicators
        case RGB_STEALTH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                rgb_matrix_sethsv(0, 0, 0);
            }
            return false;

        // RGB visible mode - make everything colorful and dazzling
        case RGB_VISIBLE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
                rgb_matrix_sethsv(0, 255, 255);
            }
            return false;
        
        // Let Keychron take the wheel
        default:
            if (!process_record_keychron_common(keycode, record)) {
                return false;
            }
    }

    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const uint16_t arrow_key_lights[4] = {75, 84, 85, 86};
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

    // Make arrow keys glow when mouse keys layer is active
    for (uint8_t i = 0; i < 4; i++) {
        if (current_layer == WIN_FN) {
            rgb_matrix_set_color(arrow_key_lights[i], RGB_WHITE);
        }
    }

    // Escape key glow when on layer with mouse key bindings
    if (current_layer == WIN_BASE || current_layer == WIN_FN) {
        rgb_matrix_set_color(0, RGB_BLUE);
    }

    // WinLock key glow when on media keys fn layer
    if (current_layer == MKEYS) {
        rgb_matrix_set_color(14, RGB_WHITE);
    }
    return false;
}
