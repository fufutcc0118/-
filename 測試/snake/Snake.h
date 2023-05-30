#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include"Food.h"

class Snake
{
public:
    Snake();
    void move();
    void grow();
    bool collidesWith(const Food& food);

private:
    int length;
    int speed;
    int dir;
    std::vector<int> body;
};

#endif