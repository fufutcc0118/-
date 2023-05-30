#include "Game.h"

int main()
{
    Game game;
    game.startGame();

    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); // 暫停10毫秒，調整遊戲速度
    }
    return 0;
}