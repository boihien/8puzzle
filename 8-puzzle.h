#include <iostream>
#include <vector>

const int size = 9;

class puzzleBoard{
    public:
        puzzleBoard();
        int initial[size];
        void displayBoard();
        bool solvedState();
        void uniformSearch(puzzleBoard node, int algo);
        void misplacedHueristic();
        void manhattenDistance();
};