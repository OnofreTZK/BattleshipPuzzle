#include "helper.h"


// Function to print '--help' guide for user.
void printHelp()
{
       std::cout << "\x1b[93mUsage: \x1b[0m[<Options>] <number_of_puzzles>:\n"
                  << "\tProgram options are: \n" 
                  << "\t\t\x1b[96m--rows <num>	\x1b[0mSpecify the number of rows for the matrix, with '<num>' in the range [\x1b[32m7 \x1b[0m,\x1b[32m16 \x1b[0m]. The default value is 10.\n"
                  << "\t\t\x1b[96m--cols <num>	\x1b[0mSpecify the number of columns for the matrix, with '<num>' in the range [\x1b[32m7 \x1b[0m,\x1b[32m16 \x1b[0m]. The default value is 10.\n"
                  << "\tRequested input: \n"
                  << "\t\t<number_of_puzzles> the number of puzzles to be generated, in the range [1, 100].\n";
}



