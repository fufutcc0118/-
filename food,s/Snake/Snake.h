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
    int opposite_direction[5] = { 0, 80, 72, 77, 75 };
    int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//保存自動前進速度,單位ms
public:
    Snake() : head({ N / 2, N / 2 }), tail({ N / 2, N / 2 - 2 }), autoSpeed(speed[grade]) 
        , mod(0), score(0), grade(1) { }
    void Start_Game();
    void Initialize_Map();
    int Update_Map();
    void Show_Map();
    void Reset();                   //復位
};
#endif // !SNAKE_H
