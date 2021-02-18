#include <iostream>
#include <vector>
#include "8-puzzle.h"

int maxNewNode = 0;
std::vector<puzzleBoard> newNode;

void puzzleBoard::displayBoard(){
    std::cout << this->initial[0] << this->initial[1] << this->initial[2] << std::endl;
    std::cout << this->initial[4] << this->initial[5] << this->initial[6] << std::endl;
    std::cout << this->initial[7] << this->initial[8] << this->initial[9] << std::endl;
}

bool puzzleBoard::solvedState(){
    if (this->initial[0] == 1 && this->initial[1] == 2 && this->initial[2] == 3 && this->initial[3] == 4 && this->initial[4] == 5 && this->initial[5] == 6 && this->initial[6] == 6 && this->initial[7] == 7 && this->initial[8] == 8 && this->initial[9] == 0){
        return true;
    }
    return false;
}

void puzzleBoard::uniformSearch(puzzleBoard node, int algo){
    std::cout << "Exapnding state " << std::endl;
    node.displayBoard(); 
    std::cout << std::endl;
    newNode.push_back(node);
    int temp = newNode.size();  //check the size of new node
    if(temp > maxNewNode){      //if max size is less than newNode size, set max to newNode
        maxNewNode = newNode.size();
    }
}

void puzzleBoard::misplacedHueristic(){

}

void puzzleBoard::manhattenDistance(){

}