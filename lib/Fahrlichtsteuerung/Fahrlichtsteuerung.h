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

#include <avr/io.h>
#include "GlobalDefinitions.h"
#include "RemoteControlDriver.h"
#include "KollisionsUeberwachung.h"

/**************************************** Definitions **********************************************************************/


/**************************************** Methods **************************************************************************/

void lightControlInit (void);

void drivinglights (void);

void brakelights (void);

void backwardslight (void);


#endif /* FAHRLICHTSTEUERUNG_H_ */