#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "CLOCK.h"

const ClockConfigType testClock = {
	.DcoResistor  = CLOCK_DCO_RESISTOR_INTERNAL,
	.SmClkSource  = CLOCK_SMCLK_SOURCE_DCO,
	.SmClkDivider = CLOCK_SMCLK_DIVIDE_1,
	.MclkSource   = CLOCK_MCLK_SOURCE_DCO,
	.MclkDivider  = CLOCK_MCLK_DIVIDE_1,
	.AclkDivider  = CLOCK_ACLK_DIVIDE_8,
	.DcoConfig = {
		.FrequencyRange  = CLOCK_DCO_FREQUENCY_RANGE_8,
		.Modulator       = 0u,
		.FrequencySelect = CLOCK_DCO_FREQUENCY_SELECT_4
	},
	.Xt2Config = {
		.Enabled = CLOCK_XT2_ENABLED_TRUE,
		.RangeSelect = CLOCK_XT2_RANGE_400K_to_1M
	},
	.Xt1Config = {
		.Mode = CLOCK_XT1_MODE_LOW_FREQUENCY,
		.ClockSelect = CLOCK_XT1_CLOCK_SELECT_LF_32768K,
		.Capacitor = CLOCK_XT1_CAPACITOR_6PF
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
