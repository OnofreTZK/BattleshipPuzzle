#ifndef MNG_H
#define MNG_H

// Made by Sandra Bastos & Tiago Onofre 

#include "ships.h"

using std::vector;

/*! This class will generate the battleship
 *  boards 
 */
class Manager{

    public:

        vector< Board > puzzles;

        Manager( int bRow, int bColumn, int Games )
        {

            // "allocating" the vector of vectors using the method resize()
            puzzles.resize( Games );

           for( int i = 0; i < puzzles.size(); i++ )
           {
              puzzles[i] = Board( bRow, bColumn );
           }

        }
};

#endif
