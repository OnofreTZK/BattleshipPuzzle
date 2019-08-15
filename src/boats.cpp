#include "boats.h"

//Função para atribuir os valores especificos para cada tipo de barco.

Boat create_Battleship( Boat boat )
{
    char b_id = 'B';
    size_t b_length = 4;

    Boat battleship{ b_id, b_length };

    return boat;
}
