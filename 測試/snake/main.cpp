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
        Sleep(10); // �Ȱ�10�@��A�վ�C���t��
    }
    return 0;
}