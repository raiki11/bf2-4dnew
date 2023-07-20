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
	cnt = 0;
	Flag = FALSE;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	flyingFlg = FALSE;

	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 24, 8, 3, 64, 64, img); // 画像の分割読み込み
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



	
	


	
	//デバッグ用
	
}

void Enemy::EnemyDraw() const
{
	/*DrawCircle(enemyLocationX, enemyLocationY, 4, 0x00ff00, TRUE);*/
	/*DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);*/
	DrawRotaGraph(ELocationX, ELocationY, 1.0f,0,img[i], TRUE, Flag);

	DrawFormatString(ELocationX-15 , ELocationY-30, GetColor(255, 0, 0), "%03d", Epoint);
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
	ELocationX += EMoveX;
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
		 flyingFlg = FALSE;
			 EMoveY = 0;
			 
		 
		
	 }

	 if (ELocationY <= P.GetPlayerLocationY()) {
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
		if (i == 13) {
		i = 8;
		}

	
	
	
}



