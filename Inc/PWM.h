#ifndef PWM
#define PWM_H

#include <msp430g2553.h>

typedef struct _Pwm_ConfigType{
    unsigned char d;
} Pwm_ConfigType;

void setPwmPin( unsigned char port, unsigned char pin, unsigned char function );

#endif