/*  TimerDriver.c
 *	1.0, 2020-06-23
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"


/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
long time=0;

/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void startTimer(void){
    cli(); // stop Interrupts

    // All declarations ar for Timer 2
    TCCR2A = 0;  //Resetting Timer/Counter Control Register A 
    TCCR2B = 0;  //Resetting Timer/Counter Control Register B
    TCNT2 = 0; //Timercount 
    OCR2A =155; // Output Compare Register A
    OCR2B =0; // Output Compare Register B

    // set prescaler
    TCCR2B |= (1<<CS22) | (1<<CS20);
    //turn on CTC mode
    TCCR2A |= (1 << WGM12)
    // enable timer compare interrupt
    TIMSK2 |= (1 << OCIE2A);
    // start serial connection for debugging
    Serial.begin(9600);

    sei();// allow interrupts
}

long getTime(void){ 
   return time;
}

ISR(TIMER2_COMPA_vect) {
  serial.println(time);
  time= time+0.1;
  serial.println(time);
}


/***************************** end of implementation **********************************/
