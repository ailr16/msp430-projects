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