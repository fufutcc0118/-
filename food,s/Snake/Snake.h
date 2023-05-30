#ifndef SNAKE_H
#define SNAKE_H
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

class Snake {
private:
    class snake {                   
    public:
        int x;
        int y;
    };
    snake head, tail;               
    deque<int> direction;    
    int mod;
    int score;
    int grade;
    int autoSpeed;
    char snake_map[N][N]; 
public:
    int x;
    int y;
    Snake() : head({ N / 2, N / 2 }), tail({ N / 2, N / 2 - 2 }) { }
    void Initialize_Map();
    void Reset();                   //復位
};
#endif // !SNAKE_H
