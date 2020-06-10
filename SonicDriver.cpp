 
 /*  Sonic_Driver.c
 *	1.0, 2020-05-17
 *	
 *		controls the sonic sensors
 *		the following functions are implemented:
 *			- void SonicPinInit():
 *				initializes the sonic sensor pins
 *			- int ReadSonic(unsigned char channel):
 *				reads the sonic sensor value:
 *					FRONT_SONIC (= 0) / REAR_SONIC (= 1)
 *				returns the distance value, range: 0-400 (in cm)
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Alexander Laichinger
 */

/****************************** include files ******************************************/
#include 	<Arduino.h>
#include	"GlobalDefinitions.h"
#include	"SonicDriver.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/


unsigned long startMicros;

/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/

void SonicPinInit(void); 
int ReadSonic(unsigned char channel);


/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/



/*
 * void SonicPinInit(void)
 *
 * initialize the pins for the sonic sensor
 */
void SonicPinInit(void) {
	pinMode( FRONT_SONIC_TRIGGER_PIN, OUTPUT );
	pinMode( FRONT_SONIC_ECHO_PIN, INPUT );
	pinMode( REAR_SONIC_TRIGGER_PIN	, OUTPUT );
	pinMode( REAR_SONIC_ECHO_PIN, INPUT );
}


/*
 * unsigned int ReadSonic(unsigned char channel)
 *
 * param: select front or rear sonic (1 / 0)
 *
 * return: the newest distance value from the sensor (in cm)
 *		   return -1 if an error occurs
 */
int ReadSonic(unsigned char channel) {

	switch(channel) {
    case FRONT_SONIC:
    
      // send request to front sonic sensor
      digitalWrite( FRONT_SONIC_TRIGGER_PIN , LOW ); 
      delayMicroseconds( 2 );
      digitalWrite( FRONT_SONIC_TRIGGER_PIN , HIGH );
      delayMicroseconds( 10 );
      digitalWrite( FRONT_SONIC_TRIGGER_PIN  , LOW );
      startMicros = micros(); 
      
      while(digitalRead(FRONT_SONIC_ECHO_PIN) == LOW) {
        if(micros()-startMicros > MAX_SONIC_VALUE) {
          // return max value
          //return MAX_SONIC_VALUE / (SONIC_PRESCALER*2);
          return MAX_SONIC_VALUE;
        }
      }
     
      startMicros = micros();  
      while(digitalRead(FRONT_SONIC_ECHO_PIN) == HIGH) {
        if(micros()-startMicros > MAX_SONIC_VALUE) {
          //return max value
          return MAX_SONIC_VALUE / (SONIC_PRESCALER*2);
        }
      }
      
      return (micros()-startMicros) / (SONIC_PRESCALER*2);
    break;
    
    case REAR_SONIC:

      // send request to front sonic sensor
      /*
       * code is doing the same as below and works on real Arduino, but not in SIMULIDE)
      PORTD &= ~(1 << REAR_SONIC_TRIGGER_PIN);
      delayMicroseconds( REAR_SONIC_TRIGGER_PIN );
      PORTD |= (1 << REAR_SONIC_TRIGGER_PIN);
      delayMicroseconds( 10 );
      PORTD &= ~(1 << REAR_SONIC_TRIGGER_PIN);
      */
      
      digitalWrite( REAR_SONIC_TRIGGER_PIN, LOW ); 
      delayMicroseconds( 2 );
      digitalWrite( REAR_SONIC_TRIGGER_PIN, HIGH );
      delayMicroseconds( 10 );
      digitalWrite( REAR_SONIC_TRIGGER_PIN, LOW );

      startMicros = micros(); 
      while(digitalRead(REAR_SONIC_ECHO_PIN  ) == LOW) {     
        if(micros()-startMicros > MAX_SONIC_VALUE) {
          
          // return max value
          return MAX_SONIC_VALUE / (SONIC_PRESCALER*2);
        }
      }
      
      startMicros = micros();  
      while(digitalRead(REAR_SONIC_ECHO_PIN  ) == HIGH) {
        if(micros()-startMicros > MAX_SONIC_VALUE) {
          // return max value
          return MAX_SONIC_VALUE / (SONIC_PRESCALER*2);;
        }
      }
      return (micros()-startMicros) / (SONIC_PRESCALER*2);
    break;
    
    default:
      return -1;
    break;
  }
  
  return -1;
}



/***************************** end of implementation **********************************/
