# AD-omvandling med ATmega328P i C
Implementering av AD-omvandling och PWM-generering med mikrodator ATmega328P.

Ljusstyrkan på en lysdiod ansluten till pin 8 (PORTB0) styrs vid en potentiometer ansluten till
analog pin A0 (PORTC0), vars insignal AD-omvandlas för att beräkna on- och off-tid för PWM-generering,
dvs. hur länge av given periodtid på 10 ms som lysdioden ska vara tänd eller släckt.

Filen "header.h" innehåller diverse definitioner och deklarationer för implementering av det inbyggda systemet.

Filen "setup.c" innehåller fördröjningsrutiner.

Filen "adc.c" innehåller funktioner för AD-omvandling samt PWM-generering.

I filen "main.c" initierar systemet vid start. Därefter läses insignalen från potentiometern av
och används för att beräkna aktuell on- och off-tid för PWM-generering. 
Ljusstyrkan styrs sedan via PWM-generering med beräknade värden.

Se video tutorial här: https://youtu.be/pPupXPCTCLc