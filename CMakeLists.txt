cmake_minimum_required(VERSION 3.5)
project(BattleshipPuzzle VERSION 0.1 LANGUAGES CXX)

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )
#CMAKE_CXX_FLAGS = "-Wall";

# -------------------------------
# This is for old cmake versions
# set (CMAKE_CXX_STANDARD 11)
# -------------------------------

# set the include path
include_directories( include )

# define the sources for the project
add_executable ( bpg
				         src/main.cpp
				         src/ships.cpp
                 src/file.cpp
				         src/verify.cpp )

# define C++11 standard
set_property (TARGET bpg PROPERTY CXX_STANDARD 11)

# the end
