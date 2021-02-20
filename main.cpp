#include <iostream>
#include <vector>
#include "main.h"
#include <queue>
#include <list>
#include <stack>

/*Peusodo code to follow from sepcs
    function general-search(problem, QUEUEING-FUNCTION)
    nodes = MAKE-QUEUE(MAKE-NODE(problem.INITIAL-STATE))
    loop do
        if EMPTY(nodes) then return "failure"
            node = REMOVE-FRONT(nodes)
        if problem.GOAL-TEST(node.STATE) succeeds then return node
            nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
    end*/
puzzleBoard::puzzleBoard(){//default constructor
    
}

//expand cheapest cost node
//g(n) = cost to current
//h(n) = number of steps to goal
int puzzleBoard::uniformSearch(vector<vector<int>> node){
    int h = 0;
    return h;
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
bool puzzleBoard::solvedState(vector<vector<int>> board){
    if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 6 && board[2][0] == 7 && board[2][1] == 8 && board[2][2] == 0){
        return true;
    }
    return false;
}
void puzzleBoard::general_search(vector<vector<int>> board, int algo){
    int heuristic = 0;
    if(algo == 1){
        heuristic = 0;//uniform cost sets h = 0
    }
    else if(algo == 2){
        heuristic = misplacedHueristic(board);
    }
    else if(algo == 3){
        heuristic = manhattenDistance(board);
    }
    std::cout << "reached here" << std::endl;

    int maxNodes = 0;
    int success = -1;

    tuple<int, int, std::vector<vector<int>>> node (heuristic, 0, board);

    //creates priority queue nodes that stores vector board
    //removing elements in order
    //pq<tuple, vector<tuple>, compare>
    std::priority_queue< tuple<int, int, std::vector<vector<int>>>, std::vector< tuple < int, int, std::vector<vector<int>>>>, compare> pq;
    pq.push(node);//push tuple (node) onto the pq

    std::cout << "Expanding State" << std::endl;
    tuple <int, int, vector<vector<int>>> TOQ = pq.top();//set TOQ to the top of priority queue
    std::vector<vector<int>> matrix = get<2>(TOQ);//get the matrix in tuple t
    for(int i = 0; i < 3; i++){//row
        for(int j = 0; j < 3; j++){//col
            std::cout << matrix[i][j];//print 2d vector at i,j of matrix of pq
        }
        std::cout << endl;
    }
    /*loop do
        if EMPTY(nodes) then return "failure"
            node = REMOVE-FRONT(nodes)
        if problem.GOAL-TEST(node.STATE) succeeds then return node
            nodes = QUEUEING-FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
    end*/
    while(success != 0 && success != 1){//loop until success is set to 0
        if(pq.empty()){
            std::cout << "Error, queue empty" << endl;
            success == 0;
            return;
        }
        TOQ = pq.top(); //set teuple t to be the top of pq
        get<2>(node) = get<2>(TOQ); //get 2d vector in node and set to t
        pq.pop();//removing front node since no goal

        if(solvedState(get<2>(node))){
            matrix = get<2>(node);
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    std::cout << matrix[i][j];
                }
                std::cout << endl;
            } 
        }
        std::cout << "expanded a total of " << totalNodes << std::endl;
        std::cout << "max number of nodes in queue was " << std::endl;
        std::cout << "depth of goal" << std::endl;

        expansion(TOQ, pq, algo);

        TOQ = pq.top();//set current tuple to the new top
        matrix = get<2>(TOQ);//set matrix to the 2d vector in current tuple
        std::cout << "The best state to expand with a g(n) =  " << get<1>(TOQ) << "and h(n) = " << get<0>(TOQ) << "is " << std::endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                std::cout << matrix[i][j];
            }
            std::cout << endl;
        }

    }
}

