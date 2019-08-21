#ifndef SHIPS_H
#define SHIPS_H

#include "verify.h"

using std::vector;

// Função para verificar se o barco está em uma posição válida.
bool validation( Board *board, int row, int col, Ship *ship );

// Função para verificar as bordas e o abarroamento de barcos.
Ship *val_Orientation( Board *board, int row, int col, Ship *ship);

// Função para os valores de posicionamento do barco.
void positioning( Board *board, int row, int col, Ship *ship);

// Função para preencher o tabuleiro.
Board *create_Board( Board *board, size_t row, size_t col );

#endif


