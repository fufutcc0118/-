#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Food.h"
using namespace std;

class Snake
{
public:
    Snake();
    void Setup();
    void Draw();
    void Input();
    void Logic();
    bool collidesWith(const Food& food);

    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
    int tailX[100], tailY[100];
    int nTail;
    Game gameOver;
private:
    int length;
    int speed;
    int dir;
    static const int width = 20;
    static const int height = 20;
    Game x,y, fruitX, fruitY, score;
    std::vector<int> body;
};

#endif