#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"
#include "GeneralFunctions.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;

	P1SEL  = 0x00;
    P1SEL2 = 0x00;	//all pins as i/o
    P1DIR = 0x41;	//pin 0 as output
	
	while(1)
	{
		unsigned char aux = P1IN;

		if( GetBit( P1IN, 3 ) == 1 )
		{
			P1OUT = 0x00;
			ClearBit( &P1OUT, 0 );
			SetBit( &P1OUT, 6 );
		}
		else
		{
			SetBit( &P1OUT, 0 );
			ClearBit( &P1OUT, 6 );
		}
	}

	return 0;
}
