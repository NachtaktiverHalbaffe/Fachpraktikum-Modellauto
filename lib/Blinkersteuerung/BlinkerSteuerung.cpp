/*  BlinkerSteuerung.c
 *	1.0, 2020-05-17
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"


/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
int mT=0; // Helper for buffering Timer if Timer is already running and the timervalue has to be stored
bool isBlinking =false; //Helper to see if it already blinks
/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void blink(void){
    if(RemoteDriver.getSteeringDirection()<2){
        // Checking if timer is already running
        if(TimerDriver.getTime()==0){
            //timer not running, starting timer and setting blink
            TimerDriver.startTimer();
            setBlinkingDirection();
        } else{
            //checking if a time is already stored in helper
            if(mT==0){
                mT = TimerDriver.getTime();
                setBlinkingDirection();
            } else {
                //check if blinking time is exceeded
                if(long delta_time = TimerDriver.getTime() - mT > BLINK_TIME){
                    //check if its blinking or off
                    if(isBlinking){
                        //is Blinking, turning off
                        turnBlinkerOff();
                        mT= TimerDriver.getTime()
                    } else {
                        //isnt blinking, turning blink on
                        setBlinkingDirection();
                        mT= TimerDriver.getTime()
                    }
                }
            }
        }

    } else{
        if(isBlinking){
         turnBlinkerOff();
        }
    }
}

void setBlinkingDirection(void){
if(RemoteDriver.getSteeringDirection()==0){
    PORTB |= (1<<BLINKER_LINKS);
} else PORTB |= (1<<BLINKER_RECHTS);
}

void turnBlinkerOff(void){
    PORTB &= ~(1 << BLINKER_RECHTS);
    PORTB &= ~(1 << BLINKER_LINKS);
}

/***************************** end of implementation **********************************/
