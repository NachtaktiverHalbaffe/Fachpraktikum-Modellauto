/* Fernsteuerung.c
*  1.0 2020-06-22
* 
*  (C) 2020 IAS, Universität Stuttgart
*  Author: Marei Schmidt
*/

/******************************************* include files ********************************************************************/

#include "RemoteControlDriver.h"
#include "GlobalDefinitions.h"

/******************************************* end of include *******************************************************************/


/******************************************* declaration of variables *********************************************************/




/******************************************* end of variables *****************************************************************/


/******************************************* declaration of functions *********************************************************/




/******************************************* end of functions *****************************************************************/


/******************************************* implementation of functions ******************************************************/

bool getBraking(void){
    int velocityHelper = 0;
    velocityHelper = KollisionsUeberachung.getVelocity();
    if(velocityHelper >= 0 && GetRemoteSignal(DRIVING_DIRECTION)){ // Driving Direction auswerten


    }
    
}


/******************************************* end of implementation ************************************************************/



