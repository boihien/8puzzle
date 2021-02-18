#include <iostream>
#include <vector>
#include "8-puzzle.h"

int puzzle[size];
int main(){
    int userInput;
    std::cout << "Welcome to Boi-Hien's 8-puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;
    std::cin >> userInput;

    if(userInput == 1){
        puzzle[0] = 1;
        puzzle[1] = 2;
        puzzle[2] = 3;

        puzzle[3] = 4;
        puzzle[4] = 8;
        puzzle[5] = 0;
        
        puzzle[6] = 7;
        puzzle[7] = 6;
        puzzle[8] = 5;

        std::cout << "Enter your choice of algorithm" << std::endl;
        std::cout << "1. Uniform Cost Search" << std::endl;
        std::cout << "A * with the Misplaced Tile heuristic" << std::endl;
        std::cout << "A * with the Manhatten distance heuristic" << std::endl;

        /*std::cin >> userInput;

        if(userInput == 1){

        }*/

    }
    if(userInput == 2){
        std::cout << "Under Construction .. " << std::endl;
    }
    
    return 0;
}