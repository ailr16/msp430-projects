#include <msp430g2553.h>

#include "DIO.h"
#include "PWM.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	setInputPin(0, 0, 0);
	setPwmPin(0, 0, 0);
	
	while(1)
	{
		P1OUT = 0x01;
		for(int i = 0; i < 0xFFFF; i++);
		P1OUT = 0x40;
		for(int i = 0; i < 0x0FFFF; i++);
	}

	return 0;
}
