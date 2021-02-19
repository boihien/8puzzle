#include <iostream>
#include <vector>

const int maxPuzzleSize = 9;

class puzzleBoard{
    public:
        puzzleBoard(); //initialize the board and make arrays = 0
        int initial[maxPuzzleSize];
        int totalNodes;//keeps track of total expanded nodes
        int maxNodesQueue;//keeps track of maximum number of nodes in queue at a time
        int depth; //depth of the goal node


        void RightSwap(); //swap the node from current to the right of board
        void LeftSwap(); 
        void BotSwap();
        void TopSwap();

        void displayBoard(); //prints out board
        bool solvedState(); //keeps track if the board has reached the goal
        void uniformSearch(puzzleBoard node, int algo);
        void misplacedHueristic();
        void manhattenDistance();
};