/********************************************************************************
* main.c: Demonstration av AD-omvandling och PWM-generering f�r att kontrollera
*         ljusstyrkan p� en lysdiod. En potentiometer ansluten till analog pin
*         A0 (PORTC0) kontrollerar ljusstyrkan p� en lysdiod ansluten till pin
*         8 (PORTB0).
*
*         Ljusstyrkan kontrolleras genom att den analoga insignalen fr�n
*         potentiometern AD-omvandlas och anv�nds f�r att ber�kna duty cycle,
*         dvs. andelen av en period som lysdioden ska vara t�nd. Som exempel
*         f�r en periodtid p� 10 ms, s� inneb�r en duty cycle p� 60 % att
*         lysdioden ska vara t�nd 60 % av tiden, dvs. 6 ms, och sl�ckt 
*         resterande periodtid, vilket �r 4 ms. I praktiken blinkas lysdioden,
*         d�r den �r t�nd 6 ms och sl�ckt 4 ms. Eftersom blikningarna �r s�
*         s� korta s� ses inte blinkningarna, i st�llet upplever vi 60 %
*         ljusstyrka, d� medeleffekten blir 60 % av max.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar mikrodatorn vid start. Potentiometern l�ses sedan av 
*       kontinuerligt och on- samt off-tid ber�knas utefter en periodtid p� 
*       10 ms. D�refter h�lls lysdioden t�nd under on-tiden och sl�ckt under
*       off-tiden.
********************************************************************************/
int main(void)
{
   uint8_t pwm_on_ms;
   uint8_t pwm_off_ms;

   setup();

   while (1)
   {
      adc_get_pwm_values(POT1, 10, &pwm_on_ms, &pwm_off_ms);

      LED1_ON;
      delay_ms(pwm_on_ms);

      LED1_OFF;
      delay_ms(pwm_off_ms);
   }
   
   return 0;   
}

