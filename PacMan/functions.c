#include <util/delay.h>

#include "functions.h"
#include "objects.h"
#include "millis.h"
#include "serial.h"
#include "movement.h"

unsigned long prev = 0;
void gameloop()
{
	// If the loop is done before the end of the frame, wait the remaining time
	unsigned long timediff = millis()-prev;
	if(timediff < frametime){
		//_delay_ms(timediff);
	}
	prev = millis();
}

void processData()
{
	if(canMove(pacman)){
		if(!collision(pacman, pacman.direction)){
			switch(pacman.direction){
				case LEFT:
				pacman.x -= 1;
				break;
				case UP:
				pacman.y -= 1;
				break;
				case RIGHT:
				pacman.x += 1;
				break;
				case DOWN:
				pacman.y += 1;
				break;
			}
		}
	}
}

void outputData()
{
	// Output field via serial
	for(int i = 0; i != ytiles; i++)
		SerialWrite(field[i]);
}