void puzzleBoard::expansion(tuple<int, int, vector<vector<int>>> node, priority_queue<tuple<int, int, vector<vector<int>>>, vector<tuple<int, int, vector<vector<int>>>>,compare> &pq, int algo){
    int heuristic = 0;
    std::vector<vector<int>> board = get<2> (node); //get 2 index in tuple node
    int row = -1; int col = -1; //keep track of where the zero is
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 0){
                row = i;//assign zeroposition to tracker
                col = j;
            }
        }
    }

    //move 0 up
    //1 2 3      1 2 0
    //4 8 0 ---> 4 8 3
    //7 6 5      7 6 5
    std::vector<vector<int>> temp = board;
    tuple<int, int, vector<vector<int>>> child;
    if(row != 0){//check if 0 is at border
        swap(temp[row][col], temp[row-1][col]);//subtract from row to  move up
        if(algo == 1){
            heuristic = 0;
        }
        else if(algo == 2){
            heuristic = misplacedHueristic(temp);
        }
        else{
            heuristic = manhattenDistance(temp);
        }
    }
    get<0>(child) = heuristic; //set child node h to 
    h = get<0>(child);
    get<1>(child) = get<1>(node) + 1; //count depth of node
    depth = get<1>(child);
    get<2>(child) = temp; //set parent 2d vector to new node
    totalNodes++;
    pq.push(child); //push child node onto pq


    //move 0 left
    //1 2 3      1 2 3
    //4 8 0 ---> 4 0 8
    //7 6 5      7 6 5
    temp = board;
    if(col != 0){
        swap(temp[row][col], temp[row][col-1]);//subtract from col to left
        if(algo == 1){
            heuristic = 0;
        }
        else if(algo == 2){
            heuristic = misplacedHueristic(temp);
        }
        else{
            heuristic = manhattenDistance(temp);
        }
    }
    get<0>(child) = heuristic; //set child node h to 
    h = get<0>(child);
    get<1>(child) = get<1>(node) + 1; //count depth of node
    depth = get<1>(child);
    get<2>(child) = temp; //set parent 2d vector to new node
    totalNodes++;
    pq.push(child); //push child node onto pq

    //move 0 down
    //1 2 3      1 2 3
    //4 8 0 ---> 4 8 5
    //7 6 5      7 6 0
    temp = board;
    if(row != 2){
        swap(temp[row][col], temp[row + 1][col]);//add to row to move down
        if(algo == 1){
            heuristic = 0;
        }
        else if(algo == 2){
            heuristic = misplacedHueristic(temp);
        }
        else{
            heuristic = manhattenDistance(temp);
        }
    }
    get<0>(child) = heuristic; //set child node h to 
    h = get<0>(child);
    get<1>(child) = get<1>(node) + 1; //count depth of node
    depth = get<1>(child);
    get<2>(child) = temp; //set parent 2d vector to new node
    totalNodes++;
    pq.push(child); //push child node onto pq

    //move 0 right
    //1 2 3      1 2 3
    //4 0 8 ---> 4 8 0
    //7 6 5      7 6 5
    temp = board;
    if(col != 2){
        swap(temp[row][col], temp[row][col + 1]);//add to col to move right
        if(algo == 1){
            heuristic = 0;
        }
        else if(algo == 2){
            heuristic = misplacedHueristic(temp);
        }
        else{
            heuristic = manhattenDistance(temp);
        }
    }
    get<0>(child) = heuristic; //set child node h to 
    h = get<0>(child);
    get<1>(child) = get<1>(node) + 1; //count depth of node
    depth = get<1>(child);
    get<2>(child) = temp; //set parent 2d vector to new node
    totalNodes++;
    pq.push(child); //push child node onto pq

}

int main(){
    int userInput;
    puzzleBoard Object;
    vector<vector<int>> board;
    std::cout << "Welcome to Boi-Hien's 8-puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle" << std::endl;
    std::cin >> userInput;

    if(userInput == 1){
        
        std::cout << "reached here" << std::endl;
        
        
        std::cout << "reached here" << std::endl;
        
        std::cout << "Enter your choice of algorithm" << std::endl;
        std::cout << "1. Uniform Cost Search" << std::endl;
        std::cout << "2. A * with the Misplaced Tile heuristic" << std::endl;
        std::cout << "3. A * with the Manhatten distance heuristic" << std::endl;
        std::cin >> userInput;

        if(userInput == 1){
            Object.general_search(board, 1);
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
