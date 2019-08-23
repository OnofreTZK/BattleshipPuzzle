# Battleship Puzzle Generator
## About
The **Battleship Puzzle Generator** is our first project for the course of **Programming Language I**, taught by professor Selan Rodrigues. This programming assignment consists of a program that creates a set of distinct battleship puzzles and writes it in an output file. The exact quantity of puzzles to be created depends on the user's specifications. 

## About the puzzle
The Battleship Puzzle is, essentially, a matrix that contains a predefined quantity of ships (which we call *armadas*), according to its rules. In this project, a valid puzzle can have dimensions between 7 and 16 for rows or columns. Also, its armada is composed of 10 ships, which are:

* 01 Battleship, with length = 4 pieces
* 02 Destroyers, with length = 3 pieces
* 03 Cruisers, with length = 2 pieces
* 04 Submarines, with length = 1 piece

Note that the ships' cells are juxtaposed and may be arranged either horizontally or vertically. Furthermore, the ships cannot touch each other, which means there must be unnoccupied cells between them, even diagonally. However, the ships may touch the edges of the matrix.

## How to compile and run

In order to run this program, you'll need to follow these steps at the project's root file:

```
cmake -S. -Bbuild
cd build
make
./bpg [<options>] <number_of_puzzles>
```
After the last command, two distinct files shall be generated. 

## Expected Output

## Possible Errors

## Limitations 

## Autorship and Collaboration

* **Sandra Bastos** - [unzerstort](https://github.com/unzerstort)

* **Tiago Onofre** - [OnofreTZK](https://github.com/OnofreTZK)
