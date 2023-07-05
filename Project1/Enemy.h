#pragma once
#include"Player.h"


class Enemy
{
private:
	float enemyLocationX;
	float enemyLocationY;
	float enemyMoveX;
	float enemyMoveY;
	int time;
	int fpscount;
	int i;
	int imgcount;

	int img[24];
	

public:
	Enemy();
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;

	void EnemyMoveX(Player P);

	void EAnimation();
};

