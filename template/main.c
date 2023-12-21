#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;

	P1SEL  = 0x00;
    P1SEL2 = 0x00;	//all pins as i/o
    P1DIR = 0x01;	//pin 0 as output
	
	while(1)
	{
		unsigned char aux = P1IN;

		if( ((P1IN >> 3) & 0x01) == 1 )
		{
			P1OUT = 0x00;
		}
		else
		{
			P1OUT = 0x01;
		}
	}

	return 0;
}
