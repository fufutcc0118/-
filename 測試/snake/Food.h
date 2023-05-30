#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Food
{
public:
    Food();
    void random();

private:
    int x;
    int y;
};

#endif