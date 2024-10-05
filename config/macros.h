#include "zmk-nodefree-config/include/zmk-helpers/helper.h"

//////////////////////////////////////////////////////////////////////////
//
// Approximation of Pascal Getreuer's Select Word macro from QMK
// - https://getreuer.info/posts/keyboards/select-word/index.html
//
//////////////////////////////////////////////////////////////////////////

// SELECT_WORD_DELAY defines how long the macro waits (milliseconds)
// after moving the cursor before it selects a word.  A larger delay
// may allow the macro to move to the next word upon each invocation.
#define SELECT_WORD_DELAY 1

ZMK_MACRO(select_none,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp DOWN &kp UP &kp RIGHT &kp LEFT>;
)


/**
 * Select word, including mod-morph for selecting left by holding shift
 */
ZMK_MOD_MORPH(select_word,
    bindings = <&select_word_right>, <&select_word_left>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_MACRO(select_word_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(RIGHT) &kp LA(LEFT) &kp LA(LS(RIGHT))>;
)

ZMK_MACRO(select_word_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LEFT) &kp LA(RIGHT) &kp LA(LS(LEFT))>;
)


/**
 * Extend word
 */
ZMK_MOD_MORPH(extend_word,
    bindings = <&extend_word_right>, <&extend_word_left>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_MACRO(extend_word_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LS(RIGHT))>;
)

ZMK_MACRO(extend_word_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LA(LS(LEFT))>;
)


/**
 * Select line
 */
ZMK_MOD_MORPH(select_line,
    bindings = <&select_line_right>, <&select_line_left>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_MACRO(select_line_right,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LG(LEFT) &kp LS(LG(RIGHT))>;
)

ZMK_MACRO(select_line_left,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LG(RIGHT) &kp LS(LG(LEFT))>;
)


/**
 * Extend line
 * - Extends current selection by one line
 */
ZMK_MOD_MORPH(extend_line,
    bindings = <&extend_line_down>, <&extend_line_up>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)

ZMK_MACRO(extend_line_down,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LS(DOWN) &kp LS(LG(RIGHT))>;
)

ZMK_MACRO(extend_line_up,
    wait-ms = <SELECT_WORD_DELAY>;
    tap-ms = <SELECT_WORD_DELAY>;
    bindings = <&kp LS(UP) &kp LS(LG(LEFT))>;
)


/**
 * Swedish special characters
 */
ZMK_MACRO(SWE_aring,
    bindings = <&macro_press &kp LALT>, <&macro_tap &kp W>, <&macro_release &kp LALT>;
)

ZMK_MACRO(SWE_aumlaut,
    bindings = <&macro_press &kp LALT>, <&macro_tap &kp A>, <&macro_release &kp LALT>;
)

ZMK_MACRO(SWE_oumlaut,
    bindings = <&macro_press &kp LALT>, <&macro_tap &kp O>, <&macro_release &kp LALT>;
)

/**
 * Programming macros for special symbol combinations
 */

// -> 
ZMK_MACRO(PROG_arrow,
    bindings = <&macro_tap &kp MINUS &kp GREATER_THAN>;
)

/**
 * Glove80 defaults
 */
// Show RGB underglow indicators (bluetooth profiles, battery status, etc)
ZMK_MACRO(rgb_ug_status_macro,
    bindings = <&rgb_ug RGB_STATUS>;
)

// Select Bluetooth profile 1
ZMK_MACRO(bt_0,
    bindings = <&out OUT_BLE &bt BT_SEL 0>;
)

// Select Bluetooth profile 2
ZMK_MACRO(bt_1,
    bindings = <&out OUT_BLE &bt BT_SEL 1>;
)

// Select Bluetooth profile 3
ZMK_MACRO(bt_2,
    bindings = <&out OUT_BLE &bt BT_SEL 2>;
)

// Select Bluetooth profile 4
ZMK_MACRO(bt_3,
    bindings = <&out OUT_BLE &bt BT_SEL 3>;
)

/**
 * Hyper + Meh
 */
ZMK_MACRO(hyper,
    bindings = <&kp LGUI &kp LCTRL &kp LALT &kp LSHIFT>;
)

/**
 * Clipboard
 */
ZMK_MACRO(copy,
    bindings = <&macro_press &kp LGUI>, <&macro_tap &kp C>, <&macro_release &kp LGUI>;
)

ZMK_MACRO(paste,
    bindings = <&macro_press &kp LGUI>, <&macro_tap &kp V>, <&macro_release &kp LGUI>;
)

ZMK_MACRO(cut,
    bindings = <&macro_press &kp LGUI>, <&macro_tap &kp X>, <&macro_release &kp LGUI>;
)

/**
 * Undo + Redo
 */

ZMK_MACRO(undo,
    bindings = <&macro_press &kp LGUI>, <&macro_tap &kp Z>, <&macro_release &kp LGUI>;
)

ZMK_MACRO(redo,
    bindings = <&macro_press &kp LGUI>, <&macro_tap &kp Y>, <&macro_release &kp LGUI>;
)
