#include "ships.h"

using std::vector;

// Verificar cada detalhe para o posicionamento do barco.
bool validation( Board *board, int row, int col, Ship *ship )
{
    if( board->matrix[row][col] != "#" ) // verifica se a posiçao ao menos é 'agua'.
    {
        return false;
    }
    else if( board->matrix[row][col] == "#" ) // Se for 'agua' entra em uma nova etapa de testes.
    {
        return true;
    }

    return false;
}



Ship *val_Orientation( Board *board, int row, int col, Ship *ship )
{
    
    if( ( row + ship->length - 1 <= board->row - 1 ) or ( board->matrix[row + ship->length - 1][col] == "#"  ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda direita da matriz ou se toca em outro barco. Resto do barco --> seu tamanho - 1.
    {
        ship->set_values( row, col, 'H', 1 );
        return ship;
    }
    else if( ( row - ship->length + 1 >= 0 ) or ( board->matrix[row - ship->length + 1][col] == "#"  )  ) // Testa se a posição atual menos o resto do barco ultrapassa a borda esquerda da matriz ou se toca em outro barco.
    {
        ship->set_values( row, col, 'H', -1 );
        return ship;
    }
    else if( ( col + ship->length - 1 <= board->column - 1 ) or ( board->matrix[row][col + ship->length - 1] == "#" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda superiou ou toca em outro barco.
    {
        ship->set_values( row, col, 'V', 2 );
        return ship;
    }
    else if( ( col - ship->length + 1 >= 0) or ( board->matrix[row][col - ship->length + 1] == "#" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda inferior ou toca em outro barco.
    {
        ship->set_values( row, col, 'V', -2 );
        return ship;
    }

    ship->set_values( row, col, 'D', 0 ); // nenhuma posição válida, então a posição é negada.
    return ship;
}



void positioning( Board board, int row, int col, Ship ship )
{
   // if( board.matrix[i][j] != "#"
}




Board *create_Board( Board *board, size_t row, size_t col )
{
    int j; // iterador que terá seu valor escolhido aleatoriamente. 
    
    for( int vec = 0; vec < board->armada.size(); vec++ ) // posicionando cada elemento da armada do maior para o menor.
    {
           srand( time( NULL ) ); //controlar a seed da função rand para que não se repita.
           j = rand() % col-1; // valor aleatório do inicio de cada barco(valores x e y da class ship )

    } 
    return board;
}


