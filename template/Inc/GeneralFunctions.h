#ifndef PWM
#define PWM_H

#include <msp430g2553.h>

unsigned int GetBit( unsigned int reg, unsigned char bit );
void SetBit( volatile unsigned char *reg, unsigned char bit );
void ClearBit( volatile unsigned char *reg, unsigned char bit );

#endif