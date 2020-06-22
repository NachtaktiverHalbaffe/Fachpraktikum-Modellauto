/*  Fahrlichtsteuerung.h
*   1.0 2020-06-22
*
*   the header for the driving light control system
*
*   (C) IAS, Universität Stuttgart
*   Author: Marei Schmidt
*/

#ifndef FAHRLICHTSTEUERUNG_H_
#define FAHRLICHTSTEUERUNG_H_


#include <avr/io.h>
#include "GlobalDefinitions.h"


/**************************************** Definitions **********************************************************************/


/**************************************** Methods **************************************************************************/

void backwardslight (bool isDrivingBackwards);

void drivinglights (bool isDark, bool inAutomaticOperation, bool lightManualOn);

void brakelights (bool isBraking);



#endif /* FARLICHTSTEUERUNG_H_ */