#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Food.h"

class Game
{
public:
    Game();
    void startGame();
    void pauseGame();
    void endGame();
    void updateScore();
    void updateLevel();

private:
    int score;
    int level;
    bool isOver;
    Snake snake;
    Food food;
};

#endif