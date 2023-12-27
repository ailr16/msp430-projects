#ifndef GENERAL_FUNCTIONS
#define GENERAL_FUNCTIONS

#include <msp430g2553.h>

unsigned int GetBit( unsigned int reg, unsigned char bit );
void SetBit( volatile unsigned char *reg, unsigned char bit );
void ClearBit( volatile unsigned char *reg, unsigned char bit );
void SetBitMask( volatile unsigned char *reg, unsigned char mask );
void ClearBitMask( volatile unsigned char *reg, unsigned char mask );

#endif