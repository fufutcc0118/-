#ifndef FOOD_H
#define FOOD_H
#define N 30
using namespace std;


class Food
{
public:
	Food(int);
	Food();

	void setFood(int);
	int getFood();

	void Rand_Food();
	int x, y;

private:
	int food;
	short food_x, food_y;      //­¹ª«®y¼Ð
	char food_map[N][N];

};
#endif // !FOOD_H
