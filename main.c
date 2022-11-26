/********************************************************************************
* main.c: Demonstration av AD-omvandling och PWM-generering för att kontrollera
*         ljusstyrkan på en lysdiod. En potentiometer ansluten till analog pin
*         A0 (PORTC0) kontrollerar ljusstyrkan på en lysdiod ansluten till pin
*         8 (PORTB0).
*
*         Ljusstyrkan kontrolleras genom att den analoga insignalen från
*         potentiometern AD-omvandlas och används för att beräkna duty cycle,
*         dvs. andelen av en period som lysdioden ska vara tänd. Som exempel
*         för en periodtid på 10 ms, så innebär en duty cycle på 60 % att
*         lysdioden ska vara tänd 60 % av tiden, dvs. 6 ms, och släckt 
*         resterande periodtid, vilket är 4 ms. I praktiken blinkas lysdioden,
*         där den är tänd 6 ms och släckt 4 ms. Eftersom blikningarna är så
*         så korta så ses inte blinkningarna, i stället upplever vi 60 %
*         ljusstyrka, då medeleffekten blir 60 % av max.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Initierar mikrodatorn vid start. Potentiometern läses sedan av 
*       kontinuerligt och on- samt off-tid beräknas utefter en periodtid på 
*       10 ms. Därefter hålls lysdioden tänd under on-tiden och släckt under
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

