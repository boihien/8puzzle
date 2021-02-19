#include <iostream>
#include <vector>
#include "main.h"

int maxNewNode = 0;
std::vector<puzzleBoard> newNode;

puzzleBoard::puzzleBoard(){//default constructor
    for(int i = 0; i < maxPuzzleSize; i++){
        initial[i] = 0;
    }
}

void puzzleBoard::displayBoard(){
    std::cout << initial[0] << initial[1] << initial[2] << std::endl;
    std::cout << initial[3] << initial[4] << initial[5] << std::endl;
    std::cout << initial[6] << initial[7] << initial[8] << std::endl;
}

bool puzzleBoard::solvedState(){
    if (initial[0] == 1 && initial[1] == 2 && initial[2] == 3 && initial[3] == 4 && initial[4] == 5 && initial[5] == 6 && initial[6] == 6 && initial[7] == 7 && initial[8] == 8 && initial[9] == 0){
        return true;
    }
    return false;
}

//expand cheapest cost node
//g(n) = cost to current
//h(n) = number of steps to goal
void puzzleBoard::uniformSearch(puzzleBoard node, int algo){
    std::cout << "Expanding state " << std::endl;
    node.displayBoard(); 
    /*Peusodo code to follow
    function general-search(problem, QUEUEING-FUNCTION)
    nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
    loop do
        if EMPTY(nodes) then return "failure"
            node = REMOVE-FRONT(nodes)
        if problem.GOAL-TEST(node.STATE) succeeds then return node
            nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
    end*/

    
}

//add up all number of misplaced tiles 
void puzzleBoard::misplacedHueristic(){

}

//for each wrong piece move magically into correct position
//add up number of moves for a total (h(n))
void puzzleBoard::manhattenDistance(){


}

int board[maxPuzzleSize];
int main(){
    int userInput;
    std::cout << "Welcome to Boi-Hien's 8-puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;
    std::cin >> userInput;

    if(userInput == 1){
        //default puzzle 
        //1 2 3
        //4 8 0
        //7 6 5
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
        int input1;
        int input2;
        int input3;
        std::cout << "Enter your puzzle, use a zero to represent the blank" << std::endl;
        std::cout << "Enter the first row, use space or tabs between numbers" << std::endl;
        std::cin >> input1;
        std::cin >> input2;
        std::cin >> input3;
        board[0] = input1;
        board[1] = input2;
        board[2] = input3;
        std::cout << "Enter the second row, use space or tabs between numbers" << std::endl;
        std::cin >> input1;
        std::cin >> input2;
        std::cin >> input3;
        board[3] = input1;
        board[4] = input2;
        board[5] = input3;
        std::cout << "Enter the third row, use space or tabs between numbers" << std::endl;
        std::cin >> input1;
        std::cin >> input2;
        std::cin >> input3;
        board[6] = input1;
        board[7] = input2;
        board[8] = input3;

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
    
    return 0;
}