#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                  
#include <ctime>
#define N 30
#define Up 1                       
#define Down 2                      
#define Left 3                      
#define Right 4                   
using namespace std;

class Food
{
public:
	int x;
	int y;
	void Rand_Food();

private:
	int food;
	char snake_map[N][N];
};

#endif // !FOOD_H

