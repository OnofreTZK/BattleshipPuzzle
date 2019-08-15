#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

class Boat
{
    public:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        size_t length; // tamanho do barco
        int x, y;
        char direction;
        Boat( char BID, size_t Blength )
        {
            ID = BID;
            length = Blength;
        }
};


#endif

