#include "ships.h"

//Função para atribuir os valores especificos para cada tipo de barco.

Ship create_Battleship( Ship ship )
{
    char shipID = 'B';
    size_t shipLen = 4;

    Ship battleship{ shipID , shipLen };

    return ship;
}
