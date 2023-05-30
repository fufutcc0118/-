#include <iostream>
#include <deque>
#include <windows.h>                //包含 隱藏光標
#include <conio.h>                  //包含 _getch() 和 _kbhit()
#include <ctime>
#include"Food.h"
#include"Snake.h"
#include"Map.h"
using namespace Food;

#define N 30
#define Up 1                        //方向鍵對應的的ASCII爲 72
#define Down 2                      //的ASCII爲   80
#define Left 3                      //的ASCII爲   75
#define Right 4  
using namespace std;

void Map::Hello()
{
    while (true) {
        system("cls");                  //清屏
        Print_Hello(mod);

        if (_getch() != 13) {                //判斷是否爲回車鍵,確定選擇的模式
            switch (_getch()) {              //判斷上下移動
            case 80: mod = 1; break;
            case 72: mod = 0; break;
            }
            continue;
        }
        //Enter 的ASCII碼爲 13, 按了回車確定模式
        if (mod == 0) {                              //普通模式
            do {
                system("cls");
                cout << "\n\n\n\n\t\t\t 請輸入你需要的遊戲級別: (1~8)   ";
                cin >> grade;
            } while (grade > 8 || grade < 1);   //判斷等級輸入是否正確
            autoSpeed = speed[grade];           //更新自動快進速度
            break;
        }
        else                                    //冒險模式
            break;
    }
    Start_Game();               //開始遊戲
}

void Map::Print_Hello(int)
{
    srand((unsigned)time(nullptr));     //用時間產生隨機種子,百度一下,你便知道
    cout << "\n\n\n\t\t\t\t 貪吃蛇 \n\n\n\n";
    cout << "\t\t\t     請選擇你的模式:";
    cout << "\n\n\t\t\t     普通模式:";
    if (mod == 0) cout << "   *";       //讓玩家知道未按回車確定前選擇的模式
    cout << "\n\n\t\t\t     冒險模式:";
    if (mod == 1) cout << "   *";
}

void Map::Start_Game()
{
    char choose;
    Initialize_Map();           //初始化地圖
    Food::Rand_Food();                //產生第一個食物
    do {
        Show_Map();
    } while (Update_Map());

    cout << "\t\t Game Over!!!     你先繼續嗎? (Y/Others)";
    cin >> choose;
    if (choose == 'Y' || choose == 'y') {
        Snake s;
        s.Reset();
        Hello();
    }
}

void Map::Initialize_Map()
{
    for (int i = 0; i < N; i++)                     //左右邊框
        map[0][i] = map[N - 1][i] = '*';
    for (int i = 1; i < N; i++)                     //上下邊框
        map[i][0] = map[i][N - 1] = '*';
    for (int i = 1; i < N - 1; i++)                 //中間空白
        for (int j = 1; j < N - 1; j++)
            map[i][j] = ' ';

    //map[N / 2][N / 2] = '@';                                //初始蛇頭
    //map[N / 2][N / 2 - 1] = map[N / 2][N / 2 - 2] = 'O';    //初始蛇身
    //direction.push_front(Right);        //初始化 direction
    //direction.push_front(Right);        //因爲初始爲 OO@ 尾部要進行兩個向右才能到蛇頭位置
}

int Map::Update_Map()
{
    Snake head;
    Snake tail;
    Food food{};

    int tmp_direction, tmp_others, sign = 0;    //sign == 1(讀入了方向鍵)         
    double start_time = (double)clock() / CLOCKS_PER_SEC;//讀入執行這段代碼時的時間

    do {
        if (_kbhit()) {          //_kbhit()判斷是否有按鍵輸入,但不讀入.
            tmp_others = _getch();              //代碼前有介紹
            if (tmp_others == 32)               //爲空格鍵 暫停遊戲
                while (_getch() != 32);         //當讀入空格鍵退出循環
            else if (tmp_others == 224) { //224爲方向鍵的第一個字節的ASCII碼
                tmp_direction = _getch();
                if (opposite_direction[direction.front()] == tmp_direction)
                    //是否爲上一次方向的反向,在這個設定下長度<=4不會吃到自己(下接)
                    continue;   //假設當前蛇爲: OO@ 如果輸入左轉向 判斷爲無效按鈕,繼續循環  
                switch (tmp_direction) {                                 //判斷方向
                case 72: direction.push_front(Up); sign = 1; break;
                case 80: direction.push_front(Down); sign = 1; break;
                case 75: direction.push_front(Left); sign = 1; break;
                case 77: direction.push_front(Right); sign = 1; break;
                }
                if (sign) break;                //讀入了方向鍵,推出循環 判斷情況
            }
        }
        //未讀入方向鍵或空格,判斷是否超過自動前進時間
        if ((double)clock() / CLOCKS_PER_SEC - start_time > autoSpeed / 1000.0) {//用法,代碼前有介紹
            direction.push_front(direction.front());    //自動前進,和前一次前進方向一樣
            break;
        }
    } while (true);

    map[head.x][head.y] = 'O';          //更新地圖把蛇頭原蛇頭位置置爲蛇身
    switch (direction.front()) {         //更新蛇頭座標
    case Up: head.x -= 1; break;
    case Down: head.x += 1; break;
    case Left: head.y -= 1; break;
    case Right: head.y += 1; break;
    }

    if (head.x == Food::x && head.y == Food::y) {  //是否吃到食物
        map[head.x][head.y] = '@';
        score += 10;
        if (mod == 1) {          //更新冒險模式的遊戲等級和速度,每吃6個增加一級,最高5級
            if (score / 60 >= grade) {
                if (grade < 5)
                    grade++;
                autoSpeed = speed[grade];
            }
        }
       Food::Rand_Food();                    //更新食物
    }
    else if (map[head.x][head.y] != ' ' && !(head.x == tail.x && head.y == tail.y))
        return 0;   //if(更新的頭位置是否不爲地圖中的空白 && 是否不爲蛇尾) (接下)
    //前面已經判斷沒吃到食物,所以蛇尾會前進,因爲只更新了蛇頭沒有更新蛇尾,所以排除蛇尾情況
    else {                              //沒有吃到食物    
        map[tail.x][tail.y] = ' ';      //更新地圖蛇尾
        map[head.x][head.y] = '@';      //更新地圖蛇頭
        switch (direction.back()) {      //更新蛇尾座標
        case Up: tail.x -= 1; break;
        case Down: tail.x += 1; break;
        case Left: tail.y -= 1; break;
        case Right: tail.y += 1; break;
        }
        direction.pop_back();           //彈出 前 蛇尾座標
    }
    return 1;                           //未撞牆或吃到自己
}

void Map::Show_Map()
{
    system("cls");
    for (int i = 0; i < N; i++) {
        cout << "\t";
        for (int j = 0; j < N; j++)
            cout << map[i][j] << ' ';
        if (i == N / 4)
            cout << "\t Score: " << score;
        if (i == N / 4 + 4)
            cout << "\t grade: " << grade;
        if (i == N / 4 + 8)
            cout << " 按空格鍵暫停/繼續";
        cout << endl;
    }
}
