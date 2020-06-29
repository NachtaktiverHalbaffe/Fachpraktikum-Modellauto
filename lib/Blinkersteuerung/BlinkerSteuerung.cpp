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
int mTB=0; // Helper for buffering Timer if Timer is already running and the timervalue has to be stored
bool isBlinking =false; //Helper to see if it already blinks
/****************************** end of variables **************************************/



/****************************** implementation of functions ***************************/
void BlinkerSteuerungInit(void){
    DDRB |= (1 << BLINKER_RECHTS) | (1<< BLINKER_LINKS);
}

void blink(void){
    if(GetSteeringDirection()<2) {
        // Checking if timer is already running
        Serial.println("Blinking on");
        Serial.println(getTime());
        if(getTime()==0){
            //timer not running, starting timer and setting blink
            Serial.println("Timer started");
            startTimer();
            setBlinkingDirection();
        } else{
            //checking if a time is already stored in helper
            if(mTB==0){
                Serial.println("No Buffered Time stored");
                mTB = getTime();
                setBlinkingDirection();
            } else {
                //check if blinking time is exceeded
                if(getTime() - mTB > BLINK_TIME){
                    //check if its blinking or off
                    if(isBlinking){
                        //is Blinking, turning off
                        turnBlinkerOff();
                        mTB= getTime();
                        Serial.println("Blink");
                        Serial.println(mTB);
                    } else {
                        //isnt blinking, turning blink on
                        setBlinkingDirection();
                        Serial.println("Blink");
                        mTB= getTime();
                        Serial.println(mTB);
                    }
                }
            }
        }

    } else{
        
        Serial.println("Blinking off");
         turnBlinkerOff();
         isBlinking=false;
        
    }
}

void setBlinkingDirection(void){
if( GetSteeringDirection() == 0){
    PORTB |= (1<<BLINKER_LINKS);
    } else PORTB |= (1<<BLINKER_RECHTS);
}

void turnBlinkerOff(void){
    PORTB &= ~(1 << BLINKER_RECHTS);
    PORTB &= ~(1 << BLINKER_LINKS);
}

/***************************** end of implementation **********************************/
