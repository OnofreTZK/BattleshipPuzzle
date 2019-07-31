#include "table.h"

void alocation( int coluna, int linha )
{
    //char **matrix = (char**) malloc(linha*sizeof(char*));
    char **matrix = new char* [linha];

    for ( unsigned int i = 0; i < coluna; i++ )
    {
        matrix[i] = new char [coluna];
    }


}


void table_generate( int coluna, int linha )
{
    alocation(coluna, linha);

    std::cout << std::endl;
    for ( unsigned int i = 0; i < linha; i++ )
    {
        for ( unsigned int j = 0; j < coluna; j++ )
        {
            std::cout << "\x1b[96m=\x1b[0m ";
        }
        std::cout << std::endl;
    } 
}
