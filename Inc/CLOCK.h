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

#define CLOCK_DCO_FREQUENCY_REG_OFFSET        0u
#define CLOCK_DCO_FREQUENCY_RANGE_1           0u
#define CLOCK_DCO_FREQUENCY_RANGE_2           1u
#define CLOCK_DCO_FREQUENCY_RANGE_3           2u
#define CLOCK_DCO_FREQUENCY_RANGE_4           3u
#define CLOCK_DCO_FREQUENCY_RANGE_5           4u
#define CLOCK_DCO_FREQUENCY_RANGE_6           5u
#define CLOCK_DCO_FREQUENCY_RANGE_7           6u
#define CLOCK_DCO_FREQUENCY_RANGE_8           7u
#define CLOCK_DCO_FREQUENCY_RANGE_9           8u
#define CLOCK_DCO_FREQUENCY_RANGE_10          9u
#define CLOCK_DCO_FREQUENCY_RANGE_11          10u
#define CLOCK_DCO_FREQUENCY_RANGE_12          11u
#define CLOCK_DCO_FREQUENCY_RANGE_13          12u
#define CLOCK_DCO_FREQUENCY_RANGE_14          13u
#define CLOCK_DCO_FREQUENCY_RANGE_15          14u
#define CLOCK_DCO_FREQUENCY_RANGE_16          15u

#define CLOCK_DCO_MODULATOR_REG_OFFSET        0u
#define CLOCK_DCO_MODULATOR_MIN_VALUE         0u
#define CLOCK_DCO_MODULATOR_MAX_VALUE         31u

#define CLOCK_DCO_FREQUENCY_SELECT_REG_OFFSET 5u
#define CLOCK_DCO_FREQUENCY_SELECT_1          0u
#define CLOCK_DCO_FREQUENCY_SELECT_2          1u
#define CLOCK_DCO_FREQUENCY_SELECT_3          2u
#define CLOCK_DCO_FREQUENCY_SELECT_4          3u
#define CLOCK_DCO_FREQUENCY_SELECT_5          4u
#define CLOCK_DCO_FREQUENCY_SELECT_6          5u
#define CLOCK_DCO_FREQUENCY_SELECT_7          6u
#define CLOCK_DCO_FREQUENCY_SELECT_8          7u

#define CLOCK_ACLK_DIVIDE_REG_OFFSET          4u
#define CLOCK_ACLK_DIVIDE_1                   0u
#define CLOCK_ACLK_DIVIDE_2                   1u
#define CLOCK_ACLK_DIVIDE_4                   2u
#define CLOCK_ACLK_DIVIDE_8                   3u

#define CLOCK_XT2_ENABLED_REG_OFFSET          7u
#define CLOCK_XT2_ENABLED_TRUE                0u
#define CLOCK_XT2_ENABLED_FALSE               1u

#define CLOCK_XT2_RANGE_REG_OFFSET           6u
#define CLOCK_XT2_RANGE_400K_to_1M           0u
#define CLOCK_XT2_RANGE_1M_to_3M             1u
#define CLOCK_XT2_RANGE_3M_to_16M            2u
#define CLOCK_XT2_RANGE_DIGITAL_400K_to_16M  3u

#define CLOCK_XT1_MODE_REG_OFFSET          6u
#define CLOCK_XT1_MODE_LOW_FREQUENCY       0u
#define CLOCK_XT1_MODE_HIGH_FREQUENCY      1u

#define CLOCK_XT1_CLOCK_SELECT_REG_OFFSET              4u
#define CLOCK_XT1_CLOCK_SELECT_LF_32768K               0u
#define CLOCK_XT1_CLOCK_SELECT_LF_AVOID_THIS           1u
#define CLOCK_XT1_CLOCK_SELECT_LF_VLOCLK               2u
#define CLOCK_XT1_CLOCK_SELECT_LF_DIGITAL_EXTERNAL     3u
#define CLOCK_XT1_CLOCK_SELECT_HF_400K_to_1M           0u
#define CLOCK_XT1_CLOCK_SELECT_HF_1M_to_3M             1u
#define CLOCK_XT1_CLOCK_SELECT_HF_3M_to_16M            2u
#define CLOCK_XT1_CLOCK_SELECT_HF_DIGITAL_400K_to_16M  3u

#define CLOCK_XT1_CAPACITOR_REG_OFFSET     2u
#define CLOCK_XT1_CAPACITOR_1PF            0u
#define CLOCK_XT1_CAPACITOR_6PF            1u
#define CLOCK_XT1_CAPACITOR_10PF           2u
#define CLOCK_XT1_CAPACITOR_12P5F          3u

typedef struct _DcoConfigType
{
    unsigned char Modulator       : 5;
    unsigned char FrequencyRange  : 4;
    unsigned char FrequencySelect : 3;
} DcoConfigType;

typedef struct _Xt2ConfigType
{
    unsigned char Enabled     : 1;
    unsigned char RangeSelect : 2;
} Xt2ConfigType;

typedef struct _Lfxt1ConfigType
{
    unsigned char Mode        : 1;
    unsigned char ClockSelect : 2;
    unsigned char Capacitor   : 2; 
} Lfxt1ConfigType;

typedef struct _ClockConfigType
{
    unsigned char   DcoResistor  : 1;
    unsigned char   SmClkSource  : 1;
    unsigned char   SmClkDivider : 2;
    unsigned char   MclkSource   : 2;
    unsigned char   MclkDivider  : 2;
    unsigned char   AclkDivider  : 2;
    Lfxt1ConfigType Xt1Config;
    Xt2ConfigType   Xt2Config;
    DcoConfigType   DcoConfig;
} ClockConfigType;

void configureMclkSmclk( const ClockConfigType *ClockConfig );

#endif