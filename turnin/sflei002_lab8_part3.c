/*	Author: sflei002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
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
DDRD = 0xFF;
PORTD = 0x00;
ADC_init();
    /* Insert your solution below */
    while (1) {
		unsigned short x = ADC;
		unsigned char b = (char)x;
		unsigned char d = (char)(x >> 8);
		if(ADC >= 208){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
    }
}
