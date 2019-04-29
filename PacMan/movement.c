#include "movement.h"
#include "objects.h"

char canMove(struct Object character)
{
	return (!(character.x % 32) && !(character.y % 32)); // Return 1 when character is on tile else return 0
}

char collision(struct Object character, char direction)
{
	// Check only for walls when on a full tile
	if((character.x % 32) == 0 && (character.y % 32) == 0){
		unsigned char x = character.x/32, y = character.y/32;
		switch(direction){
			case LEFT:
				if(field[x-1][y] != 0)
					return 1;
				break;
			case UP:
				if(field[x][y-1] != 0)
					return 1;
				break;
			case RIGHT:
				if(field[x+1][y] != 0)
					return 1;
				break;
			case DOWN:
				if(field[x][y+1] != 0)
					return 1;
				break;
		}
	}
	
	// Check for a collision with a ghost
	if(character.type == PACMAN){
		for(int i = 0; i != sizeof(ghost)/sizeof(struct Object); i++){
			switch(direction){
				case LEFT:
					if(ghost[i].x == pacman.x-1 && ghost[i].y == pacman.y)
						return 1;
					break;
				case UP:
					if(ghost[i].x == pacman.x && ghost[i].y == pacman.y-1)
						return 1;
					break;
				case RIGHT:
					if(ghost[i].x == pacman.x+1 && ghost[i].y == pacman.y)
						return 1;
					break;
				case DOWN:
					if(ghost[i].x == pacman.x && ghost[i].y == pacman.y+1)
						return 1;
					break;
			}
		}
	}
	return 0;
}