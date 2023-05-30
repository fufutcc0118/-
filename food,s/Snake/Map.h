#include <iostream>
#include <deque>
#include <windows.h>                //包含 隱藏光標
#include <conio.h>                  //包含 _getch() 和 _kbhit()
#include <ctime>
#include"Food.h"
#include"Snake.h"

#define N 30
#define Up 1                        //方向鍵對應的的ASCII爲 72
#define Down 2                      //的ASCII爲   80
#define Left 3                      //的ASCII爲   75
#define Right 4  
using namespace std;

class Map {
private:
    deque<int> direction;           //保存每次前進的方向,最近一次前進添加到最前面
    int mod;                        //遊戲模式 普通模式 == 0, 冒險模式 == 1;
    int score;
    int grade;
    int autoSpeed;                  //更新遊戲自動更新速度
    char map[N][N];                 //保存輸出      //如 xx[Up] = 80 Down的ASCII碼爲80
    int opposite_direction[5] = { 0, 80, 72, 77, 75 };//保存各方向的反方向的ASCII碼(接上面)
    int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//保存自動前進速度,單位ms
public:
    Map() : mod(0), score(0), grade(1), autoSpeed(speed[grade]) { }//構造函數
    void Hello();                   //歡迎界面
    void Print_Hello(int);          //打印歡迎界面
    void Start_Game();
    void Initialize_Map();
    int Update_Map();
    void Show_Map();
    //void Reset();                   //復位
};
