#pragma once

#include "quantum.h"
#include "led.h"

#define LAYOUT_sixteen( K00, K01, K02, K03,  \
                        K04, K05, K06, K07,  \
                        K08, K09, K0A, K0B,  \
                        K0C, K0D, K0E, K0F   \
) {                                          \
    {K00, K01, K02, K03},                    \
    {K04, K05, K06, K07},                    \
    {K08, K09, K0A, K0B},                    \
    {K0C, K0D, K0E, K0F}                     \
}                                            \

