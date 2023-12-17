#ifndef DIO_H
#define DIO_H

#include <msp430g2553.h>

typedef struct _Dio_ConfigType{
    unsigned char d;
} Dio_ConfigType;

void setInputPin( unsigned char port, unsigned char pin, unsigned char function );

#endif