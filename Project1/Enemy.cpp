#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	enemyLocationX = 300;
	enemyLocationY = 240;
}

Enemy::~Enemy()
{
}

void Enemy::EnemyUpdate()
{
	
}

void Enemy::EnemyDraw() const
{
	DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);
}
