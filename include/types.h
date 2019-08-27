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
#include <random>
#include <chrono> 

using std::vector;

class Ship
{
    public:
        char ID; // Identificar o tipo do barco --> B: Battleship | D: Destroyer | C: Cruiser | S: Submarine.
        int length; // tamanho do barco
        int sRow, sCol; // Coordenadas do inicio do barco. 
        char orientation; // direção do barco ( horizontal, vertical e nula (U) no caso do submarino.
        int direction; // informar para a função de preenchimento em qual direção percorrer.

        Ship( char sID, int sLength )
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

        bool operator==( Board board )
        {
            for( int i = 0; i < board.row; i++ )
            {
                for( int j = 0; j < board.column; j++ )
                {
                    if( this->matrix[i][j] == board.matrix[i][j] )
                    {
                        return true;
                    }
                }
            }

            return false;
        }
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

           for( int i = 0; i < row; i++ ) {
              for( int j = 0; j < column; j++ )
                 matrix[i][j] = "~";
           }
        }

        Board(void) 
        {
          row = 0;
          column = 0;
        }

        //funçao para plotar o submarino, pois não requer um laço.
        void set_position_submarine( Ship *ship )
        {
            matrix[ship->sRow][ship->sCol] = "⬤";
        }

        //função que será chamada após todos os testes para inserir o barco.
        void set_position( Ship *ship )
        {
            if( ship->length == 1 and ship->ID == 'S')
            {
                matrix[ship->sRow][ship->sCol] = "⬤";
            }

            if( ship->orientation == 'H' )
            {
                if( ship->direction == 1 )
                {
                    for( int j = ship->sCol; j < ship->sCol + ship->length; j++ )
                    {
                        if( j == ship->sCol )
                        {
                            matrix[ship->sRow][j] = "◀";
                        }
                        else if( j == ship->sCol + ship->length - 1 )
                        {
                            matrix[ship->sRow][j] = "▶";
                        }
                        else
                        {
                            matrix[ship->sRow][j] = "■";
                        }
                    }
                }
                else if( ship->direction == -1 )
                { 
                    for( int j = ship->sCol; j > ship->sCol - ship->length; j-- )
                    { 
                        if( j == ship->sCol )
                        {
                            matrix[ship->sRow][j] = "▶";
                        }
                        else if( j == ship->sCol - ( ship->length - 1 ) )
                        {
                            matrix[ship->sRow][j] = "◀";
                        }
                        else
                        {
                            matrix[ship->sRow][j] = "■";
                        }
                    }
                }
            }
            else if( ship->orientation == 'V' )
            {
                if( ship->direction == 2 )
                {
                    for( int i = ship->sRow; i < ship->sRow + ship->length; i++ )
                    {
                        if( i == ship->sRow )
                        {
                            matrix[i][ship->sCol] = "▲";
                        }
                        else if( i == ship->sRow + ship->length - 1 )
                        {
                            matrix[i][ship->sCol] = "▼";
                        }
                        else
                        {
                            matrix[i][ship->sCol] = "■";
                        }
                    }
                }
                else if( ship->direction == -2 )
                {
                    for( int i = ship->sRow; i > ship->sRow - ship->length; i-- )
                    { 
                        if( i == ship->sRow )
                        {
                            matrix[i][ship->sCol] = "▼";
                        }
                        else if( i == ship->sRow - ( ship->length - 1 ) )
                        {
                            matrix[i][ship->sCol] = "▲";
                        }
                        else
                        {
                            matrix[i][ship->sCol] = "■";
                        }
                    }
                }
             }

        }



};


#endif

