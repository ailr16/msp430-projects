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

		if( GetBit( P1IN, DIO_PIN3 ) == 0 )
		{
			SetBit( &P1OUT, DIO_PIN0 );
		}
		else
		{
			ClearBit( &P1OUT, DIO_PIN0 );
		}
	}

	return 0;
}
