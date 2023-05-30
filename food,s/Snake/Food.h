#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                  
#include <ctime>
#include "Map.h"
#define N 30
#define Up 1                       
#define Down 2                      
#define Left 3                      
#define Right 4                   
using namespace std;

class Food
{
public:
	static int x;
	static int y;
	static void Rand_Food();

private:
	int food;
	static char map[N][N];
};

#endif // !FOOD_H

