#include <string>
#include <iostream>
using namespace std;

class GameBoard
{
    string name1, name2;
    char gameSpace[4][4];
    char turn;

public:
    GameBoard();
    void setName1(string nameIn);
    void setName2(string nameIn);
    void setCharX(int row, int column);
    void setCharO(int row, int column);
    int fourInRow();
    int fourInColumn();
    int fourInDiagonal();
    void printInfo(int i);
    void printMatrix();
};

GameBoard::GameBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gameSpace[i][j] = '_';
        }
    }
}

void GameBoard::printMatrix()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << gameSpace[i][j] << " ";
        }
        cout << "\n";
    }
}

void GameBoard::setName1(string nameIn)
{
    name1 = nameIn;
}
void GameBoard::setName2(string nameIn)
{
    name2 = nameIn;
}

void GameBoard::setCharX(int row, int column)
{
    gameSpace[row][column] = 'x';
}

void GameBoard::setCharO(int row, int column)
{
    gameSpace[row][column] = 'o';
}
int GameBoard::fourInRow()
{
    int result = 0;
    int countX, countO;
    for (int i = 0; i < 4; i++)
    {

        countX = 0, countO = 0;
        for (int j = 0; j < 4; j++)
        {
            if (gameSpace[i][j] =='x')
            {
                countX++;
            }
            if (gameSpace[i][j] == 'o')
            {
                countO++;
            }
        }
        if (countX == 4)
        {
            result = 1;
            break;
        }
        else if (countO == 4)
        {
            result = 2;
            break;
        }
    }
    return result;
}
int GameBoard::fourInColumn()
{
    int result = 0;
    for (int i = 0; i < 4; i++)
    {

        int countX = 0, countO = 0;
        for (int j = 0; j < 4; j++)
        {
            if (gameSpace[j][i] == 'x')
            {
                countX++;
            }
            if (gameSpace[j][i] == 'o')
            {
                countO++;
            }
        }
        if (countX == 4)
        {
            result = 1;
            break;
        }
        else if (countO == 4)
        {
            result = 2;
            break;
        }
    }
    return result;
}

void GameBoard::printInfo(int i)
{
    if (i == 1)
        cout << "****** " << name1 << " Wins ******";
    else if (i == 2)
        cout << "****** " << name2 << " Wins ******";
    else
        cout << "****** Match tied ******";
}

int GameBoard::fourInDiagonal()
{
    int result = 0;
    int countX = 0, countO = 0;
    for (int i = 0; i < 4; i++)
    {

        if (gameSpace[i][i] == 'x')
        {
            countX++;
        }
        if (gameSpace[i][i] == 'o')
        {
            countO++;
        }
    }

    if (countX == 4)
    {
        result = 1;
    }
    else if (countO == 4)
    {
        result = 2;
    }
    else
    {
        countX = 0;
        countO = 0;
        for (int i = 0; i < 4; i++)
        {

            if (gameSpace[i][3 - i] == 'x')
            {
                countX++;
            }
            if (gameSpace[i][3 - i] == 'o')
            {
                countO++;
            }
        }

        if (countX == 4)
        {
            result = 1;
        }
        if (countO == 4)
        {
            result = 2;
        }
    }
    return result;
}