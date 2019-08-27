#include "ships.h"

using std::vector;

// Verificar cada detalhe para o posicionamento do barco.
bool validation( Board *board, int row, int col, Ship *ship )
{
    for( int i = row - 1; i <= row + 1; i++ )
    {
        for( int j = col - 1; j <= col + 1; j++ )
        {
            if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
            {
                continue;
            }

            if( board->matrix[i][j] != "~" )
            {
                return false;
            }
        }
    }

    return true;
}



Ship *val_Orientation( Board *board, int row, int col, Ship *ship )
{
    
    if( ( row + ship->length - 1 <= board->row - 1 ) and ( board->matrix[row + ship->length - 1][col] == "~"  ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda direita da matriz ou se toca em outro barco. Resto do barco --> seu tamanho - 1.
    {
        if( ( row + ship->length <= board->row - 1 ) and ( board->matrix[row + ship->length][col] == "~" ) )
        {
            ship->set_values( row, col, 'V', 2 );
            return ship; 
        }
        else if( row + ship->length > board->row - 1 )
        {
            ship->set_values( row, col, 'V', 2 );
            return ship;
        }
    }
    else if( ( row - ( ship->length - 1 ) >= 0 ) and ( board->matrix[row - ( ship->length - 1 ) ][col] == "~"  )  ) // Testa se a posição atual menos o resto do barco ultrapassa a borda esquerda da matriz ou se toca em outro barco.
    {
        if( ( row - ship->length >= 0 ) and ( board->matrix[row - ship->length][col] == "~" ) )
        {
            ship->set_values( row, col, 'V', -2 );
            return ship;
        }
        else if( row - ship->length < 0 )
        {
            ship->set_values( row, col, 'V', -2 );
            return ship;
        }
    }
    else if( ( col + ship->length - 1 <= board->column - 1 ) and ( board->matrix[row][col + ship->length - 1] == "~" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda superiou ou toca em outro barco.
    {
        if( ( col + ship->length <= board->column - 1 ) and ( board->matrix[row][col + ship->length] == "~" ) ) 
        {
            ship->set_values( row, col, 'H', 1 );
            return ship;
        }
        else if( col + ship->length > board->column - 1 )
        {
            ship->set_values( row, col, 'H', 1 );
            return ship;
        }
    }
    else if( ( col - ( ship->length - 1 ) >= 0) and ( board->matrix[row][col - ( ship->length - 1 )] == "~" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda inferior ou toca em outro barco.
    {
        if( ( col - ship->length >= 0 ) and ( board->matrix[row][col - ship->length] == "~" ) )
        {
            ship->set_values( row, col, 'H', -1 );
            return ship; 
        }
        else if( col - ship->length < 0 )
        {
            ship->set_values( row, col, 'H', -1 );
            return ship;
        }
    }

    ship->set_values( row, col, 'D', 0 ); // nenhuma posição válida, então a posição é negada.
    return ship; // ●.
}


 
bool aux_positioning_horizontal( Board *board, int row, int col, Ship ship )
{
    if( ship.ID == 'H' )
    {
        if( ship.direction == 1 )
        {
            for( int i = row - 1; i <= row + 1; i++ )
            {
                for( int j = col - 1; j <= col + ship.length; j++ )
                {

                    if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                    {
                        continue;
                    }

                    if( board->matrix[i][j] != "~" )
                    {
                        return false;
                    }
                }
            }
        }
        else if( ship.direction == -1 )
        {
            for( int i = row - 1; i <= row + 1; i++ )
            {
                for( int j = col + 1; j >= col - ship.length; j-- )
                {
                  if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                  {
                      continue;
                  }

                  if( board->matrix[i][j] != "~" )
                  {
                      return false;
                  }
                }
            }
        }
    }

    return true;
}






bool aux_positioning_vertical( Board *board, int row, int col, Ship ship )
{
    if( ship.ID == 'V' )
    {
        if( ship.direction == 2 )
        {
            for( int i = row - 1; i <= row + ship.length; i++ )
            {
                for( int j = col - 1; j <= col + 1; j++ )
                {

                    if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                    {
                        continue;
                    }


                    if( board->matrix[i][j] != "~" )
                    {
                        return false;
                    }
                }
            }
        }
        else if( ship.direction == -2 )
        {
            for( int i = row + 1; i >= row - ship.length; i-- )
            {
                for( int j = col - 1; j <= col + 1 ; j++ )
                {
                    if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
                    {
                       continue;
                    }

                    if( board->matrix[i][j] != "~" )
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}



bool val_positioning( Board *board, int row, int col, Ship ship )
{
    bool control = false;

    if( ship.orientation == 'H' )
    {
        std::cout << "\nentrou aqui no if H\n";
        control = aux_positioning_horizontal( board, row, col, ship );
    }
    else if( ship.orientation == 'V' )
    {
        std::cout << "\nentrou aqui no if V\n";
        control = aux_positioning_vertical( board, row, col, ship );
    }

    return control;
}



Board *create_Board( Board *board, size_t row, size_t col )
{
    int x, y; // iteradores que terão seu valor escolhido aleatoriamente.
    srand( time( NULL ) );
    bool permission, control; // controlar o laço de verificação.

    for( int vec = 0; vec < board->armada.size(); vec++ ) // posicionando cada elemento da armada do maior para o menor.
    {
        permission = false;

        while( permission == false )
        {
            // srand( time( NULL ) ); //controlar a seed da função rand para que não se repita.
            x = rand() % row;
            y = rand() % col; // valor aleatório do inicio de cada barco(valores x e y da class ship )
            std::cout << "\nvalores de x e y respectivamente "<< x << ", " << y << std::endl;

            // primeira verificação sobre a coordenada escolhida.
            control = validation( board, x, y, &board->armada[vec] );
            std::cout << "\n pos validation\n";
            if( control == false )
            {
                std::cout << "\n 1 if aqui\n";
                permission = false;
                continue;
            }

            // identificar a orientação do barco.
            board->armada[vec] = *val_Orientation( board, x, y, &board->armada[vec] );
            std::cout << "\n pos val orientation\n ";
            if( board->armada[vec].orientation == 'D')
            {
                std::cout << "\n 2 if aqui\n";
                permission = false;
                continue;
            }


            if( ( board->armada[vec].length == 1 ) and ( board->armada[vec].ID = 'S' ) ) // o submarino necessita apenas uma verificação, após ela ja pode ser posicionado.
            {
                board->set_position_submarine( &board->armada[vec] );
                permission = true;
                continue;
            }

            std::cout << "\nInfo do barco " << board->armada[vec].ID
                      << "\nTamanho do barco " << board->armada[vec].length
                      << "\nCoordenadas do barco ( x e y ) " << board->armada[vec].sRow << ", " << board->armada[vec].sCol
                      << "\nOrientação e direção " << board->armada[vec].orientation << ", " << board->armada[vec].direction
                      << std::endl;


            //validar o posicionamento do barco e suas sombras.
            control = val_positioning( board, x, y, board->armada[vec] );

            if( control == false )
            {
                std::cout << "\n 3 if aqui\n";
                permission = false;
                continue;
            }

            // Plotar o barco apos todas as verificações.
            board->set_position( &board->armada[vec] );
            std::cout << std::endl << "colocou um barco\n";
            permission = true;

        }

    } 
    return board;
}


