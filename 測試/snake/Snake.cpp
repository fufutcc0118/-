#include "Snake.h"
#include "Food.h"

Snake::Snake()
{
    // ��l�Ƴg���D�ݩ�
    length = 1;
    speed = 1;
    dir = 0;
    body.push_back(0);  // �g���D��l��m
}

void Snake::move()
{
    // ���ʳg���D�޿�
    // ...
}

void Snake::grow()
{
    // �g���D���j�޿�
    // ...
}

bool Snake::collidesWith(const Food& food)
{
    // �I���˴��޿�
    // ...
    return false;
}