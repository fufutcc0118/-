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
	int mod;                        //�C���Ҧ�
	int grade;
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//�O�s�۰ʫe�i�t��,���ms
	int autoSpeed;
};

#endif // !MAP_H
