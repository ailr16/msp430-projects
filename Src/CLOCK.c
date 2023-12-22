#include "CLOCK.h"

void configureMclkSmclk( const ClockConfigType *ClockConfig )
{
    unsigned char aux = 0x00;

    aux |= ClockConfig->DcoResistor  << CLOCK_DCO_RESISTOR_REG_OFFSET;
    aux |= ClockConfig->MclkSource   << CLOCK_MCLK_SOURCE_REG_OFFSET;
    aux |= ClockConfig->MclkDivider  << CLOCK_MCLK_DIVIDE_REG_OFFSET;
    aux |= ClockConfig->SmClkSource  << CLOCK_SMCLK_SOURCE_REG_OFFSET;
    aux |= ClockConfig->SmClkDivider << CLOCK_SMCLK_DIVIDE_REG_OFFSET;

    BCSCTL2 |= aux;
}