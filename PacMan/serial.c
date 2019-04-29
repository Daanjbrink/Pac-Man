#include <avr/io.h>

#include "Serial.h"

void SerialInit()
{
	/*UBRR0H = (BAUDRATE>>8);
    UBRR0L = BAUDRATE;
    UCSR0B|= (1<<TXEN0); // Enable transmitter
    UCSR0C|= (1<<UNSEL)|(1<<UCSZ00)|(1<<UCSZ10);*/
}

void SerialWrite(register char* c)
{
	register short i;
	for(i = 0; i != sizeof(c); i++)
		SerialWriteByte(c[i]);
}

void SerialWriteByte(register char c)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
}