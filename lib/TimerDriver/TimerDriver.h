/*  TimerDriver.h
 *	1.0, 2020-06-23
 *	
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */ 


#ifndef TIMERDRIVER_H_
#define TIMERDRIVER_H_


#include <avr/io.h>
#include <avr/interrupt.h>
#include "GlobalDefinitions.h"


/********************************* Definitions ********************************/


/*********************************** Methods **********************************/

/* Component management */

/*
 * void startTimer(void)
 *
 * initializing the timer und starting it
 */
void startTimer(void);

/** Public **/


/*
 * float getTime(void)
 *
 * return: current time of timer 2
 */
long getTime(void);


/** Private **/

/*
 * void ISR(TIMER2_COMPA_vect)
 *
 * function to be executed on timer interrupt
 */
void ISR(TIMER2_COMPA_vect);


#endif /* TIMERDRIVER_H_ */