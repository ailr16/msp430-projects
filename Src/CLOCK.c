#include "CLOCK.h"
#include "GeneralFunctions.h"

void configureMclkSmclk( const ClockConfigType *ClockConfig )
{
    unsigned char aux = 0x00;

    if( ClockConfig->DcoConfig.Modulator >= CLOCK_DCO_MODULATOR_MIN_VALUE &&
        ClockConfig->DcoConfig.Modulator <= CLOCK_DCO_MODULATOR_MAX_VALUE)
        {
            aux |= ClockConfig->DcoConfig.Modulator;
        }
    aux |= ClockConfig->DcoConfig.FrequencySelect << CLOCK_DCO_FREQUENCY_SELECT_REG_OFFSET;
    DCOCTL = aux;

    aux = 0x00;
    aux |= ClockConfig->DcoConfig.FrequencyRange << CLOCK_DCO_FREQUENCY_REG_OFFSET;
    aux |= ClockConfig->AclkDivider << CLOCK_ACLK_DIVIDE_REG_OFFSET;
    aux |= ClockConfig->Xt1Config.Mode << CLOCK_XT1_MODE_REG_OFFSET;
    aux |= ClockConfig->Xt2Config.Enabled << CLOCK_XT2_ENABLED_REG_OFFSET;
    BCSCTL1 = aux;    

    aux = 0x00;
    aux |= ClockConfig->DcoResistor  << CLOCK_DCO_RESISTOR_REG_OFFSET;
    aux |= ClockConfig->SmClkDivider << CLOCK_SMCLK_DIVIDE_REG_OFFSET;
    aux |= ClockConfig->SmClkSource  << CLOCK_SMCLK_SOURCE_REG_OFFSET;
    aux |= ClockConfig->MclkDivider  << CLOCK_MCLK_DIVIDE_REG_OFFSET;
    aux |= ClockConfig->MclkSource   << CLOCK_MCLK_SOURCE_REG_OFFSET;
    BCSCTL2 = aux;

    aux = 0x00;
    aux |= ClockConfig->Xt1Config.Capacitor << CLOCK_XT1_CAPACITOR_REG_OFFSET;
    aux |= ClockConfig->Xt1Config.ClockSelect << CLOCK_XT1_CLOCK_SELECT_REG_OFFSET;
    aux |= ClockConfig->Xt2Config.RangeSelect << CLOCK_XT2_RANGE_REG_OFFSET;
    ClearBitMask( &BCSCTL3, 0xFC );
    SetBitMask( &BCSCTL3, aux );
}