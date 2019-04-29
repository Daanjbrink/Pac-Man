#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define frametime 33 // This game runs on 30 frames per second, which means every 33.33ms is a frame

void gameloop(); // Make sure timing is correct
void processData(); // Tick
void outputData(); // Export to GPU

#endif