#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include"Food.h"
#define N 30
using namespace std;

Food::Food(int f)
{
	food = f;
}

Food::Food()
{
}

void Food::setFood(int f)
{
	food = f;
}

int Food::getFood()
{
	return food;
}

void Food::Rand_Food()
{
	Food food;
	do {
		food.x = rand() % (N - 2) + 1;
		food.y = rand() % (N - 2) + 1;
	} while (food_map[food.x][food.y] != ' ');
	food_map[food.x][food.y] = '%';
}
