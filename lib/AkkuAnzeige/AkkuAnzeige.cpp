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
 int spannung=0;
 int nBatterien= 4 * (1023 /5); // number of Battery cells and variable to adjust spannung in a value between 0 and 1023
/******************************************* end of variables *****************************************************************/

/******************************************* implementation of functions ******************************************************/
void AkkuAnzeigeInit (void){
    DDRD  =  0B11111111;
    DDRC |= (0 << VOLTAGE_INPUT);
    //Enable ADC
    ADCSRA |= (1 << ADEN);
}
uint16_t adc_read(uint8_t adcx) {
    //Setting up AD-Multiplexer
	ADMUX	&=	0xf0;
	ADMUX	|=	adcx;
    // Start conversion
	ADCSRA |= (1<<ADSC);
    //Wait until conversion is finished
	while ( (ADCSRA & _BV(ADSC)) );
	return ADC;
}

int akkuwert(void){
    spannung = adc_read(VOLTAGE_INPUT);// get a value between 0 and 5V and assign it to a numerical value between 0 and 1023
 if(spannung < (1.5*nBatterien)){
    // The thresholds of a "spannung" value are approximated by the Date Sheet of a "Rechargeable Cylindrical cell Nickel Metal Hydride" battery. 
     if(spannung > (1.31*nBatterien)) {
         //Serial.println("9");
        return 9; 
     }
     else if((spannung > (1.3*nBatterien))) {
         //Serial.println("8");
        return 8; 
     }
    else if((spannung >(1.29*nBatterien))) {
         // Serial.println("7");
        return 7; 
     }
    else if((spannung > (1.275*nBatterien))) {
        //Serial.println("6");
        return 6; 
     }
    else if((spannung > (1.26*nBatterien))) {
        //Serial.println("5");
        return 5; 
     }
    else if((spannung >(1.24*nBatterien)) ){
        //Serial.println("4");
        return 4; 
     }
    else if((spannung > (1.23*nBatterien)) ){
        //Serial.println("4");
        return 3; 
     }
    else if((spannung >(1.21*nBatterien)) ){
       //Serial.println("3");
        return 2; 
     }
    else if((spannung >(1.18*nBatterien))) {
         // Serial.println("1");
        return 1; 
     }
    else if((spannung <(1.18*nBatterien))) {
          //Serial.println("0");
        return 0; 
     }
 }
     //Serial.println("Error");
     return -1;
}

void anzeige7seg( int akkuwert){
    /* The funktion assigns a number between 0 and 9 an affiliated 7 segment port.
    */
    if( akkuwert== 9){
        PORTD=  0B11111011;
        //no bit operation are used because most of the bits have to be changed
    }
    if( akkuwert== 8){
        PORTD = 0B01111111;
    }
    if( akkuwert== 7){
        PORTD = 0B01110000;
    }
    if( akkuwert== 6){
        PORTD = 0B01011111;
    }
    if( akkuwert== 5){
        PORTD = 0B01011011;
    }
    if( akkuwert== 4){
        PORTD = 0B00110011;
    }
    if( akkuwert== 3){
        PORTD = 0B01111001;
    }
    if( akkuwert== 2){
        PORTD = 0B01101101;
    }
    if( akkuwert== 1){
        PORTD = 0B00110000;
    }
    if( akkuwert== 0){
        PORTD = 0B11111110;
    }
}
/******************************************* end of implementation ************************************************************/
