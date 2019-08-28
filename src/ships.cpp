#include "ships.h"

using std::vector;

/*! This function verifies each detail concerning the ship's positioning,
 *  checking whether the shadow surrounding the generated position is available..
 */
bool validation( Board *board, int row, int col, Ship *ship )
{
	/* The loop begins at the left superior diagonal of the coordinate (x - 1, y - 1)
	 * and ends at the left inferior diagonal of the coordinate (x + 1, y + 1)
	 */
    for( int i = row - 1; i <= row + 1; i++ )
    {
        for( int j = col - 1; j <= col + 1; j++ )
        {
            //! If the values exceed the board's borders, they'll be skipped
            if( i < 0 or i > board->row - 1 or j < 0 or j > board->column - 1 )
            {
                continue;
            }
            //! If at least one space is different of water, the position is denied
            if( board->matrix[i][j] != "~" )
            {
                return false;
            }
        }
    }

    //! In the loop's end the position is validated
    return true;
}


//! This function verifies whether it is possible to position the ship vertically (downwards)
void verify_vertical_down( Board *board, int row, int col, Ship *ship )
{

	/*! Verifies whether the current position plus the rest of the ship (size - 1)
	 * 	exceeds the right border of the matrix or touches another ship
	 */
    if( ( row + ship->length - 1 <= board->row - 1 ) and ( board->matrix[row + ship->length - 1][col] == "~"  ) )
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


//! Checks if it's possible to place the ship vertically (upwards)
void verify_vertical_up( Board *board, int row, int col, Ship *ship )
{
	/*! Verifies if the current position minus the rest of the ship
	 *	exceeds the left border of the matrix or touches another one
	 */
    if( ( row - ( ship->length - 1 ) >= 0 ) and ( board->matrix[row - ( ship->length - 1 ) ][col] == "~"  ) )
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


//! Verifies whether it's possible to place the ship horizontally to the right
void verify_horizontal_right( Board *board, int row, int col, Ship *ship )
{
	/*! Checks if the current position plus the rest of the ship exceeds
	 *  the superior border or touches another ship
	 */
    if( ( col + ship->length - 1 <= board->column - 1 ) and ( board->matrix[row][col + ship->length - 1] == "~" ) )
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



//! Verifies whether it's possible to place the ship horizontally to the left

void verify_horizontal_left( Board *board, int row, int col, Ship *ship )
{
	/*! Checks if the current position plus the rest of the ship exceeds
	 *  the inferior border or touches another ship
	 */
    if( ( col - ( ship->length - 1 ) >= 0) and ( board->matrix[row][col - ( ship->length - 1 )] == "~" ) )
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


//! Checks whether the ship will be correctly placed in the puzzle 
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
		//! if there's no valid position, then the position is denied
        ship->set_values( row, col, 'D', 0 ); 
	}
}


//! 
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
        control = aux_positioning_horizontal( board, row, col, ship );
    }

    else if( ship.orientation == 'V' )
    {
        control = aux_positioning_vertical( board, row, col, ship );
    }

    return control;
}


//! generates a (pseudo) random number to be used as starting point 
int generate_random_number( int range )
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 generator ( seed1 );

    return generator()%range;
}


//! creates the puzzle 
Board *create_Board( Board *board, int row, int col )
{
	//! iterators that'll have their value randomly chosen

    bool permission, control; //! controls the verification loop

    int count; //! control helper so that we can avoid infinite loops

    for( int vec = 0; vec < board->armada.size(); vec++ ) //! positioning each element of the armada from largest to smallest.
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

           	//! controls the generate_random_number seed in order to avoid repetition
            x = generate_random_number( row );
            y = generate_random_number( col ); //! random value from each ship's start (x, y values from Ship class)

            //! first verification of the chosen coordinate
            control = validation( board, x, y, &board->armada[vec] );
            
			if( control == false )
            {
                std::cout << "\n 1 if aqui\n";
                permission = false;
                continue;
            }

            //! identify the ship's orientation 
            val_Orientation( board, x, y, &board->armada[vec] );
            
			if( board->armada[vec].orientation == 'D')
            {
                std::cout << "\n 2 if aqui\n";
                permission = false;
                continue;
            }


            if( ( board->armada[vec].length == 1 ) and ( board->armada[vec].ID = 'S' ) ) //! the submarine needs only of one verification, after that it may be positioned
            {
                board->armada[vec].set_values( x, y, 'U', 0 );
                board->set_position_submarine( &board->armada[vec] );
                permission = true;
                continue;
            } 

            //! validates the positioning of the ship and its shadow
            control = val_positioning( board, x, y, board->armada[vec] );
            
			if( control == false )
            {
                permission = false;
                continue;
            }

            //! plots the ship after all verifications 
            board->set_position( &board->armada[vec] );
            permission = true;

        }

    } 
    return board;
}


