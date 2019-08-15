#include "verify.h"
#include "boats.h" 


int main ( int argc, char const *argv[])
{
    system("clear");

    size_t games = 1; // Qntd de jogos
    size_t rows = 10; // Qntd de linhas
    size_t columns = 10; // Qntd de colunas

    if( argc < 2 or argc > 6 )// Verifica a quantidade válida de argumentos para a execução.
    {
        printHelp();
        return EXIT_FAILURE;
    }
    else if( argc == 2 and ( atoi(argv[1]) >= 1 or atoi(argv[1]) <= 100 ) )// Se o numero de argumentos for igual a 2 (<executável> e quantidade de jogos ) games recebe o valor do argv[1]. 
    {
        games = atoi(argv[1]);
        std::cout << "\nUsing default number for rows and columns: 10x10\n\n";
    }
    else if( atoi(argv[2]) < 7 or atoi(argv[2]) > 16 or atoi(argv[4]) < 7 or atoi(argv[4]) > 16 )// Verificar o intervalo permitido pelo programa para linhas e colunas.
    {
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
        rows = atoi(argv[2]);
        columns = atoi(argv[4]);
    }

    std::cout << "quantidade de jogos: " << games << std::endl;
    std::cout << "Quantidade de linhas: " << rows << std::endl;
    std::cout << "Quantidade de colunas: " << columns << std::endl;

    Boat battleship;
    battleship = create_Battleship( battleship );

    std::cout << std::endl << "Identificação do barco: " << battleship.ID() << std::endl << "Tamanho do barco: " << battleship.length() << std::endl; 

    return EXIT_SUCCESS;
}
