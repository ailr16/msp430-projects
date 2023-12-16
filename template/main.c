#include <msp430g2553.h>

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = 0x41;

	while(1)
	{
		P1OUT = 0x01;
		for(int i = 0; i < 0xFFFF; i++);
		P1OUT = 0x40;
		for(int i = 0; i < 0x0FFFF; i++);
	}

	return 0;
}
