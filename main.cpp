/*Peusodo code to follow from sepcs
    function general-search(problem, QUEUEING-FUNCTION)
    nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
    loop do
        if EMPTY(nodes) then return "failure"
            node = REMOVE-FRONT(nodes)
        if problem.GOAL-TEST(node.STATE) succeeds then return node
            nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
    end*/

#include <iostream>
#include <vector>
#include "main.h"
#include <queue>
#include <list>
#include <stack>

puzzleBoard::puzzleBoard(){//default constructor
    
}

//add up all number of misplaced tiles
//not including the blank 
int puzzleBoard::misplacedHueristic(vector<vector<int>> board){
    int numMisplaced = 0;
    if(board[0][0] != 1){
        numMisplaced++;
    }
    if(board[0][1] != 2){
        numMisplaced++;
    }
    if(board[0][2] != 3){
        numMisplaced++;
    }
    if(board[1][0] != 4){
        numMisplaced++;
    }
    if(board[1][1] != 5){
        numMisplaced++;
    }
    if(board[1][2] != 6){
        numMisplaced++;
    }
    if(board[2][0] != 7){
        numMisplaced++;
    }
    if(board[2][1] != 8){
        numMisplaced++;
    }

    return numMisplaced;

}

//for each wrong piece move magically into correct position
//add up number of moves for a total (h(n))
int puzzleBoard::manhattenDistance(vector<vector<int>> board){
    int total;
    for(int i = 0; i < 3; i++){//row
        for(int j = 0; j < 3; j++){
            
        }
    }
}

void general_search(vector<vector<int>> board, int algo){
    int heuristic = 0;
    if(algo == 1){
        heuristic = 0;
    }
    else if(algo == 2){
        heuristic = __is_move_assignable_impl
    }

}

bool puzzleBoard::solvedState(vector<vector<int>> board){
    vector<vector<int>> solved;
    solved[0][0] = 1;
    solved[0][1] = 2;
    solved[0][2] = 3;
    solved[1][0] = 4;
    solved[1][1] = 5;
    solved[1][2] = 6;
    solved[2][0] = 7;
    solved[2][1] = 8;
    solved[2][2] = 0;

    if (board == solved){
        return true;
    }
    return false;
}

//expand cheapest cost node
//g(n) = cost to current
//h(n) = number of steps to goal
void puzzleBoard::uniformSearch(){
    std::cout << "Expanding state " << std::endl;
    
}
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
        /*position[0] = 1;
        position[1] = 2;
        position[2] = 3;

        position[3] = 4;
        position[4] = 8;
        position[5] = 0;
        
        position[6] = 7;
        position[7] = 6;
        position[8] = 5;*/

        std::cout << "Enter your choice of algorithm" << std::endl;
        std::cout << "1. Uniform Cost Search" << std::endl;
        std::cout << "2. A * with the Misplaced Tile heuristic" << std::endl;
        std::cout << "3. A * with the Manhatten distance heuristic" << std::endl;

        std::cin >> userInput;

        if(userInput == 1){
            
        }
        else if(userInput == 2){
            
        }
        else if(userInput == 3){
           
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
        /*position[0] = input1;
        position[1] = input2;
        position[2] = input3;*/
        std::cout << "Enter the second row, use space or tabs between numbers" << std::endl;
        std::cin >> input1;
        std::cin >> input2;
        std::cin >> input3;
        /*position[3] = input1;
        position[4] = input2;
        position[5] = input3;*/
        std::cout << "Enter the third row, use space or tabs between numbers" << std::endl;
        std::cin >> input1;
        std::cin >> input2;
        std::cin >> input3;
        /*position[6] = input1;
        position[7] = input2;
        position[8] = input3;*/

        std::cout << "Enter your choice of algorithm" << std::endl;
        std::cout << "1. Uniform Cost Search" << std::endl;
        std::cout << "2. A * with the Misplaced Tile heuristic" << std::endl;
        std::cout << "3. A * with the Manhatten distance heuristic" << std::endl;

        std::cin >> userInput;

        if(userInput == 1){
            
        }
        else if(userInput == 2){
           
        }
        else if(userInput == 3){
           
        }
        else{
            std:: cout << "Not a valid algorithm" << std::endl;
            return 0;
        }
    }
    
    return 0;
}