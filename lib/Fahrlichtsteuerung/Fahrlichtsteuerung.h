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

/* The funcion initializes the light-pins and the brightness-pin. 
*  params: void
*  return: void
*/
void lightControlInit (void);

/* The funcion switches on the drivinglight.
*  params: void
*  return: void
*/
void drivinglights (void);

/* The funcion switches on the brakelights.
*  params: void
*  return: void
*/
void brakelights (void);

/* The funcion switches on the backwardslight.
*  params: void
*  return: void
*/
void backwardslight (void);


#endif /* FAHRLICHTSTEUERUNG_H_ */