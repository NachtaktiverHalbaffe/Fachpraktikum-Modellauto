/*  Akkuanzeige.h
*   1.0 2020-06-23
*
*   (C) IAS, Universität Stuttgart
*   Author: Ilya Kozlov
*/

#ifndef AKKUANZEIGE_H_
#define AKKUANZEIGE_H_


#include <avr/io.h>
#include "GlobalDefinitions.h"


/**************************************** Definitions **********************************************************************/
 /* The funktion calculets a battery value
 gives out a value between 0 and 9*/
int akkuwert(int spannung);

/* The funktion calculets a battery value and rounds it off to a single digit. */
void anzeige7seg( int akkuwert);

/**************************************** Methods **************************************************************************/


#endif /* AKKUANZEIGE_H_ */