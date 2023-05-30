#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                 
#include <ctime>
#include "Snake.h"
#include"Food.h"

#define N 30
#define Up 1                       
#define Down 2                     
#define Left 3                      
#define Right 4                    
using namespace std;

void Snake::Initialize_Map()
{
    snake_map[N / 2][N / 2] = '@';                                //初始蛇頭
    snake_map[N / 2][N / 2 - 1] = snake_map[N / 2][N / 2 - 2] = 'O';    //初始蛇身
    direction.push_front(Right);        //初始化 direction
    direction.push_front(Right);        
}

void Snake::Reset()
{
    Initialize_Map();
    head = { N / 2, N / 2 };
    tail = { N / 2, N / 2 - 2 };
    mod = 0;
    score = 0;
    grade = 1;
    autoSpeed = 800;
    direction.clear();
}
