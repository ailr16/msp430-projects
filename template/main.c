#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "GeneralFunctions.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	
	setInputPin( DIO_PORT_1, DIO_PIN3 );
	setOutputPin( DIO_PORT_1, DIO_PIN0 );

	while(1)
	{
		unsigned char aux = P1IN;

		if( getPin( DIO_PORT_1, DIO_PIN3) == DIO_PIN_LOW )
		{
			setPin( DIO_PORT_1, DIO_PIN0 );
		}
		else
		{
			clearPin( DIO_PORT_1, DIO_PIN0 );
		}
	}

	return 0;
}
