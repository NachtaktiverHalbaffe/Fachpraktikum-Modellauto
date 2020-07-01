/* AkkuAnzeige.cpp
*  1.0 2020-06-23
* 
*  (C) 2020 IAS, Universität Stuttgart
*  Author: Ilya Kozlov
*/

/******************************************* include files ********************************************************************/
#include <avr/io.h>
#include "GlobalDefinitions.h"
#include "AkkuAnzeige.h"
/******************************************* end of include *******************************************************************/

/******************************************* declaration of variables *********************************************************/
#define DDRD  =  0B11111111     //PD7 digital output
#define   VOLTAGE_INPUT 0

void AkkuAnzeigeInit (void){
    DDRD  =  0B11111111;
    DDRC |= (0 << VOLTAGE_INPUT);
 int spannung=0;
 int nBaterien= 4 * (1023 /5); // number of Battery cells and variable to adjust spannung in a value between 0 and 1023

}
/******************************************* end of variables *****************************************************************/

/******************************************* implementation of functions ******************************************************/
int akkuwert(void){
    spannung = analogRead(DDRC0);// get a value between 0 and 5V and assign it to a numerical value between 0 and 1023
 if(spannung < int(1.5*nBaterien)){
    // The thresholds of a "spannung" value are approximated by the Date Sheet of a "Rechargeable Cylindrical cell Nickel Metal Hydride" battery. 
     if(spannung >int(1.31*nBaterien)) {
         Serial.println("9");
        return 9; 
     }
     else if((spannung > int(1.3*nBaterien)) {
         Serial.println("8");
        return 8; 
     }
    else if((spannung >int(1.29*nBaterien)) {
          Serial.println("7");
        return 7; 
     }
    else if((spannung > int(1.275*nBaterien)) {
        Serial.println("6");
        return 6; 
     }
    else if((spannung > int(1.26*nBaterien)) {
        Serial.println("5");
        return 5; 
     }
    else if((spannung >int(1.24*nBaterien)) {
        Serial.println("4");
         akkuwert =4;
        return 4; 
     }
    else if((spannung > int(1.23*nBaterien)) {
        Serial.println("4");
         akkuwert =3;
        return 3; 
     }
    else if((spannung >int(1.21*nBaterien)) {
        Serial.println("3");
         akkuwert =2;
        return 2; 
     }
    else if((spannung >int(1.18*nBaterien)) {
          Serial.println("1");
         akkuwert =1;
        return 1; 
     }
    else if((spannung <int(1.18*nBaterien)) {
          Serial.println("0");
         akkuwert =0;
        return 0; 
     }
 }
 else{
     Serial.println("Voltage to high");
     return -1:
 }
}

void anzeige7seg( int akkuwert){
    /* The funktion assigns a number between 0 and 9 an affiliated 7 segment port.
    */
   DDRD= {0B00000000};
    if( akkuwert== 9){
        PORTD= {0B11110110};
        //no bit operation are used because most of the bits have to be changed
    }
    if( akkuwert== 8){
        PORTD= {0B11111110};
    }
    if( akkuwert== 7){
        PORTD= {0B11100000};
    }
    if( akkuwert== 6){
        PORTD= {0B10111110};
    }
    if( akkuwert== 5){
        PORTD= {0B10110110};
    }
    if( akkuwert== 4){
        PORTD= {0B01100110};
    }
    if( akkuwert== 3){
        PORTD= {0B11110010};
    }
    if( akkuwert== 2){
        PORTD= {0B11011010};
    }
    if( akkuwert== 1){
        PORTD= {0B01100000};
    }
    if( akkuwert== 0){
        PORTD= {0B11111100};
    }
}
/******************************************* end of implementation ************************************************************/
