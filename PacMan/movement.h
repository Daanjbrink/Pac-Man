#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "objects.h"

char canMove(struct Object character);
char collision(struct Object character, char direction);

#endif