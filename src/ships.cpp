#include "ships.h"

using std::vector;

// Verificar cada detalhe para o posicionamento do barco.
// A função checa se a sombra ao redor da posição gerada está disponivel.
// O laço inicia na diagonal superior esquerda da coordenada ( x - 1, y -1 ).
// E termina na diagonal inferior esquerda da coordenada ( x + 1, y + 1 ).
bool validation( Board *board, int row, int col, Ship *ship )
{
    for( int i = row - 1; i <= row + 1; i++ )
    {
        for( int j = col - 1; j <= col + 1; j++ )
        {
            // Caso os valores ultrapassem as bordas do tabuleiro, eles serão pulados.
            if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
            {
                continue;
            }
            // Se ao menos um espaço for diferente de 'agua' a posição é negada.
            if( board->matrix[i][j] != "~" )
            {
                return false;
            }
        }
    }

    // No fim do laço a posição é validade. 
    return true;
}



void verify_vertical_down( Board *board, int row, int col, Ship *ship )
{

    if( ( row + ship->length - 1 <= board->row - 1 ) and ( board->matrix[row + ship->length - 1][col] == "~"  ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda direita da matriz ou se toca em outro barco. Resto do barco --> seu tamanho - 1.
    {
        if( ( row + ship->length <= board->row - 1 ) and ( board->matrix[row + ship->length][col] == "~" ) )
        {
            ship->set_values( row, col, 'V', 2 );
        }
        else if( row + ship->length > board->row - 1 )
        {
            ship->set_values( row, col, 'V', 2 );
        }
        else
        {
            ship->set_values( row, col, 'N', 0 );
        }
    }
    else
    {
        ship->set_values( row, col, 'N', 0 );
    }
}



void verify_vertical_up( Board *board, int row, int col, Ship *ship )
{
    if( ( row - ( ship->length - 1 ) >= 0 ) and ( board->matrix[row - ( ship->length - 1 ) ][col] == "~"  ) ) // Testa se a posição atual menos o resto do barco ultrapassa a borda esquerda da matriz ou se toca em outro barco.
    {
        if( ( row - ship->length >= 0 ) and ( board->matrix[row - ship->length][col] == "~" ) )
        {
            ship->set_values( row, col, 'V', -2 );
        }
        else if( row - ship->length < 0 )
        {
            ship->set_values( row, col, 'V', -2 );
        }
        else
        {
            ship->set_values( row, col, 'N', 0 );
        }
        
    }
    else
    {
        ship->set_values( row, col, 'N', 0 );
    }
}



void verify_horizontal_right( Board *board, int row, int col, Ship *ship )
{
    if( ( col + ship->length - 1 <= board->column - 1 ) and ( board->matrix[row][col + ship->length - 1] == "~" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda superiou ou toca em outro barco.
    {
        if( ( col + ship->length <= board->column - 1 ) and ( board->matrix[row][col + ship->length] == "~" ) ) 
        {
            ship->set_values( row, col, 'H', 1 );
        }
        else if( col + ship->length > board->column - 1 )
        {
            ship->set_values( row, col, 'H', 1 );
        }
        else
        {
            ship->set_values( row, col, 'N' , 0 );
        }
    }
    else
    {
        ship->set_values( row, col, 'N' , 0 );
    }
}



void verify_horizontal_left( Board *board, int row, int col, Ship *ship )
{
    if( ( col - ( ship->length - 1 ) >= 0) and ( board->matrix[row][col - ( ship->length - 1 )] == "~" ) ) // Testa se a posição atual mais o resto do barco ultrapassa a borda inferior ou toca em outro barco.
    {
        if( ( col - ship->length >= 0 ) and ( board->matrix[row][col - ship->length] == "~" ) )
        {
            ship->set_values( row, col, 'H', -1 );
        }
        else if( col - ship->length < 0 )
        {
            ship->set_values( row, col, 'H', -1 );
        }
        else
        {
            ship->set_values( row, col, 'N', 0 );
        }
    }
    else
    {
        ship->set_values( row, col, 'N', 0 );
    }
}



void val_Orientation( Board *board, int row, int col, Ship *ship )
{
    verify_vertical_down( board, row, col, ship );

    if( ship->orientation == 'N' )
    {
        verify_vertical_up( board, row, col, ship );
    }

    if( ship->orientation == 'N' )
    {
        verify_horizontal_right( board, row, col, ship );
    }

    if( ship->orientation == 'N' )
    {
        verify_horizontal_left( board, row, col, ship );
    }

    if( ship->orientation == 'N' )
    {
        ship->set_values( row, col, 'D', 0 ); // nenhuma posição válida, então a posição é negada.
        //return ship;
    }
}


 
bool aux_positioning_horizontal( Board *board, int row, int col, Ship ship )
{
    if( ship.orientation == 'H' )
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
    if( ship.orientation == 'V' )
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
        std::cout << "\nentrou aqui no if H do val_positionig\n";
        control = aux_positioning_horizontal( board, row, col, ship );
    }
    else if( ship.orientation == 'V' )
    {
        std::cout << "\nentrou aqui no if V do val_positioning\n";
        control = aux_positioning_vertical( board, row, col, ship );
    }

    return control;
}



int generate_random_number( int range )
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 generator ( seed1 );

    return generator()%range;
}



Board *create_Board( Board *board, int row, int col )
{
    int x, y; // iteradores que terão seu valor escolhido aleatoriamente.

    srand( time( NULL ) );

    bool permission, control; // controlar o laço de verificação.

    int count;// Auxiliar no controle para evitar um loop infinito.

    for( int vec = 0; vec < board->armada.size(); vec++ ) // posicionando cada elemento da armada do maior para o menor.
    {
        permission = false;
        count = 0;

        while( permission == false )
        {
            if( count == board->row * board->column )
            {
                permission = true;
                vec = vec - 2;
                continue;
            }
            std::cout << "\nLINHAS: "<< board->row << "\nCOLUNAS: " << board->column << "\nCONTADOR!!!!! " << count << std::endl;
            count++;

            // srand( time( NULL ) ); //controlar a seed da função rand para que não se repita.
            x = generate_random_number( row );
            y = generate_random_number( col ); // valor aleatório do inicio de cada barco(valores x e y da class ship )
            std::cout << "\nvalores de x e y respectivamente "<< x << ", " << y << std::endl;

            // primeira verificação sobre a coordenada escolhida.
            control = validation( board, x, y, &board->armada[vec] );
            std::cout << "\n passou na validation\n";
            if( control == false )
            {
                std::cout << "\n 1 if aqui\n";
                permission = false;
                continue;
            }

            // identificar a orientação do barco.
            val_Orientation( board, x, y, &board->armada[vec] );
            std::cout << "\n passou na val_orientation\n ";
            if( board->armada[vec].orientation == 'D')
            {
                std::cout << "\n 2 if aqui\n";
                permission = false;
                continue;
            }


            if( ( board->armada[vec].length == 1 ) and ( board->armada[vec].ID = 'S' ) ) // o submarino necessita apenas uma verificação, após ela ja pode ser posicionado.
            {
                board->armada[vec].set_values( x, y, 'U', 0 );
                board->set_position_submarine( &board->armada[vec] );
                permission = true;
                std::cout << "\nPosicionou o submarino\n";
                continue;
            }

            /*std::cout << "\nInfo do barco " << board->armada[vec].ID
                      << "\nTamanho do barco " << board->armada[vec].length
                      << "\nCoordenadas do barco ( x e y ) " << board->armada[vec].sRow << ", " << board->armada[vec].sCol
                      << "\nOrientação e direção " << board->armada[vec].orientation << ", " << board->armada[vec].direction
                      << std::endl; */


            //validar o posicionamento do barco e suas sombras.
            control = val_positioning( board, x, y, board->armada[vec] );
            std::cout << "\nPassou na val_positioning\n";
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


