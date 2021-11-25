#include <iostream>
#include <vector>
#include <cstdlib>
#include "mazegen.h"
/*  
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    as06.cpp
    assingment name: Amzing union find, assignment number: 6
    
    The purpose of this program is to implement the union find data 
    structure in order to make it a real application such as making a
    maze
    
    Code status: compiles/tested
*/
int main(int argc, char *argv[])
{
    int size = std::atoi(argv[1]);
    if(std::atoi(argv[1]) < 3)
    {
        std::cout << "Value must be 3 or greater\n";
        return 0;
    }
    MazeGen A(size);
    A.generateMaze();
    A.printMaze();
}