#ifndef DIO_H
#define DIO_H

#include <msp430g2553.h>

#define DIO_PORT_1      1
#define DIO_PORT_2      2

#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7

void setInputPin( unsigned char port, unsigned char pin );
void setOutputPin( unsigned char port, unsigned char pin );


#endif