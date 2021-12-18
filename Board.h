#include <iostream>
using namespace std;
#define size 3

class Board
{
private:
    char board[size][size];

public:
    void showBoard()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void showInstructions()
    {
        cout << "Please Choose a cell no. for your move" << endl;
        int num = 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << num++ << " ";
            }
            cout << endl;
        }
    }

    void init()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                board[i][j] = '.';
        }
    }

    bool isWon()
    {
        for (int i = 0; i < size; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
                return true;
        }

        for (int i = 0; i < size; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
                return true;
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
            return true;

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')
            return true;
        return false;
    }

    void startGame()
    {
        init();
        showInstructions();

        int moveIndex = 0;
        int player = 0;
        int x, y;
        while (!isWon() && moveIndex != size * size)
        {
            if (player == 0)
            {
                int cellNo;

                while (1)
                {
                    cout << "Player 1,Enter cellNo. for your Move" << endl;
                    cin >> cellNo;
                    cellNo--;
                    x = cellNo / 3;
                    y = cellNo % 3;
                    if (cellNo >= 0 && cellNo <= 8)
                    {
                        if (board[x][y]!='.')
                        {
                            cout<<"Invalid Move";
                        }
                        else
                            break;
                    }
                    else
                    {
                        cout<<"Invalid Move,choose cellNo from 1 to 9";
                    }
                }
                board[x][y] = 'O';
                showBoard();
                moveIndex++;
                player = 1;
            }

            else
            {
                int cellNo;
                while (1)
                {
                    cout << "Player 2,Enter cellNo. for your Move" << endl;
                    cin >> cellNo;
                    cellNo--;
                    x = cellNo / 3;
                    y = cellNo % 3;
                    if (cellNo >= 0 && cellNo <= 8)
                    {
                        if (board[x][y]!='.')
                        {
                            cout<<"Invalid Move,you can't choose selected cells"<<endl;
                        }
                        else
                            break;
                    }
                    else
                    {
                        cout<<"Invalid Move,choose cellNo from 1 to 9"<<endl;
                    }
                }
                board[x][y] = 'X';
                showBoard();
                moveIndex++;
                player = 0;
            }
        }

        if (!isWon() &&
            moveIndex == size * size)
            cout << "It is Draw";
        else
        {
            if (player == 0)
                cout << "Player 2 won";
            else
                cout << "Player 1 won";
        }
        return;
    }
};