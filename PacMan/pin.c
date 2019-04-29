#include <avr/io.h>

#include "pin.h"

void PinInit()
{
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // Enable ADC and set prescaler bits
	ADMUX = (1<<6); // AVCC with external capacitor at AREF pin
	
	DDRD = (1<<2); // Set pin 16 as input
}

char PinRead(char pin)
{
	return (PIND & pin);
}

short PinARead(char pin)
{
	ADMUX |= (pin & 0b00000111); // Keep 'pin' between 0 and 7
	ADCSRA |= (1<<ADSC); // Start conversion
	while(ADCSRA & (1<<ADSC)); // Wait till conversion is done	  
	return ADC; // Return analog value
}