#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "millis.h"

#if F_CPU > 16320000 // 16.32MHz - 65.28MHz
#define CLOCKSEL (_BV(CS20))
#define PRESCALER 256
#elif F_CPU > 2040000 // 2.04MHz - 16.32MHz
#define CLOCKSEL (_BV(CS01)|_BV(CS00))
#define PRESCALER 64
#elif F_CPU > 255 // 256Hz - 2.04MHz
#define CLOCKSEL (_BV(CS01))
#define PRESCALER 8
#endif

static volatile unsigned long milliseconds;

ISR(TIMER0_COMPA_vect)
{
	milliseconds++;
}

// Initialise library
void millis_init()
{
	// Timer settings
	TCCR0A = (1<<WGM01);
	TCCR0B = CLOCKSEL;
	TIMSK0 = (1<<OCIE0A);
	OCR0A = ((F_CPU / PRESCALER) / 1000);
}

// Get current milliseconds
unsigned long millis()
{
	register unsigned long ms;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		ms = milliseconds;
	}
	return ms;
}