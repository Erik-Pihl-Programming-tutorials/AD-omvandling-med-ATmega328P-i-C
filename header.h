/********************************************************************************
* header.h: Inneh�ller diverse definitioner och deklarationer f�r implementering
*           av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens (beh�vs f�r f�rdr�jningsrutiner): */
#define F_CPU 16000000UL /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inneh�ller information om I/O-register s�som PORTB och DDRB. */
#include <util/delay.h> /* Inneh�ller f�rdr�jningsrutiner s�som _delay_ms. */

/* Makrodefinitioner: */
#define LED1 PORTB0 /* Lysdiod 1 ansluten till pin 8 (PORTB0). */
#define POT1 PORTC0 /* Potentiometer 1 ansluten till analog pin A0 (PORTC0). */

#define LED1_ON PORTB |= (1 << LED1)   /* T�nder lysdiod 1. */
#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */

/********************************************************************************
* delay_ms: Genererar f�rdr�jning m�tt i millisekunder.
*
*           - delay_time_ms: F�rdr�jningstiden m�tt i millisekunder.
********************************************************************************/
#define delay_ms(delay_time_ms) ({ \
   for (uint16_t i = 0; i < delay_time_ms; ++i) { \
      _delay_ms(1); \
   } \
})

/* Enumerationer: */
typedef enum { false, true } bool; /* Realiserar datatypen bool. */
 
/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);

/********************************************************************************
* adc_read: L�ser av angiven analog pin och returnerar motsvarande digitala
*           v�rde mellan 0 - 1023.
*           
*           - pin: Analog pin A0 - A5 som ska l�sas av.
********************************************************************************/
uint16_t adc_read(const uint8_t pin);

/********************************************************************************
* adc_get_pwm_values: L�ser av angiven analog pin och ber�knar on- och off-tid
*                     utefter angiven periodtid. Ber�knar on- och off-tid lagras
*                     p� angivna adresser.
*
*                     - pin          : Analog pin A0 - A5 som ska l�sas av.
*                     - pwm_period_ms: Periodtid f�r PWM-generering i ms.
*                     - pwm_on_ms    : Lagringsplats f�r ber�knad on-tid i ms.
*                     - pwm_off_ms   : Lagringsplats f�r ber�knad on-tid i ms.
********************************************************************************/
void adc_get_pwm_values(const uint8_t pin,
                        const uint8_t pwm_period_ms,
                        uint8_t* pwm_on_ms,
                        uint8_t* pwm_off_ms);

#endif /* HEADER_H_ */