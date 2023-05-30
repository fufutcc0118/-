#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Snake.h"
#include "Food.h"
using namespace std;

class Game
{
public:
    Game();
    void startGame();
    void pauseGame();
    void endGame();
    void updateScore();
    void updateLevel();

    int x, y, fruitX, fruitY, score;
    
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

private:
    int score;
    int level;
    static const int width = 20;
    static const int height = 20;
    bool gameOver;
    Snake snake;
    Food food;
};

#endif