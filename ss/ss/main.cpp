#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Snake.h"
using namespace std;

int main()
{
    system("mode con cols=100 lines=40"); //設定開啟視窗大小

    Snake ss;
    ss.Setup();
 
    while (!ss.getGameOver())
    {
        ss.Draw();
        ss.Input();
        ss.Logic();
        Sleep(10); // 暫停10毫秒，調整遊戲速度
    }
    return 0;
}