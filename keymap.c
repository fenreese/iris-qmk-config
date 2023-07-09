// Copyright 2023 Reese Dominguez (@fenreese)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// tap shortcuts
#define ESC_CTL LCTL_T(KC_ESC)

// vim mode
#define BGN_WRD LCTL(KC_LEFT)
#define END_WRD LCTL(KC_RGHT)
#define VIM_SVE LCTL(KC_S)

// layers
#define MO_SYM MO(_SYMBOL)
#define MO_MED MO(_MEDIA)
#define TO_ADJ TO(_ADJUST)

// screenshots and such, for both MacOS and not-MacOS
#define MAC_PSCW LGUI(LSFT(KC_3))       // MacOS: capture screen
#define MAC_PSCR LGUI(LSFT(KC_4))       // MacOS: capture region
// may need to configure Alt + 1/2 in ShareX or your dotfiles
#define ETC_PSCW LALT(KC_2)             // Other: capture screen
#define ETC_PSCR LALT(KC_1)             // Other: capture region
// Windows: Print Screen/Snipping Tool
#define WIN_PSCR LGUI(LSFT(KC_S))       // Windows: capture region

// layers
enum custom_layers {
    _COLEMAK = 0,
    _QWERTY,
    _VIM,    // vim keybinds my beloved
    _SYMBOL, // i need another layer
    _MEDIA,  // play/pause/etc
    _ADJUST  // RGB and layer switching
};

// macros
enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    VIM_VIS,
    VIM_APD
};

// tapdance declarations
enum custom_tapdances {
    TD_VDEL,
    TD_VIM
};

// tap dance actions
tap_dance_action_t tap_dance_actions[] = {
    [TD_VDEL] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_DEL), // DD for delete, D for down
    [TD_VIM]  = ACTION_TAP_DANCE_LAYER_MOVE(KC_GRV, _VIM) // enable "Vim" mode/layer, else backtick
};

// encoder shenanigans
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_VIM] = {  },
    [_SYMBOL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_BRIU, KC_BRID), },
    [_ADJUST] = {  },
};
#endif

// combo shenanigans
const uint16_t PROGMEM layer_combo[] = {MO_SYM, MO_MED, COMBO_END};
combo_t key_combos[] = {
    COMBO(layer_combo, TO_ADJ)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      TD(TD_VIM), KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        ESC_CTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           KC_MUTE, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       MO_SYM,  KC_LGUI, KC_SPC,                    KC_SPC,  KC_RALT, MO_MED
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      TD(TD_VIM), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       MO_SYM,  KC_LGUI, KC_SPC,                    KC_SPC,  KC_RALT, MO_MED
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_VIM] = LAYOUT( // WIP for now as I get it set up for both MacOS and Windows
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX, XXXXXXX, VIM_SVE, END_WRD, XXXXXXX, XXXXXXX,                            XXXXXXX, KC_PGUP,TG(_VIM), XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       TG(_VIM), VIM_APD, XXXXXXX, TD_VDEL, XXXXXXX, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_VIS, BGN_WRD, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
    //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_SYMBOL] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_MEDIA] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_SLEP, ETC_PSCR,ETC_PSCW,MAC_PSCW,MAC_PSCR, _______,                            _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, KC_WREF, _______, _______,                            _______, KC_MRWD, KC_MFFD, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______,WIN_PSCR, KC_VOLD, KC_VOLU, KC_MPLY,                            KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, KC_MUTE, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, _______,                   _______,  _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

    [_ADJUST] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_ADJUST), _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                            RGB_TOG, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        QK_BOOT, _______, _______, _______, _______, _______,                            RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, CG_TOGG,          _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _______, _______, QWERTY,                    COLEMAK, _______, _______
                                  // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

// macro implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
            layer_move(_COLEMAK);
        }
        return false;
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
            layer_move(_QWERTY);
        }
        return false;
    case VIM_VIS: // -- VISUAL --
        if (record->event.pressed) {
            static bool sel_toggled = false; // Static to remember state
            sel_toggled = !sel_toggled;

            if (sel_toggled) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
        }
        return false;
    case VIM_APD: // -- INSERT -- (but append)
        if (record->event.pressed) {
            tap_code(KC_RIGHT);
            tap_code16(TG(_VIM)); // i promise this turns it off
        }
        return false;
  }
  return true;
}
