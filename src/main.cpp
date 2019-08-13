#include "table.h"


int main ( int argc, char const *argv[])
{
    system("clear");

    size_t games; // Qntd de jogos
    size_t rows; // Qntd de linhas
    size_t columns; // Qntd de colunas

    if( argc < 2 or argc > 6 )// Verifica a quantidade válida de argumentos para a execução.
    {
        printHelp();
        return EXIT_FAILURE;
    }
    else if( argc == 2 and ( atoi(argv[1]) >= 1 or atoi(argv[1]) <= 100 ) )
    {
        games = atoi(argv[1]);
        std::cout << "\n Default number for rows and columns: 10x10\n";
    }
    else if( atoi(argv[2]) < 7 or atoi(argv[2]) > 16 or atoi(argv[4]) < 7 or atoi(argv[4]) > 16 )
    {
        printHelp();
        return EXIT_FAILURE;
    }
    else if( strcmp( argv[1], "--rows" ) != 0 or strcmp( argv[3], "--cols" ) != 0 )
    {
        printHelp();
        return EXIT_FAILURE;
    }

    //table_generate( atoi(argv[1]), atoi(argv[2]) ); 

    return EXIT_SUCCESS;
}
