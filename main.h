#include <iostream>
#include <vector>
using namespace std;
const int maxPuzzleSize = 9;

//used this source to create priorit queue
//https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
/*struct CompareOverload{
    bool operator()(puzzleBoard b1, puzzleBoard b2){
        return ((b1.depth + b1.h) < (b2.depth + b2.h));
    }
};*/

class puzzleBoard{
    public:
        puzzleBoard(); //initialize the board and make arrays = 0
        int initial[maxPuzzleSize];
        int totalNodes;//keeps track of total expanded nodes
        int maxNodesQueue;//keeps track of maximum number of nodes in queue at a time
        int depth; //depth of the goal node g(n)
        int h; //h(n)

        void general_search(vector<vector<int>> board, int algo);
        bool solvedState(vector<vector<int>> board); //keeps track if the board has reached the goal
        void uniformSearch();
        int misplacedHueristic(vector<vector<int>> node);
        int manhattenDistance(vector<vector<int>> node);
};