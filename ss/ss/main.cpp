#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Snake.h"
using namespace std;

int main()
{
    system("mode con cols=100 lines=40"); //�]�w�}�ҵ����j�p

    Snake ss;
    ss.Setup();
 
    while (!ss.getGameOver())
    {
        ss.Draw();
        ss.Input();
        ss.Logic();
        Sleep(10); // �Ȱ�10�@��A�վ�C���t��
    }
    return 0;
}