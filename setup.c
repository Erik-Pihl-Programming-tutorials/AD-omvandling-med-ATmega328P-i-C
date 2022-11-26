/********************************************************************************
* setup.c: Innehåller fördröjningsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
*
*        1. Lysdioden sätts till utport genom skrivning till datariktnings-
*           register DDRB. Eftersom potentiometerns insignal är analog så ska
*           kunna flyta mellan 0 - 5 V. Därmed ettställer vi inte den interna
*           pullup-resistorn såsom görs för tryckknappar, då insignalen då
*           alltid hade blivit 0 - 1.
*
*        2. Vi initierar AD-omvandlarens analoga kretsar genom att köra en
*           testomvandling. Eftersom resultatet i detta fall inte är av värde
*           så typomvandlas returtypen till void.
********************************************************************************/
void setup(void)
{
   DDRB = (1 << LED1);
   (void)adc_read(POT1);
   return;
}