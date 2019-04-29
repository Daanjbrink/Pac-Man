#include <string.h>
#include <math.h>

#include "init.h"
#include "objects.h"

void initGame()
{
	// Zero structs
	memset(field, 0, sizeof(field));
	memset(&pacman, 0, sizeof(pacman));
	memset(&ghost, 0, sizeof(ghost));

	// Fill top row with walls
	for(int i = 0; i != xtiles; i++)
		field[0][i] = WALL;

	field[1][1] = PACMAN; // Set pacman on tile 1,1
	
	//Initialize the objects
	pacman.x = 1*32; // xpos*32px
	pacman.y = 1*32; // ypos*32px
	pacman.direction = 0;
	pacman.type = 0;
}