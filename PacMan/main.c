#include <avr/io.h>

#include "init.h"
#include "functions.h"
#include "millis.h"
#include "serial.h"
#include "input.h"

int main()
{
	SerialInit();
	InputInit();
	initGame();
	millis_init();
	
    while (1) 
    {
		gameloop();
		InputHandle();
		processData();
		outputData();
    }
}