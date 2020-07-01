/*  Akkuanzeige.h
*   1.0 2020-06-23
*
*   (C) IAS, Universität Stuttgart
*   Author: Ilya Kozlov
*/

#ifndef AKKUANZEIGE_H_
#define AKKUANZEIGE_H_

#include <avr/io.h>
#include <stdint.h>
#include "GlobalDefinitions.h"


/**************************************** Definitions **********************************************************************/
#define VOLTAGE_INPUT 0
#define VOLTAG_PIN 23


/* The funcion initializes the voltage input pin and the led output pins. 

*  params: void

*  return: void
*/
void AkkuAnzeigeInit (void);

 /* The funktion calculets a battery value and rounds it off to a single digit. 
 * 
 * params: voltage of the accumulator
 * 
 * return: int value between 0 and 9
 */
int akkuwert(void);


/* The funktion assigns a number between 0 and 9 to an affiliated 7 segment port.
*    
* params: int value between 0 and 9
*
* return: void
*/
void anzeige7seg( int akkuwert);

/* Reads the voltage value from an adc pin
*
* params: adc pin
*
* return: a int value between 0 and 1023 acording to voltages 0 to 5V
*
*/
uint16_t adc_read(uint8_t adcx);


/**************************************** Methods **************************************************************************/


#endif /* AKKUANZEIGE_H_ */