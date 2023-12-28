#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "CLOCK.h"

extern ClockConfigType clockConfig;

int main(void)
{
	configureMclkSmclk( &clockConfig );
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
