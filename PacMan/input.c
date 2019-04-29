#include "input.h"
#include "objects.h"
#include "pin.h"

void InputInit()
{
	PinInit();
}

void InputHandle()
{
	// Analog pins go from 0-1023; 
	if(PinARead(STICK_UPDOWN) > ((255/2)+32)) // Up
		pacman.direction = UP;
	else if(PinARead(STICK_UPDOWN) < ((255/2)-32)) // Down
		pacman.direction = DOWN;
	else if(PinARead(STICK_LEFTRIGHT) > ((255/2)+32)) // RIGHT
		pacman.direction = RIGHT;
	else if(PinARead(STICK_LEFTRIGHT) < ((255/2)-32)) // LEFT
		pacman.direction = LEFT;
}