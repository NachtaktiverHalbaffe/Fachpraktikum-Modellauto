/* Fahrlichtsteuerung.c
*  1.0 2020-06-22
* 
*       controls the drivinglight, brakelight and backwardslight:
*       the following functions are implemented:
*           - lightControlInit()
*               initializes the light-pins and the brightness-pin
*           - drivinglight()
*               switches on the drivinglight
*           - brakelight()
*               switches on the braklight
*           - backwardslight()
*               switches on the backwardslight
*
*
*  (C) 2020 IAS, Universität Stuttgart
*  Author: Marei Schmidt
*/

/******************************************* include files ********************************************************************/

#include <avr/io.h>
#include "GlobalDefinitions.h"
#include "Fahrlichtsteuerung.h"
//#include "KollisionsUeberwachung.h"
//#include "RemoteControlDriver.h"

/******************************************* end of include *******************************************************************/


/******************************************* declaration of variables *********************************************************/

#define DRIVINGLIGHT_PIN    7       //PD7 digital output
#define BRAKELIGHTS_PIN     4       //PB4 digital output
#define BACKWARDSLIGHT_PIN  5       //PB5 digital output
#define BRIGHTNESS_PIN      3       //PC3 analog input

int brightness = 0;

/******************************************* end of variables *****************************************************************/


/******************************************* declaration of functions *********************************************************/
/******************************************* end of functions *****************************************************************/


/******************************************* implementation of functions ******************************************************/

//manages whether the port is input (0) or output (1)
void lightControlInit (void){
    DDRD |= (1 << DRIVINGLIGHT_PIN);
    DDRB |= (1 << BRAKELIGHTS_PIN); 
    DDRB |= (1 << BACKWARDSLIGHT_PIN);
    DDRC |= (0 << BRIGHTNESS_PIN);
}

void drivinglights (void){

    /* read brightness sensor
    *  OV -> 0
    *  5V -> 1023
    *  definded: darkness from 0V to 2,5V (from 0 to 511)
    */
    brightness = adc_read(BRIGHTNESS_PIN);

    //in automatic operation and it is dark (brightness < 511)
    if(GetLightSwitchStatus() == 1 && brightness < 511){
        PORTD |= (1 << DRIVINGLIGHT_PIN);
    }
    //in manual operation and light switch is on
    else if(GetLightSwitchStatus() == 2){
        PORTD |= (1 << DRIVINGLIGHT_PIN);
    }
    //in manual operation and light switch is off
    else {
        PORTD &= ~(1 << DRIVINGLIGHT_PIN);
    }
}


void brakelights (void){
    
    //driving forward -> braking
    if (getVelocity() > 0 && GetDrivingDirection() == 1){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("driving forward -> braking"); //passt nicht; fährt rückwärts gegen Wand
    } 
    //driving backwards -> braking
    else if(getVelocity() < 0 && GetDrivingDirection() == 0){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("driving backwards -> braking"); //passt nicht; fährt eigentlich vorwärts?
    }
    //driving forwards and collision -> braking
    else if(getVelocity() > 0 && collisioncontrol(false) == true){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("driving forwards and collision");
    }
    //driving backwards and collision -> braking
    else if(getVelocity() < 0 && collisioncontrol(true) == true){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("driving backwards and collision");
    }
    // collision
    else if(collisioncontrol(false) == true || collisioncontrol(true) == true){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("collision");
    }
    // standing
    else if((getVelocity() == 0 && GetDrivingDirection() == 2) || getVelocity() == 0){
        PORTB |= (1 << BRAKELIGHTS_PIN);
        Serial.println(" ");
        Serial.println("standing");
    }
    //brakelights off
    else {
        PORTB &= ~(1 << BRAKELIGHTS_PIN);
    }
}


void backwardslight (void){

    //driving backwards
    if(getVelocity() < 0 && GetDrivingDirection() == 1){
        PORTB |= (1 << BACKWARDSLIGHT_PIN);
    } 
    //backwardslights off
    else {
        PORTB &= ~(1 << BACKWARDSLIGHT_PIN);
    }
}

/*
* GetLightSwitchStatus():
*   0 == light off
*   1 == light automatic
*   2 == light on
*
* GetDrivingDirection():
*   0 == driving forward
*   1 == driving reverse
*   2 == driving stand
* 
* getVelocity():
*   >0 == driving forward
*   0  == stand
*   <0 == driving reverse
*
* collisioncontrol(bool isDrivingBackwards):
*   isDrivingBackwards: true -> driving reverse
*                       false -> driving vorwards
*   0 == no collision
*   1 == collision
*/

/******************************************* end of implementation ***********************************************************/