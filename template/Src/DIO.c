#include "DIO.h"

void setInputPin( unsigned char port, unsigned char pin, unsigned char function )
{
    P1SEL  = 0x00;
    P1SEL2 = 0x00;
    P1DIR = 0x41;
}