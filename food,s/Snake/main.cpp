#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                 
#include <ctime>

#include"Map.h"
#define N 30
#define Up 1                        
#define Down 2                      
#define Left 3                     
#define Right 4                     
using namespace std;

int main() {

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                   
    CONSOLE_CURSOR_INFO CursorInfo;                                   
    GetConsoleCursorInfo(handle, &CursorInfo);      //獲取控制檯光標信息 //  隱藏
    CursorInfo.bVisible = false;                    //隱藏控制檯光標       //  光標
    SetConsoleCursorInfo(handle, &CursorInfo);      //設置控制檯光標狀態 //  方法

    Map map;
    map.Hello();

    return 0;

}