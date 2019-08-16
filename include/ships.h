#ifndef SHIPS_H
#define SHIPS_H

#include "verify.h"

using std::vector;

// Função para verificar se o barco está em uma posição válida.
bool validation( vector< vector< char > > &board, int j, Ship ship );

Board create_Board( Board board, size_t row, size_t col );

#endif


