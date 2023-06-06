#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "Map.h"
#include"Snake.h"
#include"Food.h"

using namespace std;

Map::Map(int m, int g)
{
	mod = m;
	grade = g;
}

Map::Map()
{
	grade = 1;
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };
	int autoSpeed(speed[grade]);
}

void Map::setMod(int m)
{
	mod = m;
}

int Map::getMod()
{
	return mod;
}

void Map::setGrade(int g)
{
	grade = g;
}

int Map::getGrade()
{
	return grade;
}


void Map::Hello()
{
	while (true) {
		system("cls");                  //清屏
		Print_Hello(mod);

		if (_getch() != 13) {                //判斷是否爲回車鍵,確定選擇的模式
			switch (_getch()) {              //判斷上下移動
			case 72: mod = 0; break;
			}
			continue;
		}
		//Enter 的ASCII碼爲 13, 按了回車確定模式
		if (mod == 0) {                              //普通模式
			do {
				
				system("cls");
				cout << "\n\n\n\n\t   請輸入你需要的遊戲級別: (1~8)   ";
				cin >> grade;
			} while (grade > 8 || grade < 1);   //判斷等級輸入是否正確
			autoSpeed = speed[grade];           //更新自動快進速度
			break;
		}
	
	}
	Start_Game();               
}

void Map::Print_Hello(int mod)
{
	srand((unsigned)time(nullptr));     //用時間產生隨機種子
	cout << "\n\n\n\t\t\t     歡迎來到貪吃蛇遊戲 \n\n\n\n";
	cout << "\t\t\t      請選擇你的模式:";
	cout << "\n\n\t\t\t      普通模式:";
	if (mod == 0) cout << "   *";       
}

void Map::Start_Game()
{
	Snake s;
	//Food food;
	char choose;
	s.Setall();
	//food.Rand_Food();
	do {
		s.Draw();
		s.key_Down();
		s.UpDate();
		Sleep(30); // 調整遊戲速度
	} while (!s.getGameOver());
	

	cout << "\t   Game Over！！！     你要再一次嗎？ (Y/Others)";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		s.Draw();
		Hello();
	}
	else
		cout << "\n";
		cout << "\t   掰掰囉 祝你天天開心！ (σ′▽‵)′▽‵)σ" << endl;
}



