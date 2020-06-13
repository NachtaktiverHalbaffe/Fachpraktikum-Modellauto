/*  SonicDriver.h
 *	1.0, 2020-05-17
 *	
 *		the header for the sonic driver
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */


#ifndef SONICDRIVER_H_
#define SONICDRIVER_H_

#include <Arduino.h> 
#include "GlobalDefinitions.h"

/*
not needed because digitalwrite is used
#ifndef F_CPU
#define	F_CPU	16000000UL
#endif
#include	"util/delay.h"
#include	"avr/io.h"
#include	"stdio.h"
#include	"avr/interrupt.h"
#include	"util/delay.h"
*/
/********************************* Definitions ********************************/

#define MAX_SONIC_VALUE			30000
// dont go over int range

#define SONIC_PRESCALER			   29


/*********************************** Methods **********************************/


/* Component management */
void SonicPinInit(void);

/** Public **/
int ReadSonic(unsigned char channel);

/** Private **/




#endif /* SONICDRIVER_H_ */