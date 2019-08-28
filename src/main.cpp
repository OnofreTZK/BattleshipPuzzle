#include "helper.h"
#include "file.h"

// Made by Sandra Bastos & Tiago Onofre

#define MAX_ROW 16
#define MAX_COL 16
#define MAX_NPUZZLE 100

#define MIN_ROW 7
#define MIN_COL 7
#define NPUZZLE 1

#define DFT_ROW 10
#define DFT_COL 10


int main ( int argc, char const *argv[])
{
    system("clear");

    int puzzles = NPUZZLE; //! Number of puzzles
    int rows = DFT_ROW; //! Number of rows
    int columns = DFT_COL; //! Number of columns

	//! Verifies the valid amount of arguments to the program's execution
    if( argc < 2 )
    {
        std::cout << "Too few arguments!\n" << std::endl;
        printHelp();

        return EXIT_FAILURE;
    }
    else if( argc > 6 )
    {
        std::cout << "Too many arguments!\n" << std::endl;
        printHelp();
        return EXIT_FAILURE;
    }

	/*! If the amount of arguments is equal to 2 (<executable> [number of puzzles]),
	 *  puzzles receives the value of argv[1]
	 */
    else if( argc == 2 )
    {
        puzzles = atoi(argv[1]);

        if( puzzles < 1 or puzzles > 100 )
        {
            printHelp();
            return EXIT_FAILURE;
        }

        std::cout << "\nUsing default number for rows and columns: 10x10\n\n";
    }
	//* Verifies the interval of values allowed for rows and columns
    else if( atoi(argv[2]) < MIN_ROW or atoi(argv[2]) > MAX_ROW )
    {
        std::cout << "Number of rows is out of range!\n" << std::endl;
        printHelp();

        return EXIT_FAILURE;
    }
    else if( atoi(argv[4]) < MIN_COL or atoi(argv[4]) > MAX_COL )
    {
        std::cout << "Number of columns is out of range!\n" << std::endl;
        printHelp();

        return EXIT_FAILURE;
    } 
	//* Verifies if the user entered the right arguments to inform the rows and columns
    else if( strcmp( argv[1], "--rows" ) != 0 or strcmp( argv[3], "--cols" ) != 0 ) 
	{
        printHelp();

        return EXIT_FAILURE;
    }
	/*! Last verification. If everything's fine, the values of the
	 *  parameters are assigned
	 */ 
    else if( argc == 6 and ( strcmp( argv[1], "--rows" ) == 0 ) and ( strcmp( argv[3], "--cols" ) == 0 ) )
	{
        puzzles = atoi(argv[5]);

        if( puzzles < 1 or puzzles > 100 )
        {
            printHelp();

            return EXIT_FAILURE;
        }

        rows = atoi(argv[2]);
        columns = atoi(argv[4]);
    }

    std::cout << "Number of puzzles: " << puzzles << std::endl;
    std::cout << "Number of rows: " << rows << std::endl;
    std::cout << "Number of columns: " << columns << std::endl;

    puzzle_Generator( rows, columns, puzzles );

    return EXIT_SUCCESS;
 }
