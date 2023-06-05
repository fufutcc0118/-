#ifndef MAP_H
#define MAP_H
#define N 30
using namespace std;

class Map
{
public:
	Map(int,int,int);
	Map();

	void setLevel(int);
	int getLevel();
	void setMod(int);
	int getMod();
	void setGrade(int);
	int getGrade();

	void Hello();                   //歡迎界面
	void Print_Hello(int);          //打印歡迎界面
	void Start_Game();

private:
	char map[N][N];
	int level = 1;        //遊戲關卡
	int mod;                        //遊戲模式 普通模式 == 0, 冒險模式 == 1;
	int grade;
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//保存自動前進速度,單位ms
	int autoSpeed;
};

#endif // !MAP_H
