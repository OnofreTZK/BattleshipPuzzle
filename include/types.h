#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>

using std::vector;

class Ship
{
    public:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        size_t length; // tamanho do barco
        int sRow, sCol; // Coordenadas do inicio do barco. 
        char orientation; // direção do barco ( horizontal, vertical e nula (U) no caso do submarino.
        int direction; // informar para a função de preenchimento em qual direção percorrer.
        
        Ship( char sID, size_t sLength )
        {
            ID = sID;
            length = sLength;
        }
       // função para inserir os valores das coordenadas e da orientação do barco --> será usada no processo de criação do tabuleiro.
        void set_values( int sX, int sY, char sOrientation, int sDirection )
        {
            sRow = sX;
            sCol = sY;
            orientation = sOrientation;
            direction = sDirection;
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

        int row, column; // valores das linhas e colunas do tabuleiro.

        vector< vector < std::string > > matrix; // corpo do tabuleiro.

        Board( int bRow, int bColumn )
        {
            row = bRow;
            column = bColumn;
        
            // "alocando" o vector de vector usando o método resize().  
            vector< std::string > mat_rows;
            mat_rows.resize( column );
            matrix.resize( row, mat_rows );

           for( int i = 0; i < row; i++ )
           {
              for( int j = 0; j < column; j++ )
                 matrix[i][j] = " # ";
           }

        }

        

};


#endif

