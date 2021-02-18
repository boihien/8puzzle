#include <iostream>
#include <vector>

const size = 9;

class puzzleBoard{
    public:
        puzzleBoard();
        int initial[size];
        void displayBoard();
        bool solvedState();
        void uniformSearch();
        void misplacedHueristic();
        void manhattenDistance();
};