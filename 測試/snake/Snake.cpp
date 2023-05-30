#include "Snake.h"
#include "Food.h"

Snake::Snake()
{
    // ªì©l¤Æ³g­¹³DÄÝ©Ê
    length = 1;
    speed = 1;
    dir = 0;
    body.push_back(0);  // ³g­¹³Dªì©l¦ì¸m
}

void Snake::move()
{
    // ²¾°Ê³g­¹³DÅÞ¿è
    // ...
}

void Snake::grow()
{
    // ³g­¹³Dªø¤jÅÞ¿è
    // ...
}

bool Snake::collidesWith(const Food& food)
{
    // ¸I¼²ÀË´úÅÞ¿è
    // ...
    return false;
}