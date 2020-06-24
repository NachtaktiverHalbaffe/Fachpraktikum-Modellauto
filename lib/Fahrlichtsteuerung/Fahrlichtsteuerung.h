/*  Fahrlichtsteuerung.h
*   1.0 2020-06-22
*   1.1 2020-06-24
*
*   the header for the driving light control system
*
*   (C) IAS, Universität Stuttgart
*   Author: Marei Schmidt
*/

#ifndef FAHRLICHTSTEUERUNG_H_
#define FAHRLICHTSTEUERUNG_H_


#include "GlobalDefinitions.h"


/**************************************** Definitions **********************************************************************/


/**************************************** Methods **************************************************************************/

void lightControlInit (void);

void backwardslight (bool isDrivingBackwards);

void drivinglights (bool isDark, bool inAutomaticOperation, bool lightManualOn);

void brakelights (bool isBraking);



#endif /* FAHRLICHTSTEUERUNG_H_ */