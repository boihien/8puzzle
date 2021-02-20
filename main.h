#include <iostream>
#include <vector>
#include <tuple>//using tuple to store different element types together
#include <queue>
using namespace std;
const int maxPuzzleSize = 9;

//used this source to create priority queue
//https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
//created class for priority queue
//expand nodes with smallest f(n) value
//f(n) = g(n) + h(n)
//tuple<h(n), depth, 2dvector>
//compare struct for priority queue
struct compare{
    bool operator()(tuple<int, int, vector<vector<int>>> b1, tuple<int, int, vector<vector<int>>> b2){
        return get<0>(b1) + get<1>(b1) > get<0>(b2) + get<1>(b2);//returns the larger f(n)
    }
};
class puzzleBoard{
    public:
        puzzleBoard(); //default constructor
        int totalNodes;//keeps track of total expanded nodes
        int maxNodesQueue;//keeps track of maximum number of nodes in queue at a time
        int depth; //depth of the goal node g(n)
        int h; //h(n)

        void general_search(vector<vector<int>> board, int algo);
        bool solvedState(vector<vector<int>> board); //keeps track if the board has reached the goal
        int misplacedHueristic(vector<vector<int>> node);//counts h(n) in misplaced hueristic
        int manhattenDistance(vector<vector<int>> node);//counts h(n) in manhatten
        int uniformSearch(vector<vector<int>> node);//set h(n) = 0
        void expansion(tuple<int, int, vector<vector<int>>> node, priority_queue<tuple<int, int, vector<vector<int>>>, vector<tuple<int, int, vector<vector<int>>>>, compare> &pq, int algo);
};