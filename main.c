#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "CLOCK.h"

const ClockConfigType testClock = {
	.DcoResistor  = CLOCK_DCO_RESISTOR_DEFAULT,
	.SmClkSource  = CLOCK_SMCLK_SOURCE_DEFAULT,
	.SmClkDivider = CLOCK_SMCLK_DIVIDE_DEFAULT,
	.MclkSource   = CLOCK_MCLK_SOURCE_DEFAULT,
	.MclkDivider  = CLOCK_MCLK_DIVIDE_DEFAULT,
	.AclkDivider  = CLOCK_ACLK_DIVIDE_DEFAULT,
	.DcoConfig = {
		.FrequencyRange  = CLOCK_DCO_FREQUENCY_RANGE_DEFAULT,
		.Modulator       = CLOCK_DCO_MODULATOR_DEFAULT,
		.FrequencySelect = CLOCK_DCO_FREQUENCY_SELECT_DEFAULT
	},
	.Xt2Config = {
		.Enabled = CLOCK_XT2_ENABLED_DEFAULT,
		.RangeSelect = CLOCK_XT2_RANGE_DEFAULT
	},
	.Xt1Config = {
		.Mode = CLOCK_XT1_MODE_DEFAULT,
		.ClockSelect = CLOCK_XT1_CLOCK_SELECT_DEFAULT,
		.Capacitor = CLOCK_XT1_CAPACITOR_DEFAULT
	}
};

int main(void)
{
	configureMclkSmclk( &testClock );
	WDTCTL = WDTPW | WDTHOLD;
	
	setInputPin( DIO_PORT_1, DIO_PIN3 );
	setOutputPin( DIO_PORT_1, DIO_PIN0 );

	while(1)
	{
		setPin( DIO_PORT_1, DIO_PIN0 );
		for(unsigned int i = 0; i <= 0x1FFF; i++);
		clearPin( DIO_PORT_1, DIO_PIN0 );
		for(unsigned int i = 0; i <= 0x1FFF; i++);
	}

	return 0;
}
