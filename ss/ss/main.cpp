#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Map.h"

using namespace std;

int main()
{
    system("mode con cols=75 lines=35"); //設定開啟視窗大小
    system("color 02"); //設定背景色和前景色
    system("title 貪吃蛇 "); 

    Map m;
  
    m.Hello();

    return 0;
}