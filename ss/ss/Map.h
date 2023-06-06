#ifndef MAP_H
#define MAP_H
using namespace std;

class Map
{
public:
	Map(int,int);
	Map();

	void setMod(int);
	int getMod();
	void setGrade(int);
	int getGrade();

	void Hello();                   
	void Print_Hello(int);          
	void Start_Game();

private:
	int mod;                        //遊戲模式
	int grade;
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//保存自動前進速度,單位ms
	int autoSpeed;
};

#endif // !MAP_H
