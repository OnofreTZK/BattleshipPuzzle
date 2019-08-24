#ifndef SHIPS_H
#define SHIPS_H

#include "verify.h"

using std::vector;

// Função para verificar se o barco está em uma posição válida.
bool validation( Board *board, int row, int col, Ship *ship );

// Função para verificar as bordas e o abarroamento de barcos.
Ship *val_Orientation( Board *board, int row, int col, Ship *ship);

// Função auxiliar para verificar toda a 'sombra' do barco se este estiver na horizontal.
bool aux_positioning_horizontal( Board *board, int row, int col, Ship ship, int direction );

// Função auxiliar para verificar todas a 'sombra' do barco se este estiver na vertical.
bool aux_positioning_vertical( Board *board, int row, int col, Ship ship, int direction );

// Função para os valores de posicionamento do barco.
void positioning( Board *board, int row, int col, Ship *ship);

// Função para preencher o tabuleiro.
Board *create_Board( Board *board, size_t row, size_t col );

#endif


