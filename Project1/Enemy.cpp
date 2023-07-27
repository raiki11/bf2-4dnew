#include"DxLib.h"
#include "Enemy.h"
#include "Stage.h"
#include "HitBox.h"

Enemy* hitenemy[6];
HitBox hit;
Stage stage;

int Enemy::DeadFlg = FALSE;
int Enemy::EdeadCount = 0;
int Enemy::Score = 0;

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
	PSpeed = 0;
	Flag = FALSE;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	flyingFlg = FALSE;
	eflg = FALSE;
	aflg = FALSE;
	count = 0;
	




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
	cflg = 0;
	cy = 0;
	cycount = 0;
	swy = 0;
	LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, P_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, R_img); // 画像の分割読み込み
	LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, G_img); // 画像の分割読み込み

	Eflg = FALSE;
	Eflgcnt = 0;
	Escore1 = LoadGraph("images/Score/GetScore_500.png");
	Escore2 = LoadGraph("images/Score/GetScore_750.png");
	Escore3 = LoadGraph("images/Score/GetScore_1000.png");
	Escore4 = LoadGraph("images/Score/GetScore_1500.png");
	Escore5 = LoadGraph("images/Score/GetScore_2000.png");
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

	if (cflg == 1) {
		EPA();
	}
	if (cflg == 2) {
		EDeadAnim();
	}

	if (cflg == 0) {
		if (i >= 8 && i < 13) {
			EnemyMoveX(P);
			EnemyMoveY(P);
		}
	}
	


	/*if (CheckHitKey(KEY_INPUT_A) == TRUE) {
		cflg = TRUE;
	}*/

	
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

	if (cflg == 2) {
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
		DrawFormatString(0, 300, 0xffffff, "Score::%d", Score);
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
	//DrawFormatString(0, 300, 0xffffff, "Score::%d", Score);
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
			Estate = 0;
		}
		if (i >= 8 ) {
			if (eflg == TRUE) {
				if (enemy.type != 2) {
					enemy.type = enemy.type + 1;
					eflg = FALSE;
				}
			}
			++i;
			Estate = 1;
		}
		if (i == 12) {
		i = 8;
		}
	
}

void Enemy::EPA()
{

	EMoveY =PSpeed;
	PSpeed += 0.01f;
	if (EMoveY >= 1.0f) {
		EMoveY = 1.0f;
	}


	//パラシュート
	
	if (cflg == 1) {
		if (i >= 8 && i < 13) {
			i = 13;
		}
		if (++i >= 17) {
			i = 17;
		}
		Estate = 2;
	}

	if (flyingFlg != FALSE) {
		EMoveY = 0;
		i = 0;
		cflg = 0;
		eflg = TRUE;
	}
	
	
	
	ELocationY += EMoveY;
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
			Enemy::EdeadCount += 1;
			DeadFlg = TRUE;
			swy += 1;
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

	
	count++;
	if (Ex<=pxwidth && Exwidth>=px &&Ey<=pywidth && Eywidth>=py) {

		if (count >= 60) {
			aflg = TRUE;
			if (cflg == 0 && i >= 8 && aflg == TRUE) {
				cflg = 1;
				aflg = FALSE;
				EScore();
			}

			if(aflg == TRUE && eflg == TRUE){
				cflg = 2;
				aflg = FALSE;
				EScore();
			}
			count = 0;
		}

		
	
	}
}


int Enemy::EScore()
{
	switch (enemy.type)
	{
	case 0:
		//地面に立ってる時
		if (Estate == 0) {
			Score += 750;
		}
		//風船割る
		else if (Estate == 1) {
			Score += 500;
		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 1000;
		}
		break;
	case 1:
		//地面に立ってる時
		if (Estate == 0) {
			Score += 1000;
		}
		//風船割る
		else if (Estate == 1) {
			Score += 750;
		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 1500;
		}
		break;
	case 2:
		//地面に立ってる時
		if (Estate == 0) {
			Score += 1500;
		}
		//風船割る
		else if (Estate == 1) {
			Score += 1000;
		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 2000;
		}
		break;
	}
	return Score;
}
