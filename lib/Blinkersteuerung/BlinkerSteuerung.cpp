/*  BlinkerSteuerung.c
 *	1.0, 2020-05-17
 *	
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Felix Brugger
 */

/****************************** include files ******************************************/
#include  <avr/io.h>
#include  "GlobalDefinitions.h"
#include "BlinkerSteuerung.h"


/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/
float mTB=0; // Helper for buffering Timer if Timer is already running and the timervalue has to be stored
bool isBlinking =false; //Helper to see if it already blinks
const float BLINK_TIME = 0.7;
/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void BlinkerSteuerungInit(void){
    DDRB |= (1 << BLINKER_RECHTS) | (1<< BLINKER_LINKS);
}

void blink(void){
    if(GetSteeringDirection()<2) {
        // Checking if timer is already running
            //checking if a time is already stored in helper
            if(mTB==0){
                Serial.println("No Buffered Time stored");
                mTB = getTime();
                setBlinkingDirection();
                isBlinking=true;
            } else {
                //check if blinking time is exceeded
                Serial.println(getTime() - mTB);
                if(getTime() - mTB > BLINK_TIME){
                    //check if its blinking or off
                    if(isBlinking){
                        //is Blinking, turning off
                        turnBlinkerOff();
                        mTB= getTime();
                    } else {
                        //isnt blinking, turning blink on
                        setBlinkingDirection();
                        mTB= getTime();
                    }
                }
            }
    } else{
        //car isnt steering, turning evrything off
         turnBlinkerOff();
         isBlinking=false;    
    }
}

void setBlinkingDirection(void){
    isBlinking = true;
    //set Blink-LEDs on according to steering direction 
    if( GetSteeringDirection() == 0){
    PORTB |= (1<<BLINKER_LINKS);
    PORTB &= ~(1 << BLINKER_RECHTS);
    } else{
        PORTB |= (1<<BLINKER_RECHTS);
        PORTB &= ~(1 << BLINKER_LINKS);
    } 
}

void turnBlinkerOff(void){
    //turn all blinker off
    PORTB &= ~(1 << BLINKER_RECHTS);
    PORTB &= ~(1 << BLINKER_LINKS);
    isBlinking=false;
}

/***************************** end of implementation **********************************/
