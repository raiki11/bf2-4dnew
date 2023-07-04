#pragma once
#include"Player.h"


class Enemy
{
private:
	float enemyLocationX;
	float enemyLocationY;
	float enemyMoveX;
	float enemyMoveY;


	

public:
	Enemy();
	~Enemy();

	void EnemyUpdate(Player P);
	void EnemyDraw() const;

	void EnemyMoveX(Player P);
};

