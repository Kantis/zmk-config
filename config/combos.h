#include "zmk-nodefree-config/include/zmk-helpers/helper.h"
#include "zmk-nodefree-config/include/zmk-helpers/key-labels/glove80.h"

#define COMBO_TERM_FAST 50

ZMK_COMBO(arrow, &PROG_arrow, RB2 RB3, ALL, COMBO_TERM_FAST)
ZMK_COMBO(elvis, &PROG_elvis, RB1 RB2, ALL, COMBO_TERM_FAST)

