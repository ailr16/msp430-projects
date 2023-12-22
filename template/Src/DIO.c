#include "DIO.h"
#include "GeneralFunctions.h"

void setInputPin( unsigned char port, unsigned char pin )
{
    switch( port )
    {
        case DIO_PORT_1:
            ClearBit( &P1SEL, pin );
            ClearBit( &P1SEL2, pin );
            ClearBit( &P1DIR, pin );
            break;

        case DIO_PORT_2:
            ClearBit( &P2SEL, pin );
            ClearBit( &P2SEL2, pin );
            ClearBit( &P2DIR, pin );
            break;
        
        default:
            break;
    }
}

void setOutputPin( unsigned char port, unsigned char pin )
{
    switch( port )
    {
        case DIO_PORT_1:
            ClearBit( &P1SEL, pin );
            ClearBit( &P1SEL2, pin );
            SetBit( &P1DIR, pin );
            break;

        case DIO_PORT_2:
            ClearBit( &P2SEL, pin );
            ClearBit( &P2SEL2, pin );
            SetBit( &P2DIR, pin );
            break;
        
        default:
            break;
    }
}

unsigned char getPin( unsigned char port, unsigned char pin )
{
    unsigned char returnValue = DIO_PIN_UNDEFINED;

    switch( port )
    {
        case DIO_PORT_1:
            returnValue = GetBit( P1IN, pin );
            break;

        case DIO_PORT_2:
            returnValue = GetBit( P2IN, pin );
            break;
        
        default:
            break;
    }

    return returnValue;
}

void setPin( unsigned char port, unsigned char pin )
{
    switch( port )
    {
        case DIO_PORT_1:
            SetBit( &P1OUT, pin );
            break;

        case DIO_PORT_2:
            SetBit( &P2OUT, pin );
            break;
        
        default:
            break;
    }
}

void clearPin( unsigned char port, unsigned char pin )
{
    switch( port )
    {
        case DIO_PORT_1:
            ClearBit( &P1OUT, pin );
            break;

        case DIO_PORT_2:
            ClearBit( &P2OUT, pin );
            break;
        
        default:
            break;
    }
}