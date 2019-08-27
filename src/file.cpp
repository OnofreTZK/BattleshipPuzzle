#include "file.h"

void writeBPMatrix( std::vector < int > &vector, int puzNum, int rowNum, int colNum )
{
	std::ofstream file("bpgMatrix.bp");
	
	file << puzNum << std::endl;

	file << rowNum
		 << " "
		 << colNum
		 << std::endl;

    for ( int i = 0; i < vector.size(); i++)
		file << vector[i] << std::endl;

/*	board = *create_Board( &board, rowNum, colNum );

    file << std::endl;

    for( int i = 0; i < rowNum; i++ )
    {
        for( int j = 0; j < colNum; j ++ )
        {
            file << board.matrix[i][j] << "  ";
        }

        file << std::endl;
    }
*/
	file.close();

	std::cout << "File saved sucessfully! ;)" << std::endl;
}

void writeBPArmada()
{

}
