#include "file.h"

void writeBPArmada( Manager manager, int puzNum )
{

    std::ofstream file("bpgArmada.txt");

    for( int vec = 0; vec < puzNum; vec++ )
    {
        file << "\nArmada Format\n";
        for( int i = 0; i < manager.puzzles[vec].armada.size(); i++ )
        {
            file << manager.puzzles[vec].armada[i].ID << " "
                 << manager.puzzles[vec].armada[i].sRow << " "
                 << manager.puzzles[vec].armada[i].sCol << " "
                 << manager.puzzles[vec].armada[i].orientation << "\n";
        }

         file << "\n\n\n";
    }

    file.close();

}



void writeBPMatrix( Manager manager, int puzNum, int rowNum, int colNum )
{
	std::ofstream file("bpgMatrix.txt");
	

    for( int vec = 0; vec < manager.puzzles.size(); vec++ )
    {
	      file << puzNum << std::endl;

	      file << rowNum
		    << " "
		    << colNum
		    << std::endl;
        for ( int i = 0; i < rowNum; i++)
        {
		        for( int j = 0; j < colNum; j++ )
            {
                file << manager.puzzles[vec].matrix[i][j] << "  ";
            }

            file << "\n";
        }

        file << "\n\n\n";
    }

	file.close();

	std::cout << "File saved sucessfully! ;)" << std::endl;
}


bool verify_Board( std::vector< Board > &puzzles, Board board, int posi )
{
    for( int vec = 0; vec < posi; vec++ )
    {
        if( board == puzzles[vec] )
        {
            return false;
        }
    }

    return true;
} 


void puzzle_Generator( int row, int col, int games )
{
   Manager manager( row, col, games);

   for( int vec = 0; vec < manager.puzzles.size(); vec++ )
   {
      manager.puzzles[vec] = *create_Board( &manager.puzzles[vec], row, col );
   }

   writeBPMatrix( manager, games, row, col );
   writeBPArmada( manager, games );
}  
