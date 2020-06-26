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

#define DDRD
 /* The funktion calculets a battery value and rounds it off to a single digit. 
 * 
 * params: voltage of the accumulator
 * 
 * return: int value between 0 and 9
 */
int akkuwert(int spannung);


/* The funktion assigns a number between 0 and 9 to an affiliated 7 segment port.
*    
* params: int value between 0 and 9
*
* return: void
*/
void anzeige7seg( int akkuwert){
    DDRD= {0B 0     0	0 	0 	0 	0 	0  0}
}

/**************************************** Methods **************************************************************************/


#endif /* AKKUANZEIGE_H_ */