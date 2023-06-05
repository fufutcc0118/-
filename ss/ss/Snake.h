#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#define N 30

using namespace std;

struct  Snake
{
public:
	Snake(int, int);
	Snake();

	void setWidth(int);
	int getWidth()const;
	void setHeight(int);
	int getHeight()const;
	void setGameOver(bool);
	bool getGameOver();

	void Setall();
	void Draw();
	void key_Down();
	bool UpDate();

private:
	bool gameOver;

	int x=0, y=0, foodX=0, foodY=0, score=0;
	int s_tailX[100], s_tailY[100];
	int sTail=0;
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;

	int width;
	int height;
};
#endif // !SNAKE_H
