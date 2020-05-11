/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
//photoresistor high:417 low:168
int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00;
PORTA = 0xFF;
DDRB = 0xFF;
PORTB = 0x00;
unsigned char temp = 0x00;
ADC_init();
    /* Insert your solution below */
    while (1) {
		if(ADC <= 420 && ADC >= 340){
			temp = 0x80;
		}
		else if(ADC <= 339 && ADC >= 300){
                        temp = 0xC0;
                }
		else if(ADC <= 299 && ADC >= 260){
                        temp = 0xE0;
                }
		else if(ADC <= 259 && ADC >= 220){
                        temp = 0xF0;
                }
		else if(ADC <= 219 && ADC >= 180){
                        temp = 0xF8;
                }
		else if(ADC <= 179 && ADC >= 140){
                        temp = 0xFC;
                }
		else if(ADC <= 139 && ADC >= 100){
                        temp = 0xFE;
                }
		else if(ADC <= 99 && ADC >= 0){
                        temp = 0xFF;
                }
		PORTB = temp;
    }
}
