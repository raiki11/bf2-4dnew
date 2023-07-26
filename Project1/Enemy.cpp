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
	cnt = 0;
	Flag = FALSE;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	flyingFlg = FALSE;

	enemy.type = Stage::EnemyType[Stage::Snum][set_X];

	changeimg = 0;
	changeCt = 0;
	cflg = FALSE;
	cy = 0;
	cycount = 0;
	swy = 0;
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, P_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, R_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, G_img); // 画像の分割読み込み

};

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
		EnemyMoveY(P);
	}


	if (CheckHitKey(KEY_INPUT_A) == TRUE) {
		cflg = TRUE;
	}

	if (cflg == TRUE) {
		EDeadAnim();
	}
	//デバッグ用
	DebagHit(P);

}

void Enemy::EnemyDraw() const
{
	/*DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);*/
	/*DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);*/

	if (cflg == TRUE) {
		switch (enemy.type)
		{
		case 0:
			DrawRotaGraph(ELocationX, ELocationY + cy, 1.0f, 0, P_img[changeimg], TRUE, Flag);
			break;
		case 1:
			DrawRotaGraph(ELocationX, ELocationY + cy, 1.0f, 0, G_img[changeimg], TRUE, Flag);
			break;
		case 2:
			DrawRotaGraph(ELocationX, ELocationY + cy, 1.0f, 0, R_img[changeimg], TRUE, Flag);
			break;
		}
		

	}
	else {
		
		switch (enemy.type)
		{
		case 0:
			DrawRotaGraph(ELocationX, ELocationY, 1.0f, 0, P_img[i], TRUE, Flag);
			break;
		case 1:
			DrawRotaGraph(ELocationX, ELocationY, 1.0f, 0, G_img[i], TRUE, Flag);
			break;
		
		case 2:
			DrawRotaGraph(ELocationX, ELocationY, 1.0f, 0, R_img[i], TRUE, Flag);
			break;
	
		}

		DrawFormatString(ELocationX - 15, ELocationY - 30, GetColor(255, 0, 0), "%03d", Epoint);
		//デバッグ用
		//DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", ELocationX);
		//DrawFormatString(0, 160, 0xffffff, "time::%d", time);
		//DrawFormatString(0, 175, 0xffffff, "i::%d", i);
		if (reboundFlgStageY == TRUE) {
			DrawFormatString(0, 205, 0xffffff, "Y:TRUE");
		}
		else {
			DrawFormatString(0, 205, 0xffffff, "Y:FALSE");
		}
		if (reboundFlgStageX == TRUE) {
			DrawFormatString(0, 220, 0xffffff, "X:TRUE");
		}
		else {
			DrawFormatString(0, 220, 0xffffff, "X:FALSE");
		}
	}
}

void Enemy::EnemyMoveX(Player P)
{
	//if (ELocationX == P.GetPlayerLocationX() && ELocationY <= P.GetPlayerLocationY()) {
	//	if (Flag == TRUE) {
	//		EMoveX -= 0.01f;
	//	}
	//	else
	//	{
	//		EMoveX += 0.01f;
	//	}

	//}

	if (ELocationX > 640) {
		ELocationX = 0;
	}
	if (ELocationX < 0) {
		ELocationX = 640;
	}

	if (EMoveX > 0.5f) {
		EMoveX = 0.5f;
	}

	if (ELocationX <= P.GetPlayerLocationX()) {
		EMoveX += 0.01f;
		Flag = TRUE;

	}
	else if (ELocationX >= P.GetPlayerLocationX()) {
		EMoveX -= 0.01f;
		Flag = FALSE;

	}

	if (EMoveX < -0.5f) {
		EMoveX = -0.5f;
	}


	//反発
	if (reboundFlgStageX == TRUE) {


		reboundFlgStageX = FALSE;
		EMoveX = -1 * EMoveX*10;

	}
	if (cflg == FALSE) {
		ELocationX += EMoveX;

	}
}



void Enemy::EnemyMoveY(Player P)
{


	/*if (ELocationY <= P.GetPlayerLocationY()) {
		ELocationY += EMoveY;


	}
	else if (ELocationY >= P.GetPlayerLocationY()) {
		ELocationY -= EMoveY;

	}*/
	

	//反発
	 if (reboundFlgStageY == TRUE  ){
		
		 
			reboundFlgStageY = FALSE;
			EMoveY = -1 * EMoveY*10;
	}
	 if (flyingFlg != FALSE) {
			 EMoveY = 0;
			 
		 
		
	 }
	 
	 
		 if (ELocationY <= P.GetPlayerLocationY() && flyingFlg == FALSE) {
			 EMoveY += 0.01f;
		 }
		 else if (ELocationY >= P.GetPlayerLocationY()) {
			 EMoveY -= 0.01f;
		 }
		 if (EMoveY > 0.5f) {
			 EMoveY = 0.5f;
		 }
		 if (EMoveY < -0.5f) {
			 EMoveY = -0.5f;
		 }
	 
	


	ELocationY += EMoveY;

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
		if (i == 12) {
		i = 8;
		}
	
}

void Enemy::EDeadAnim() {


		switch (swy)
		{
		case 0:
			cycount++;
			cy -= 2.8;
			if (cycount > 9) {
				swy += 1;
				cycount = 0;
			}
			break;
		case 1:
			cycount++;
			if (cycount > 6) {
					cy += 3;
			}
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

void Enemy::DebagHit(Player P) {
	float Ex = ELocationX;
	float Exwidth = ELocationX + 64;
	float Ey = ELocationY;
	float Eywidth = ELocationY + 64;

	float px = P.GetPlayerLocationX();
	float pxwidth = px + 64;
	float py = P.GetPlayerLocationY();
	float pywidth = py + 64;


	if (Ex<=pxwidth && Exwidth>=px &&Ey<=pywidth && Eywidth>=py) {
		cflg = TRUE;

	}
}