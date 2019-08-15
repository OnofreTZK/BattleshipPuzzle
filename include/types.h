#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

class Ship
{
    public:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        size_t length; // tamanho do barco
        int srow, scol; // Coordenadas do inicio do barco. 
        char orientation; // direção do barco ( horizontal, vertical e nula (U) no caso do submarino.
        
        Ship( char SID, size_t Slength )
        {
            ID = SID;
            length = Slength;
        }
       // função para inserir os valores das coordenadas e da orientação do barco --> será usada no processo de criação do tabuleiro.
        void set_values( int sx, int sy, char sorientation )
        {
            srow = sx;
            scol = sy;
            orientation = sorientation;
        }
};

class Board
{
    public:
        // vector para guardar toda a armada e auxiliar no posicionamento de cada barco.
        std::vector< Ship > armada = {
        Ship { 'B', 4 },
        Ship { 'D', 3 },
        Ship { 'D', 3 },
        Ship { 'C', 2 },
        Ship { 'C', 2 },
        Ship { 'C', 2 },
        Ship { 'S', 1 },
        Ship { 'S', 1 },
        Ship { 'S', 1 },
        Ship { 'S', 1 } };

        int row, column;

        Board( int brow, int bcolumn )
        {
            row = brow;
            column = bcolumn;
        }

};


#endif

