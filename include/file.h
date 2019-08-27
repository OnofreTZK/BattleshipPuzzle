#ifndef FILE_H
#define FILE_H

#include "manager.h" 

/*! This library contains all functions regarding file manipulation.
*/ 

// writeBPMatrix writes the file containing the matrix-format puzzles
void writeBPMatrix(Board *board, int puzNum, int rowNum, int colNum);

// writeBPArmada writes the file containing the armada-format puzzles
void writeBPArmada();

#endif
