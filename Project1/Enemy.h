#pragma once
#include"Player.h"


class Enemy
{
private:
	float ELocationX;
	float ELocationY;
	float EMoveX;
	float EMoveY;
	int time;
	int fpscount;
	int i;
	int Flag;

	int img[24];
	

public:
	Enemy();
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;

	void EnemyMoveX(Player P);

	void EAnimation();
};

