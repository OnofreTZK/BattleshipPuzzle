#ifndef MNG_H
#define MNG_H

#include "ships.h"

using std::vector;

class Manager{

    public:

        vector< Board > puzzles;

        Manager( int bRow, int bColumn, int Games )
        {

            // "alocando" o vector de vector usando o método resize()
            puzzles.resize( Games );

           for( int i = 0; i < puzzles.size(); i++ )
           {
              puzzles[i] = Board( bRow, bColumn );
           }

        }
};

#endif
