#include"DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
{
	ELocationX = 320;
	ELocationY = 230;
	EMoveX = 0;
	EMoveY = 0;
	time = 0;
	fpscount = 0;
	i = 0;
	Flag = FALSE;

	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 24, 8, 3, 64, 64, img); // 画像の分割読み込み

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



	
	


	
	//デバッグ用
	
}

void Enemy::EnemyDraw() const
{
	/*DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);*/
	/*DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);*/
	DrawRotaGraph(ELocationX, ELocationY, 1.0f,0,img[i], TRUE, Flag);


	//デバッグ用
	//DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", ELocationX);
	//DrawFormatString(0, 160, 0xffffff, "time::%d", time);
	//DrawFormatString(0, 175, 0xffffff, "i::%d", i);


}

void Enemy::EnemyMoveX(Player P)
{
	/*if (ELocationX == P.GetPlayerLocationX() && ELocationY <= P.GetPlayerLocationY()) {
		if (Flag == TRUE) {
			EMoveX -= 0.01f;
		}
		else
		{
			EMoveX += 0.01f;
		}

	}*/

	if (ELocationX > 640) {
		ELocationX = 0;
	}
	if (ELocationX < 0) {
		ELocationX = 640;
	}

	if (EMoveX > 1) {
		EMoveX = 1;
	}

	if (ELocationX <= P.GetPlayerLocationX()) {
		EMoveX += 0.01f;
		Flag = TRUE;

	}
	else if (ELocationX >= P.GetPlayerLocationX()) {
		EMoveX -= 0.01f;
		Flag = FALSE;

	}

	if (EMoveX < -1) {
		EMoveX = -1;
	}

	
	ELocationX += EMoveX;
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



