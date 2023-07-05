#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	enemyLocationX = 300;
	enemyLocationY = 240;
	enemyMoveX = 0;
	enemyMoveY = 0;
	time = 0;
	fpscount = 0;
	imgcount = 0;
	i = 0;

	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 24, 8, 3, 64, 64, img); // �摜�̕����ǂݍ���

}

Enemy::~Enemy()
{
}

void Enemy::EnemyUpdate(Player P)
{
	if (++fpscount >= 60)
	{
		EAnimation();
	}

	if (i >= 8) {
		EnemyMoveX(P);
	}

	/*����s���̎c�[
	if (enemyLocationX == P.GetPlayerLocationX() && enemyLocationY <= P.GetPlayerLocationY()) {
		enemyMoveX -= 0.01f;
	}*/


	
	//�f�o�b�O�p
	
}

void Enemy::EnemyDraw() const
{
	/*DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);*/
	DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);


	//�f�o�b�O�p
	DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", enemyLocationX);
	DrawFormatString(0, 160, 0xffffff, "time::%d", time);
	DrawFormatString(0, 175, 0xffffff, "i::%d", i);


}

void Enemy::EnemyMoveX(Player P)
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

void Enemy::EAnimation()
{
	
		++time;
		fpscount = 0;

		if (i < 8) {
			++i;
		}
		if (i >= 8 ) {
			++i;
			
		}
		if (i == 13) {
		i = 8;
		}

	
	
	
}



