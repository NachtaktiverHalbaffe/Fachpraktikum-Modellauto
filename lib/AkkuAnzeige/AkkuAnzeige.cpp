/* AkkuAnzeige.cpp
*  1.0 2020-06-23
* 
*  (C) 2020 IAS, Universität Stuttgart
*  Author: Ilya Kozlov
*/

/******************************************* include files ********************************************************************/

#include <avr/io.h>
#include "GlobalDefinitions.h"

/******************************************* end of include *******************************************************************/


/******************************************* declaration of variables *********************************************************/
 double spannung;




/******************************************* end of variables *****************************************************************/


/******************************************* declaration of functions *********************************************************/
int akkuwert(int spannung);
void anzeige7seg( int akkuwert);



/******************************************* end of functions *****************************************************************/


/******************************************* implementation of functions ******************************************************/
int akkuwert(double spannung){
 if(spannung < 1,5){
     if(spannung >1,31) {
         Serial.println("9");
        return 9; 
     }
     else if((spannung >1,3) {
         Serial.println("8");
        return 8; 
     }
      else if((spannung >1,29) {
          Serial.println("7");
        return 7; 
     }
    else if((spannung >1,275) {
        Serial.println("6");
        return 6; 
     }
    else if((spannung >1,26) {
        Serial.println("5");
        return 5; 
     }
    else if((spannung >1,24) {
        Serial.println("4");
         akkuwert =4;
        return 4; 
     }
    else if((spannung >1,23) {
        Serial.println("4");
         akkuwert =3;
        return 3; 
     }
    else if((spannung >1,21) {
        Serial.println("3");
         akkuwert =2;
        return 2; 
     }
      else if((spannung >1,18) {
          Serial.println("1");
         akkuwert =1;
        return 1; 
     }
      else if((spannung <1,18) {
          Serial.println("0");
         akkuwert =0;
        return 0; 
     }
 
 }
}
void anzeige7seg( int akkuwert){
    
}




/******************************************* end of implementation ************************************************************/
