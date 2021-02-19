#include <iostream>
#include <vector>
#include "main.h"

int maxNewNode = 0;
std::vector<puzzleBoard> newNode;

puzzleBoard::puzzleBoard(){
    for(int i = 0; i < maxPuzzleSize; i++){
        initial[i] = 0;
    }
}

void puzzleBoard::RightSwap(){

}
void puzzleBoard::LeftSwap(){

}
void puzzleBoard::BotSwap(){

}
void puzzleBoard::TopSwap(){

}

void puzzleBoard::displayBoard(){
    std::cout << this->initial[0] << this->initial[1] << this->initial[2] << std::endl;
    std::cout << this->initial[3] << this->initial[4] << this->initial[5] << std::endl;
    std::cout << this->initial[6] << this->initial[7] << this->initial[8] << std::endl;
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

int board[maxPuzzleSize];
int main(){
    int userInput;
    std::cout << "Welcome to Boi-Hien's 8-puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;
    std::cin >> userInput;

    if(userInput == 1){
        board[0] = 1;
        board[1] = 2;
        board[2] = 3;

        board[3] = 4;
        board[4] = 8;
        board[5] = 0;
        
        board[6] = 7;
        board[7] = 6;
        board[8] = 5;

        std::cout << "Enter your choice of algorithm" << std::endl;
        std::cout << "1. Uniform Cost Search" << std::endl;
        std::cout << "2. A * with the Misplaced Tile heuristic" << std::endl;
        std::cout << "3. A * with the Manhatten distance heuristic" << std::endl;

        std::cin >> userInput;

        if(userInput == 1){
            puzzleBoard createObject;
            createObject.displayBoard();
            createObject.uniformSearch(createObject, userInput);
        }
        else if(userInput == 2){
            puzzleBoard createObject;
            createObject.displayBoard();
            createObject.misplacedHueristic();
        }
        else if(userInput == 3){
            puzzleBoard createObject;
            createObject.displayBoard();
            createObject.manhattenDistance();
        }
        else{
            std:: cout << "Not a valid algorithm" << std::endl;
            return 0;
        }

    }
    if(userInput == 2){
        std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;

    }
    
    return 0;
}