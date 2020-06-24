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
int akkuwert(int spannung);
void anzeige7seg( int akkuwert);

/**************************************** Methods **************************************************************************/


#endif /* AKKUANZEIGE_H_ */