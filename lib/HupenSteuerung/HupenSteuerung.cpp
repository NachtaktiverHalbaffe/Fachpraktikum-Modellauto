/*  HupenSteuerung.c
 *	1.0, 2020-06-17
 *	    
 *
 *      controls the honk:
 *      the following functions are implemented:
 *          - HupenSteuerungInit():
 *              initialize the honk-pin
 *          - honk(doHonking)
 *              orders the Honk-Component to honk
 * 
 *		
 *
 *	(C) 2020 IAS, Universitaet Stuttgart
 *	Author: Rouven Rischert
 */

/****************************** include files ******************************************/

#include    <avr/io.h>
#include	"HupenSteuerung.h"

/****************************** end of include ****************************************/



/****************************** declaration of variables ******************************/

#define HONK_PIN                4

/****************************** end of variables **************************************/



/****************************** declaration of functions ******************************/
/****************************** end of functions **************************************/



/****************************** implementation of functions ***************************/

/*
 * void HupenSteuerungInit(void)
 * 
 * initialize the honk-pin
*/
void HupenSteuerungInit(void){
    DDRD |= (1 << HONK_PIN);
}


/*
 * void Honk(bool doHonking)
 * 
 * params: bool doHonking is 0 or 1:
 * 0 -> don't honk
 * 1 -> honk
 * 
 * works with GetRemoteSignal(Horn_Status) to get the right offer for honk/not honk
 */
void Honk(void){
    static bool doHonking;
    doHonking = GetRemoteSignal(HORN_STATUS);
    if (doHonking){
        PORTD |= (1 << HONK_PIN);
    }
    else{
        PORTD &= ~(1 << HONK_PIN);
    }
}
/***************************** end of implementation **********************************/
