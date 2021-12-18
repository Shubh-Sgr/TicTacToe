#define size 3
#include <iostream>
using namespace std;

class Board
{
private:
    char board[size][size];

public:
    void showBoard();
    bool isWon();
    void init();
    void startGame();
    void showInstructions();
};