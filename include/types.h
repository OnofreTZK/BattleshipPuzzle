#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;

class Ship
{
    public:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        size_t length; // tamanho do barco
        int sRow, sCol; // Coordenadas do inicio do barco. 
        char orientation; // direção do barco ( horizontal, vertical e nula (U) no caso do submarino.
        
        Ship( char sID, size_t sLength )
        {
            ID = sID;
            length = sLength;
        }
       // função para inserir os valores das coordenadas e da orientação do barco --> será usada no processo de criação do tabuleiro.
        void set_values( int sX, int sY, char sOrientation )
        {
            sRow = sX;
            sCol = sY;
            orientation = sOrientation;
        }
};

class Board
{
    public:
        // vector para guardar toda a armada e auxiliar no posicionamento de cada barco.
        vector< Ship > armada = {
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

		vector< vector < char > > board = {

		};

        int row, column;

        Board( int bRow, int bColumn )
        {
            row = bRow;
            column = bColumn;
        }

};


#endif

