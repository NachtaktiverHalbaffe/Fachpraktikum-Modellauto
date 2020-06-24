/* Fahrlichtsteuerung.c
*  1.0 2020-06-22
* 
*  (C) 2020 IAS, Universität Stuttgart
*  Author: Marei Schmidt
*/

/******************************************* include files ********************************************************************/

#include "RemoteControlDriver.h"
#include "GlobalDefinitions.h"
#include "Fahrlichtsteuerung.h"
//#include "KollisionsUeberwachung.h"

/******************************************* end of include *******************************************************************/


/******************************************* declaration of variables *********************************************************/

#define DRIVINGLIGHT_PIN    7
#define BRAKELIGHTS_PIN     4
#define BACKWARDSLIGHT_PIN  5
#define BRIGHTNESS_PIN      3

// KollisionsUeberachung.getVelocity()  
// Geschwindigkeitsfunktion von Felix, positiver Wert == vorwärts, negativer Wert == rückwärts

/******************************************* end of variables *****************************************************************/


/******************************************* declaration of functions *********************************************************/

void lightControlInit (void){
    DDRD |= (1 << DRIVINGLIGHT_PIN);
    DDRD |= (1 << BRAKELIGHTS_PIN);
    DDRD |= (1 << BACKWARDSLIGHT_PIN);
    DDRD |= (1 << BRIGHTNESS_PIN);
}

void drivinglights (bool isDark, bool inAutomaticOperation, bool lightManualOn){
    if((isDark && inAutomaticOperation) || (~inAutomaticOperation && lightManualOn)){
        PORTD |= (1 << DRIVINGLIGHT_PIN);
    } else {
        PORTD |= (1 << DRIVINGLIGHT_PIN);
    }
}


void brakelights (bool isBraking){
    if (isBraking){
        PORTB |= (1 << BRAKELIGHTS_PIN);
    } else {
        PORTB &= ~(1 << BRAKELIGHTS_PIN);
    }
}


void backwardslight (bool isDrivingBackwards){
    if (isDrivingBackwards){
        PORTB |= (1 << BACKWARDSLIGHT_PIN);
    } else {
        PORTB &= ~(1 << BACKWARDSLIGHT_PIN);
    }
}


/******************************************* end of functions *****************************************************************/


/******************************************* implementation of functions ******************************************************/




/******************************************* end of implementation ************************************************************/