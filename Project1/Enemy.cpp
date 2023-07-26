#include"DxLib.h"
#include "Enemy.h"
#include "Stage.h"
#include "HitBox.h"

Enemy* hitenemy[6];
HitBox hit;
Stage stage;

int Enemy::DeadFlg = FALSE;
int Enemy::EdeadCount = -1;
int Enemy::ElastFlg = FALSE;

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
	switch (enemy.type)
	{
	case 0:
		enemy.MaxSpeed = P_MAX;
		break;
	case 1:
		enemy.MaxSpeed = G_MAX;
		break;
	case 2:
		enemy.MaxSpeed = R_MAX;
		break;
	}

	Epoint = 500;
	changeimg = 0;
	changeCt = 0;
	cflg = FALSE;
	cy = 0;
	cycount = 0;
	swy = 0;
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, P_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, R_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, G_img); // 画像の分割読み込み

	Eflg = FALSE;
	Eflgcnt = 0;
	Escore1 = LoadGraph("images/Score/GetScore_500.png");
	/*Escore2 = LoadGraph("images/Score/GetScore_750.png");
	Escore3 = LoadGraph("images/Score/GetScore_1000.png");
	Escore4 = LoadGraph("images/Score/GetScore_1500.png");
	Escore5 = LoadGraph("images/Score/GetScore_2000.png");*/
	n_score = 0;
};



Enemy::~Enemy()
{
}

void Enemy::EnemyUpdate(Player P,int& j)
{
	if (++fpscount >= 60)
	{
		EAnimation();
	}

	if (i >= 8 && i< 13) {
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
	Eflgcnt++;
	if (Eflgcnt == 200) {
		c++;
	}
	
	if (Eflgcnt >= 200) {
		Eflgcnt = 0;
	}
	if (c > 1) {
		Eflg = FALSE;
	}
	
}

void Enemy::EnemyDraw() const
{
	//DrawCircle(ELocationX, ELocationY, 4, 0x00ff00, TRUE);
	/*DrawGraph(enemyLocationX, enemyLocationY, img[i], TRUE);*/

	//DrawFormatString(0, 400, 0xffffff, "ElY%f", ELocationY);
	DrawBox(0, 440, 600, 600, 0x00ff00, FALSE);


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
	//DrawFormatString(300, 0, 0xffffff, "Eflg::%d", Eflg);
	//printfDx("%d", Eflg);
	
	//switch (switch_on)
	//{
	//case 0:
	//	break;
	//}
	
	if (c <= 1) {

		if (Eflgcnt <= 100) {
			if (Eflg == TRUE) {
				DrawGraph(ELocationX - 15, ELocationY - 30, Escore1, TRUE);
			}
		}
		
	}
	DrawFormatString(500, 0, 0xffffff, "%06d", n_score);
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

	if (EMoveX > enemy.MaxSpeed) {
		EMoveX = enemy.MaxSpeed;
	}

	if (ELocationX <= P.GetPlayerLocationX()) {
		EMoveX += enemy.MaxSpeed/50;
		Flag = TRUE;

	}
	else if (ELocationX >= P.GetPlayerLocationX()) {
		EMoveX -= enemy.MaxSpeed/50;
		Flag = FALSE;

	}

	if (EMoveX < -enemy.MaxSpeed) {
		EMoveX = -enemy.MaxSpeed;
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
	if (ELocationY <= 25) {
		reboundFlgStageY = TRUE;
	}

	//反発
	 if (reboundFlgStageY == TRUE  ){
		
		 
			reboundFlgStageY = FALSE;
			EMoveY = -1 * EMoveY*10;
	}
	 if (flyingFlg != FALSE) {
			 EMoveY = 0;
			 
		 
		
	 }
	 
	 
		 if (ELocationY <= P.GetPlayerLocationY() && flyingFlg == FALSE) {
			 EMoveY += enemy.MaxSpeed/150;
		 }
		 else if (ELocationY >= P.GetPlayerLocationY()) {
			 EMoveY -= enemy.MaxSpeed/150;
		 }
		 if (EMoveY > enemy.MaxSpeed) {
			 EMoveY = enemy.MaxSpeed;
		 }
		 if (EMoveY < -enemy.MaxSpeed) {
			 EMoveY = -enemy.MaxSpeed;
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
			if (ELocationY+cy>=450)swy += 1;
			break;
		case 2:
			DeadFlg = TRUE;
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
		Eflg = TRUE;
		EdeadCount += 1;
	}

}