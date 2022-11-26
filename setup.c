/********************************************************************************
* setup.c: Inneh�ller f�rdr�jningsrutiner.
********************************************************************************/
#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
*
*        1. Lysdioden s�tts till utport genom skrivning till datariktnings-
*           register DDRB. Eftersom potentiometerns insignal �r analog s� ska
*           kunna flyta mellan 0 - 5 V. D�rmed ettst�ller vi inte den interna
*           pullup-resistorn s�som g�rs f�r tryckknappar, d� insignalen d�
*           alltid hade blivit 0 - 1.
*
*        2. Vi initierar AD-omvandlarens analoga kretsar genom att k�ra en
*           testomvandling. Eftersom resultatet i detta fall inte �r av v�rde
*           s� typomvandlas returtypen till void.
********************************************************************************/
void setup(void)
{
   DDRB = (1 << LED1);
   (void)adc_read(POT1);
   return;
}