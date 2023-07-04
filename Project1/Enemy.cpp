#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	enemyLocationX = 300;
	enemyLocationY = 240;
	enemyMoveX = 0;
	enemyMoveY = 0;
}

Enemy::~Enemy()
{
}

void Enemy::EnemyUpdate(Player P)
{



	if (enemyLocationX > 640) {
		enemyLocationX = 0;
	}
	if (enemyLocationX < 0) {
		enemyLocationX = 640;
	}

	if (enemyMoveX > 1) {
		enemyMoveX = 1;
	}

	if (enemyLocationX <= P.GetPlayerLocationX()) {
		enemyMoveX += 0.01f;
		
	}
	else if (enemyLocationX >= P.GetPlayerLocationX()) {
		enemyMoveX -= 0.01f;
		
	}

	if (enemyMoveX < -1) {
		enemyMoveX = -1;
	}




	enemyLocationX += enemyMoveX;
}

void Enemy::EnemyDraw() const
{
	DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);
	DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", enemyLocationX);
}
