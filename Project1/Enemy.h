#pragma once
class Enemy
{
private:
	float enemyLocationX;
	float enemyLocationY;
	float enemyMoveX;
	float enemyMoveY;
	int Espeed;

public:
	Enemy();
	~Enemy();

	void EnemyUpdate();
	void EnemyDraw() const;
};

