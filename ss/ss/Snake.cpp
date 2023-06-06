#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include"Snake.h"
#include"Map.h"
using namespace std;

Snake::Snake(int w, int h)
{
    width = w;
    height = h;
}

Snake::Snake()
{
}

void Snake::setWidth(int w)
{
	width = w;
}

int Snake::getWidth() const
{
	return 60;
}

void Snake::setHeight(int h)
{
	height = h;
}

int Snake::getHeight() const
{
	return 30;
}

void Snake::setGameOver(bool g)
{
    gameOver = g;
}

bool Snake::getGameOver()
{
	return gameOver;
}

void Snake::Setall()
{
    gameOver = false;
	dir = STOP;
	x = getWidth() / 2;
	y = getHeight() / 2;
	foodX = rand() % getWidth();
	foodY = rand() % getHeight();
	score = 0;
}

void  Snake::Draw()
{
    system("cls"); // 清除畫面

    for (int i = 0; i < getWidth() + 2; i++) {
        cout << "=";
    }
    cout << endl;

    for (int i = 0; i < getHeight(); i++)
    {
        for (int j = 0; j < getWidth(); j++)
        {
            if (j == 0)
                cout << "]";
            if (i == y && j == x)
                cout << "@"; // 蛇頭
            else if (i == foodY && j == foodX)
                cout << "%"; // 食物
            else
            {
                bool printTail = false;
                for (int k = 0; k < sTail; k++)
                {
                    if (s_tailX[k] == j && s_tailY[k] == i)
                    {
                        cout << "o"; // 蛇身
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == getWidth() - 1)
                cout << "[";
        }
        cout << endl;
    }

    for (int i = 0; i < getWidth() + 2; i++) {
        cout << "=";
    }
    cout << endl;

    cout << "Score:" << score << endl;

}

void Snake::key_Down()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

bool Snake::UpDate()
{
    int prevX = s_tailX[0];
    int prevY = s_tailY[0];
    int prevXX, prevYY;
    s_tailX[0] = x;
    s_tailY[0] = y;

    for (int i = 1; i < sTail; i++)
    {
        prevXX = s_tailX[i];
        s_tailX[i] = prevX;
        prevX = prevXX;

        prevYY = s_tailY[i];
        s_tailY[i] = prevY;
        prevY = prevYY;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

  
    if (x >= getWidth() || x < 0 || y >= getHeight() || y < 0) // 撞到牆壁
        gameOver = true;

    for (int i = 0; i < sTail; i++) // 撞到自己
    {
        if (s_tailX[i] == x && s_tailY[i] == y)
            gameOver = true;
    }
    if (x == foodX && y == foodY)
    {
        score += 10;
        foodX = rand() % getWidth();
        foodY = rand() % getHeight();
        sTail++;
    }

    return 1;
}
