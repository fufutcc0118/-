#include <iostream>
#include <deque>
#include <windows.h>                
#include <conio.h>                 
#include <ctime>
#include "Snake.h"
#include"Food.h"

#define N 30
#define Up 1                       
#define Down 2                     
#define Left 3                      
#define Right 4                    
using namespace std;

void Snake::Start_Game()
{
    char choose;
    Initialize_Map();           //初始化地圖
    Food food;
    food.Rand_Food();                //產生第一個食物
    do {
        Show_Map();
    } while (Update_Map());

    cout << "\t\t Game Over!!!     你先繼續嗎? (Y/Others)";
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {
        Reset();
    }
}

void Snake::Initialize_Map()
{
    snake_map[N / 2][N / 2] = '@';                                //初始蛇頭
    snake_map[N / 2][N / 2 - 1] = snake_map[N / 2][N / 2 - 2] = 'O';    //初始蛇身
    direction.push_front(Right);        //初始化 direction
    direction.push_front(Right);        
}
void Snake::Show_Map()
{
    system("cls");
    for (int i = 0; i < N; i++) {
        cout << "\t";
        for (int j = 0; j < N; j++)
            cout << snake_map[i][j] << ' ';
        if (i == N / 4)
            cout << "\t Score: " << score;
        if (i == N / 4 + 4)
            cout << "\t grade: " << grade;
        if (i == N / 4 + 8)
            cout << " 按空格鍵暫停/繼續";
        cout << endl;
    }
}

int Snake::Update_Map()//更新遊戲
{
    int tmp_direction, tmp_others, sign = 0;         
    double start_time = (double)clock() / CLOCKS_PER_SEC;

    do {
        if (_kbhit()) {          
            tmp_others = _getch();              
            if (tmp_others == 32)               //爲空格鍵 暫停遊戲
                while (_getch() != 32);         
            else if (tmp_others == 224) {
                tmp_direction = _getch();
                if (opposite_direction[direction.front()] == tmp_direction)
                    continue;   
                switch (tmp_direction) {                                 //判斷方向
                case 72: direction.push_front(Up); sign = 1; break;
                case 80: direction.push_front(Down); sign = 1; break;
                case 75: direction.push_front(Left); sign = 1; break;
                case 77: direction.push_front(Right); sign = 1; break;
                }
                if (sign) break;                
            }
        }
        if ((double)clock() / CLOCKS_PER_SEC - start_time > autoSpeed / 1000.0) {
            direction.push_front(direction.front());    //自動前進,和前一次前進方向一樣
            break;
        }
    } while (true);

    snake_map[head.x][head.y] = 'O';          //更新地圖把蛇頭原蛇頭位置置爲蛇身
    switch (direction.front()) {         //更新蛇頭座標
    case Up: head.x -= 1; break;
    case Down: head.x += 1; break;
    case Left: head.y -= 1; break;
    case Right: head.y += 1; break;
    }
    Food food{};
    if (head.x == food.x && head.y == food.y) {  //是否吃到食物
        snake_map[head.x][head.y] = '@';
        score += 10;
        if (mod == 1) {          //更新冒險模式的遊戲等級和速度,每吃6個增加一級,最高5級
            if (score / 60 >= grade) {
                if (grade < 5)
                    grade++;
                autoSpeed = speed[grade];
            }
        }
        food.Rand_Food();                    //更新食物
    }
    else if (snake_map[head.x][head.y] != ' ' && !(head.x == tail.x && head.y == tail.y))
        return 0;  
    else {                              //沒有吃到食物    
        snake_map[tail.x][tail.y] = ' ';      
        snake_map[head.x][head.y] = '@';      
        switch (direction.back()) {      //更新蛇尾座標
        case Up: tail.x -= 1; break;
        case Down: tail.x += 1; break;
        case Left: tail.y -= 1; break;
        case Right: tail.y += 1; break;
        }
        direction.pop_back();           
    }
    return 1;                           //未撞牆或吃到自己
}


void Snake::Reset()
{
    Initialize_Map();
    head = { N / 2, N / 2 };
    tail = { N / 2, N / 2 - 2 };
    mod = 0;
    score = 0;
    grade = 1;
    autoSpeed = 800;
    direction.clear();
}
