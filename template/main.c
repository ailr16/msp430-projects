#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "CLOCK.h"
#include "GeneralFunctions.h"

const ClockConfigType test = {
	.DcoResistor  = CLOCK_DCO_RESISTOR_INTERNAL,
	.SmClkSource  = CLOCK_SMCLK_SOURCE_DCO,
	.SmClkDivider = CLOCK_SMCLK_DIVIDE_1,
	.MclkSource   = CLOCK_MCLK_SOURCE_DCO,
	.MclkDivider  = CLOCK_MCLK_DIVIDE_8
};

int main(void)
{
	configureMclkSmclk( &test );
	WDTCTL = WDTPW | WDTHOLD;
	
	setInputPin( DIO_PORT_1, DIO_PIN3 );
	setOutputPin( DIO_PORT_1, DIO_PIN0 );

	while(1)
	{
		setPin( DIO_PORT_1, DIO_PIN0 );
		for(unsigned int i = 0; i <= 0x6FFF; i++);
		clearPin( DIO_PORT_1, DIO_PIN0 );
		for(unsigned int i = 0; i <= 0x6FFF; i++);
	}

	return 0;
}
