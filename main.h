#include <iostream>
#include <vector>
#include <tuple>//using tuple to store different elements together
using namespace std;
const int maxPuzzleSize = 9;

//used this source to create priority queue
//https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
struct CompareOverload{
    bool operator()(tuple<int, int, vector<vector<int>>> b1, tuple<int, int, vector<vector<int>>> b2){
        return get<0>(b1) + get<1>(b1) > get<0>(b2) + get<1>(b2);
    }
};

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