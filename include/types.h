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
    private:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        size_t length; // tamanho do barco
    public:
        void set_values( char BID, size_t Blength )
        {
            ID = BID;
            length = Blength;
        }
};


#endif

