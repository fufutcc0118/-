#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                 
#include <ctime>
#include "Snake.h"
#define N 30
#define Up 1                        
#define Down 2                      
#define Left 3                     
#define Right 4                     
using namespace std;

int main() {

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    
    CONSOLE_CURSOR_INFO CursorInfo;                                     
    GetConsoleCursorInfo(handle, &CursorInfo);      
    CursorInfo.bVisible = false;                    
    SetConsoleCursorInfo(handle, &CursorInfo);      

}