#include "verify.h"
#include "file.h"


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

    int games = NPUZZLE; // Qntd de jogos
    int rows = DFT_ROW; // Qntd de linhas
    int columns = DFT_COL; // Qntd de colunas

    if( argc < 2 )// Verifica a quantidade válida de argumentos para a execução.
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
    else if( argc == 2 )// Se o numero de argumentos for igual a 2 (<executável> e quantidade de jogos ) games recebe o valor do argv[1].
    {
        games = atoi(argv[1]);

        if( games < 1 or games > 100 )
        {
            printHelp();
            return EXIT_FAILURE;
        }

        std::cout << "\nUsing default number for rows and columns: 10x10\n\n";
    }
    else if( atoi(argv[2]) < MIN_ROW or atoi(argv[2]) > MAX_ROW )// Verificar o intervalo permitido pelo programa para linhas e colunas.
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
    else if( strcmp( argv[1], "--rows" ) != 0 or strcmp( argv[3], "--cols" ) != 0 ) //Verificar se o usuário entrou com os argumentos certo para informar as linhas e colunas.
    {
        printHelp();
        return EXIT_FAILURE;
    }
    else if( argc == 6 and ( strcmp( argv[1], "--rows" ) == 0 ) and ( strcmp( argv[3], "--cols" ) == 0 ) ) // ultima verificação, se estiver tudo certo os valos dos parametros são atribuidos.
    {
        games = atoi(argv[5]);

        if( games < 1 or games > 100 )
        {
            printHelp();
            return EXIT_FAILURE;
        }

        rows = atoi(argv[2]);
        columns = atoi(argv[4]);
    }



    std::cout << "Number of puzzles: " << games << std::endl;
    std::cout << "Number of rows: " << rows << std::endl;
    std::cout << "Number of columns: " << columns << std::endl;

    Board board( rows, columns ); 

    std::cout << std::endl;
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < columns; j ++ )
        {
            std::cout << board.matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    board = *create_Board( &board, rows, columns );

    std::string teste = " \u25A0 " ;
    std::cout << "\n \u25C0 " << teste << teste << " \u25B6 " <<  std::endl;

    std::cout << std::endl;
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < columns; j ++ )
        {
            std::cout << board.matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }


    puzzle_Generator( rows, columns, games );

    return EXIT_SUCCESS;
 }
