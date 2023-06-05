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

	void Hello();                   //�w��ɭ�
	void Print_Hello(int);          //���L�w��ɭ�
	void Start_Game();

private:
	char map[N][N];
	int level = 1;        //�C�����d
	int mod;                        //�C���Ҧ� ���q�Ҧ� == 0, �_�I�Ҧ� == 1;
	int grade;
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//�O�s�۰ʫe�i�t��,���ms
	int autoSpeed;
};

#endif // !MAP_H
