#include "table.h"


int main ( int argc, char const *argv[])
{
    system("clear");
    
    if ( argc != 4 )
    {
        std::cout << "\x1b[91merror: \x1b[0mQuantidade de parâmetros inválida! por favor siga o formato:\n"
                  << "\t\x1b[32m./executável  \x1b[0m<colunas> <linhas> <quantidade de jogos>\n";
        return EXIT_FAILURE;
    }
    else if ( atoi(argv[1]) < 7 or atoi(argv[1]) > 16 or atoi(argv[2]) < 7 or atoi(argv[2]) > 16 )
    {
        std::cout << "\x1b[93maviso: \x1b[0m Por favor, entre com valores no intervalo de ( \x1b[32m7 \x1b[0m,\x1b[32m16 \x1b[0m) para as colunas e linhas.\n";
        return EXIT_FAILURE;
    } 

    table_generate( atoi(argv[1]), atoi(argv[2]) ); 

    return EXIT_SUCCESS;
}
