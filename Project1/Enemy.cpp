#include"DxLib.h"
#include "Enemy.h"
#include "Stage.h"


Enemy::Enemy(int set_X,int set_Y)
{
	//ELocationX = 320;
	//ELocationY = 230;
	ELocationX = Stage::EnemyX[Stage::Snum][set_X];
	ELocationY = Stage::EnemyY[Stage::Snum][set_Y];
	EMoveX = 0;
	EMoveY = 0;
	time = 0;
	fpscount = 0;
	i = 0;
	Flag = FALSE;
	changeimg = 0;
	changeCt = 0;
	cflg = FALSE;
	cy = 0;
	cycount = 0;
	swy = 0;
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

	if (CheckHitKey(KEY_INPUT_A) == TRUE) {
		cflg = TRUE;
	}

	if (cflg == TRUE) {

		switch (swy)
		{
		case 0:
			cy -= 2.5;
			cycount++;
			if (cycount > 12) {
				swy += 1;
				cycount = 0;
			}
			break;
		case 1:
			cy += 0.5;
			cycount++;
			if (cycount > 18)swy += 1;
		case 2:
			cy+=3;
			if (cy >= 300)swy += 1;
			break;
		default:
			break;
		}

		//敵やられたときのモーション
		if (changeCt <= 5) {
			++changeCt;
			changeimg = 13;
		}
		if (changeCt >= 6) {
			++changeCt;
			changeimg = 14;
		}
		if (changeCt == 12) {
			changeCt = 0;
		}
	}
	
	//デバッグ用
	
}

void Enemy::EnemyDraw() const
{
	/*DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);*/
	/*DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);*/

	//DrawRotaGraph(ELocationX, ELocationY, 1.0f,0,img[i], TRUE, Flag);



	//デバッグ用
	//DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", ELocationX);
	//DrawFormatString(0, 160, 0xffffff, "time::%d", time);
	//DrawFormatString(0, 175, 0xffffff, "i::%d", i);
	//DrawFormatString(0, 300, 0xffffff, "changeimg::%d", changeimg);
	DrawFormatString(0, 300, 0xffffff, "fpscount::%d", fpscount);
	DrawFormatString(0, 340, 0xffffff, "cy::%d", cy);
	DrawFormatString(0, 380, 0xffffff, "swy::%d", swy);

	DrawRotaGraph(ELocationX, ELocationY + cy, 1.0f, 0, img[changeimg], TRUE, Flag);

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



