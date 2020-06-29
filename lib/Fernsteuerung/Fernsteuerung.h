/*  Fernsteuerung.h
*   1.0 2020-06-22
*
*   the header for the remote control
*
*   (C) IAS, Universität Stuttgart
*   Author: Marei Schmidt
*/

#ifndef FERNSTEUERUNG_H_
#define FERNSTEUERUNG_H_


#include "RemoteControlDriver.h"
#include "GlobalDefinitions.h"


/**************************************** Definitions **********************************************************************/


/**************************************** Methods **************************************************************************/

float getAcceleration (void);

float getSteer (void);

bool getHonking (void);

bool getLightManualOn (void);

bool getManualOperation (void);



#endif /* FERNSTEUERUNG_H_ */