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
    return ship; // ●.
}


 
bool aux_positioning_horizontal( Board *board, int row, int col, Ship ship, int direction )
{
    if( ship.ID == 'H' )
    {
        if( ship.direction == 1 )
        {
            for( int i = row - 1; i < row + 1; i++ )
            {
                for( int j = col - 1; j < col + ship.length; j++ )
                {

                    if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                    {
                        continue;
                    }

                    if( i == row and (j >= col or j <= col + ship.length - 1 ) )
                    {
                        continue;
                    }

                    if( board->matrix[i][j] != "#" )
                    {
                        return false;
                    }
                }
            }
        }
        else if( ship.direction == -1 )
        {
            for( int i = row - 1; i < row + 1; i++ )
            {
                for( int j = col + 1; j > col - ship.length; j-- )
                {
                  if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                  {
                      continue;
                  }

                  if( i == row and ( j <= col or j >= col - ( ship.length - 1 ) ) )
                    {
                        continue;
                    }

                    if( board->matrix[i][j] != "#" )
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}






bool aux_positioning_vertical( Board *board, int row, int col, Ship ship, int direction )
{
    if( ship.ID == 'V' )
    {
        if( ship.direction == 2 )
        {
            for( int i = row - 1; i < row + ship.length; i++ )
            {
                for( int j = col - 1; j < col + 1; j++ )
                {

                    if( i < 0 or i > board->column - 1 or j < 0 or j > board->row - 1 )
                    {
                        continue;
                    }

                    if( j == col and (i >= row or i <= row + ship.length - 1 ) )
                    {
                        continue;
                    }

                    if( board->matrix[i][j] != "#" )
                    {
                        return false;
                    }
                }
            }
        }
        else if( ship.direction == -2 )
        {
            for( int i = row + 1; i > row + ship.length; i-- )
            {
                for( int j = col - 1; j < col + 1 ; j++ )
                {
                  if( i < 0 or i > board->column - 1 or j < 0 or j > board->row - 1 )
                  {
                      continue;
                  }

                  if( j == col and ( i <= row or i >= row - ( ship.length - 1) ) )
                    {
                        continue;
                    }

                    if( board->matrix[i][j] != "#" )
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}



int val_positioning( Board *board, int row, int col, Ship ship )
{
    if( ship.ID == 'H' )
    {
        switch ( ship.direction )
        {
          case 1:
            if( aux_positioning_horizontal( board, row, col, ship, ship.direction ) == true )
            {
                return 1;
            };
            break;
          case -1:
            if( aux_positioning_horizontal( board, row, col, ship, ship.direction ) == true )
            {
                return -1;
            }
            break;
          default:
            return 0;
        }
    }
    else if( ship.ID == 'V' )
    {
        switch ( ship.direction )
        {
          case 2:
            if( aux_positioning_vertical( board, row, col, ship, ship.direction ) == true )
            {
                return 2;
            }
            break;
          case -2:
            if( aux_positioning_vertical( board, row, col, ship, ship.direction ) == true )
            {
                return -2;
            }
            break;
          default:
            return 0;
        }
    }

    return 0;
}




bool positioning( Board *board, int row, int col, Ship ship )
{
      if( ship.ID == 'H' )
      {
          switch ( ship.direction )
          {
            case  1:
              // laço.
              break;
            case  -1:
              // laço.
              break;
            default:
              return false;
          }
      }
      else if( ship.ID == 'V' )
      {
         switch ( ship.direction )
         {
           case  2:
              // laço.
              break;
           case  -2:
              // laço.
              break;
           default:
              return false;
         }
      } 
      return false;
}



Board *create_Board( Board *board, size_t row, size_t col )
{
    int x, y; // iteradores que terão seu valor escolhido aleatoriamente.
    srand( time( NULL ) );
    bool permission;
    int  control; // controlar o laço de verificação.

    for( int vec = 0; vec < board->armada.size(); vec++ ) // posicionando cada elemento da armada do maior para o menor.
    {
        permission = false;

        while( permission == false )
        {
            // srand( time( NULL ) ); //controlar a seed da função rand para que não se repita.
            x = rand() % row - 1;
            y = rand() % col - 1; // valor aleatório do inicio de cada barco(valores x e y da class ship )

            permission = validation( board, x, y, &board->armada[vec] );

            if( permission == false )
            {
                permission = false;
                continue;
            }

            board->armada[vec] = *val_Orientation( board, x, y, &board->armada[vec] );

            if( board->armada[vec].orientation == 'D')
            {
                permission = false;
                continue;
            }

            control = val_positioning( board, x, y, board->armada[vec] );

            if( control == 0 )
            {
                permission = false;
                continue;
            }



        }

    } 
    return board;
}


