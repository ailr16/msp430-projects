#ifndef CLOCK_H
#define CLOCK_H

#include <msp430g2553.h>

#define CLOCK_DCO_RESISTOR_REG_OFFSET         0u
#define CLOCK_DCO_RESISTOR_INTERNAL           0u
#define CLOCK_DCO_RESISTOR_EXTERNAL           1u

#define CLOCK_SMCLK_SOURCE_REG_OFFSET         3u
#define CLOCK_SMCLK_SOURCE_DCO                0u
#define CLOCK_SMCLK_SOURCE_XT2_LFXT1_VLO      1u

#define CLOCK_SMCLK_DIVIDE_REG_OFFSET         1u
#define CLOCK_SMCLK_DIVIDE_1                  0u
#define CLOCK_SMCLK_DIVIDE_2                  1u
#define CLOCK_SMCLK_DIVIDE_4                  2u
#define CLOCK_SMCLK_DIVIDE_8                  3u

#define CLOCK_MCLK_SOURCE_REG_OFFSET          6u
#define CLOCK_MCLK_SOURCE_DCO                 1u
#define CLOCK_MCLK_SOURCE_XT2_LFXT1_VLO       2u
#define CLOCK_MCLK_SOURCE_LFXT1_VLO           3u

#define CLOCK_MCLK_DIVIDE_REG_OFFSET          4u
#define CLOCK_MCLK_DIVIDE_1                   0u
#define CLOCK_MCLK_DIVIDE_2                   1u
#define CLOCK_MCLK_DIVIDE_4                   2u
#define CLOCK_MCLK_DIVIDE_8                   3u

typedef struct _ClockConfigType
{
    unsigned char DcoResistor  : 1;
    unsigned char SmClkSource  : 1;
    unsigned char SmClkDivider : 2;
    unsigned char MclkSource   : 2;
    unsigned char MclkDivider  : 2;
} ClockConfigType;

void configureMclkSmclk( const ClockConfigType *ClockConfig );

#endif