#ifndef DIO_H
#define DIO_H

#include <msp430g2553.h>

#define DIO_PORT_1           1u
#define DIO_PORT_2           2u

#define DIO_PIN0             0u
#define DIO_PIN1             1u
#define DIO_PIN2             2u
#define DIO_PIN3             3u
#define DIO_PIN4             4u
#define DIO_PIN5             5u
#define DIO_PIN6             6u
#define DIO_PIN7             7u

#define DIO_PIN_LOW          0u
#define DIO_PIN_HIGH         1u
#define DIO_PIN_UNDEFINED    3u

#define DIO_PIN_FUNCTION_IO               0u
#define DIO_PIN_FUNCTION_PERIPH_PRIMARY   1u
#define DIO_PIN_FUNCTION_PERIPH_SECONDARY 2u


void setPinFunction( unsigned char port, unsigned char pin, unsigned char function );
void setInputPin( unsigned char port, unsigned char pin );
void setOutputPin( unsigned char port, unsigned char pin );
unsigned char getPin( unsigned char port, unsigned char pin );
void setPin( unsigned char port, unsigned char pin );
void clearPin( unsigned char port, unsigned char pin );

#endif