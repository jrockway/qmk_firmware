#pragma once

#include "quantum.h"
#include "led.h"

#define LAYOUT_sixteen(K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F) \
    {                                                                                                  \
        {K00, K01, K02, K03}, {K04, K05, K06, K07}, {K08, K09, K0A, K0B}, { K0C, K0D, K0E, K0F }       \
    }

// clang-format off
#define LAYOUT_ergorocks(          \
L00, L01, L02, L03, L04, L05, L06, \
L07, L08, L09, L10, L11, L12, L13, \
L14, L15, L16, L17, L18, L19, L20, \
L21, L22, L23, L24, L25, L26, L27, \
L28, L29, L30, L31, L32, L33, L34, \
     L35, L36, L37, L38, L39, L40, \
                                   \
C00, C01, C02, C03,                \
C04, C05, C06, C07,                \
C08, C09, C10,                     \
C11, C12, C13, C14,                \
C15, C16, C17,                     \
C18,      C19, C20,                \
                                   \
    A0,                            \
A1, A2, A3,			      \
                                   \
R00, R01, R02, R03, R04, R05, R06, \
R07, R08, R09, R10, R11, R12, R13, \
R14, R15, R16, R17, R18, R19, R20, \
R21, R22, R23, R24, R25, R26, R27, \
R28, R29, R30, R31, R32, R33, R34, \
R35, R36, R37, R38, R39, R40       \
)				      \
{                                  \
       {L00, L01, L02, L03, L04, L05, L06, C00, C01, C02, C03, KC_NO, KC_NO, KC_NO, R00, R01, R02, R03, R04, R05, R06},       \
       {L07, L08, L09, L10, L11, L12, L13, C04, C05, C06, C07, KC_NO, KC_NO, KC_NO, R07, R08, R09, R10, R11, R12, R13},       \
	{L14, L15, L16, L17, L18, L19, L20, C08, C09, C10, KC_NO, KC_NO, KC_NO, KC_NO, R14, R15, R16, R17, R18, R19, R20},     \
	{L21, L22, L23, L24, L25, L26, L26, C11, C12, C13, C14, KC_NO, KC_NO, KC_NO, R21, R22, R23, R24, R25, R26, R27},       \
	{L28, L29, L30, L31, L32, L33, L34, C15, C16, C17, A0, A1, A2, A3, R28, R29, R30, R31, R32, R33, R34},                 \
	{KC_NO, L35, L36, L37, L38, L39, L40, KC_NO, C18, C19, C20, KC_NO, KC_NO, KC_NO, R35, R36, R37, R38, KC_NO, R39, R40}, \
}
// clang-format on

// ghbcdef
// abcdefg
