#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                  
#include <ctime>
#include"Food.h"
#include"Snake.h"

#define N 30
#define Up 1                        
#define Down 2                      
#define Left 3                      
#define Right 4
using namespace std;

void Food::Rand_Food()
{
    Food food;
    do {
        food.x = rand() % (N - 2) + 1;
        food.y = rand() % (N - 2) + 1;
    } while (snake_map[food.x][food.y] != ' ');
    snake_map[food.x][food.y] = '%';
}
