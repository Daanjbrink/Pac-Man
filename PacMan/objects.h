#ifndef OBJECTS_H_
#define OBJECTS_H_

// Define game dimensions
#define xtiles 28
#define ytiles 36

// Define directions
#define LEFT 1
#define UP 2
#define RIGHT 4
#define DOWN 8

// Define object types
#define PACMAN 1
#define GHOST 2
#define WALL 4

struct Object {
	short x; // 0 to 896 (28tiles*32px)
	short y; // 0 to 1152 (36tiles*32px)
	char direction; // 1 = left; 2 = up; 4 = right; 8 = down;
	char type; // 0 = pacman; 1 = ghost;
};

char field[xtiles][ytiles]; // Game field; 0 = nothing, 1 = pacman, 2 = ghost, 3 = wall
struct Object pacman; // Init pacman object
struct Object ghost[4];

#endif