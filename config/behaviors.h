#include "zmk-nodefree-config/include/zmk-helpers/helper.h"
#include "zmk-nodefree-config/include/zmk-helpers/key-labels/glove80.h"
#include "layer_names.h"

#define KEYS_L LC1 LC2 LC3 LC4 LC5 LN0 LN1 LN2 LN3 LN4 LN5 LT0 LT1 LT2 LT3 LT4 LT5 LM0 LM1 LM2 LM3 LM4 LM5 LB0 LB1 LB2 LB3 LB4 LB5  // left-hand keys
#define KEYS_R RC1 RC2 RC3 RC4 RC5 RN0 RN1 RN2 RN3 RN4 RN5 RT0 RT1 RT2 RT3 RT4 RT5 RM0 RM1 RM2 RM3 RM4 RM5 RB0 RB1 RB2 RB3 RB4 RB5  // right-hand keys
#define THUMBS LH5 LH4 LN3 LH2 LH1 LH0 RH0 RH1 RH2 RH3 RH4 RH5              // thumb keys
                                                                            //
/**
 * Homerow mods
 */

/* left-hand HRMs */
ZMK_BEHAVIOR(hml, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <280>;
    quick-tap-ms = <175>;                // repeat on tap-into-hold
    require-prior-idle-ms = <150>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <KEYS_R THUMBS>;
    hold-trigger-on-release;             // delay positional check until key-release
)

/* right-hand HRMs */
ZMK_BEHAVIOR(hmr, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <280>;
    quick-tap-ms = <175>;                // repeat on tap-into-hold
    require-prior-idle-ms = <150>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <KEYS_L THUMBS>;
    hold-trigger-on-release;             // delay positional check until key-release
)


/**
 * Pinky hold_taps
 * Used to toggle layers by holding pinky finger on nearby keys (primary pinky key is used for Homerow mod)
 */

/* left pinky-tap */
ZMK_BEHAVIOR(lpt, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <280>;
    quick-tap-ms = <175>;                // repeat on tap-into-hold
    require-prior-idle-ms = <150>;
    bindings = <&mo>, <&kp>;             // layer toggle on hold, kp on tap
    hold-trigger-key-positions = <KEYS_R THUMBS>;
    hold-trigger-on-release;             // delay positional check until key-release
)

/* right pinky-tap */
ZMK_BEHAVIOR(rpt, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <280>;
    quick-tap-ms = <175>;                // repeat on tap-into-hold
    require-prior-idle-ms = <150>;
    bindings = <&mo>, <&kp>;             // layer toggle on hold, kp on tap
    hold-trigger-key-positions = <KEYS_L THUMBS>;
    hold-trigger-on-release;             // delay positional check until key-release
)


/**
 * Space hold_tap
 * Used to toggle layer by holding the space key. Quickly double-tapping should start sending repeat spaces.
 */

// SPACE_HOLDING_TIME defines how long you need to hold (milliseconds)
// the space thumb key to activate.  Shorter holds are treated as taps.
#define SPACE_HOLDING_TIME 170

// SPACE_REPEAT_DECAY defines how much time you have left (milliseconds)
// after tapping a key to hold it again in order to make it auto-repeat.
#define SPACE_REPEAT_DECAY 200 // "tap then hold" for key auto-repeat

ZMK_BEHAVIOR(space, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <SPACE_HOLDING_TIME>;
    quick-tap-ms = <SPACE_REPEAT_DECAY>;
    retro-tap;
    bindings = <&mo>, <&kp>;
)

/**
 * Tap dances
 */

// For the "layer" key, it'd nice to be able to use it as either a shift or a toggle.
// Configure it as a tap dance, so the first tap (or hold) is a &mo and the second tap is a &to
ZMK_BEHAVIOR(lower, tap_dance,
  tapping-term-ms = <200>;
  bindings = <&mo 1>, <&to 1>;
)

ZMK_BEHAVIOR(shiftdance, tap_dance,
  tapping-term-ms = <200>;
  bindings = <&kp RSHFT>, <&caps_word>, <&kp CAPSLOCK>;
)

ZMK_BEHAVIOR(alt_swe, tap_dance,
  tapping-term-ms = <200>;
  bindings = <&kp ESC>, <&to SWE>;
)

