#include "GeneralFunctions.h"

unsigned int GetBit( unsigned int reg, unsigned char bit )
{
    unsigned int returnValue;

    returnValue = ((reg >> bit) & 0x01);

    return returnValue;
}

void SetBit( volatile unsigned char *reg, unsigned char bit )
{
    *reg |= (0x01 << bit);
}

void ClearBit( volatile unsigned char *reg, unsigned char bit )
{
    *reg &= ~(0x01 << bit);
}

void SetBitMask( volatile unsigned char *reg, unsigned char mask )
{
    *reg |= mask;
}

void ClearBitMask( volatile unsigned char *reg, unsigned char mask )
{
    *reg &= ~mask;
}