#include "PWM.h"

void setPwmPin( unsigned char port, unsigned char pin, unsigned char function )
{
    P1SEL  = 0x00;
    P1SEL2 = 0x00;
}