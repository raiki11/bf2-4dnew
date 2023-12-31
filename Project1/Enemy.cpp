#include"DxLib.h"
#include "Enemy.h"
#include "Stage.h"
#include "HitBox.h"
#include "Fish.h"
#include "math.h"
#include "Bubble.h"

Enemy* hitenemy[6];
HitBox hit;
Stage stage;
int Enemy::Eflg = FALSE;
Fish fish;
Bubble bu;

int Enemy::DeadFlg = FALSE;
int Enemy::EdeadCount = -1;
int Enemy::ElastFlg = FALSE;
int Enemy::Score = 0;
bool Enemy::FishFlg = false;
int Enemy::EgetFx = 0;

int Enemy::SE_enemyMove = LoadSoundMem("sounds/SE_EnemyMove.wav");
int Enemy::SE_PA = LoadSoundMem("sounds/SE_parachute.wav");


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
	PSpeedY = 0;
	PSpeedX = 0;
	Flag = FALSE;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	flyingFlg = FALSE;
	eflg = FALSE;
	aflg = FALSE;
	count = 0;
	once = false;
	spc = 0;
	spflg = false;

	ranonce = FALSE;

	f = FALSE;
	EfectFlag = FALSE;
	EfectScore = 0;
	efectcout = 0;
	e = FALSE;
	E_Gflg = 0;
	E_count = 0;
	E_rand = 0;

	Fishprobability = 0;

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
	LoadDivGraph("images/Stage/Stage_SplashAnimation.png", 4, 4, 1, 64, 32, EspAnim);


	Eflgcnt = 0;
	Escore1 = LoadGraph("images/Score/GetScore_500.png");
	Escore2 = LoadGraph("images/Score/GetScore_750.png");
	Escore3 = LoadGraph("images/Score/GetScore_1000.png");
	Escore4 = LoadGraph("images/Score/GetScore_1500.png");
	Escore5 = LoadGraph("images/Score/GetScore_2000.png");

	SE_enemyMove = LoadSoundMem("sounds/SE_EnemyMove.wav");
	SE_PA = LoadSoundMem("sounds/SE_parachute.wav");
	SEonce = false;
	on = FALSE;
};



Enemy::~Enemy()
{
}

void Enemy::EnemyUpdate(Player P,int& j)
{
	ChangeVolumeSoundMem(70, SE_enemyMove);
	ChangeVolumeSoundMem(80, SE_PA);



		if (ranonce == FALSE) {
			Fishprobability = rand() % (100 + 1);
			StopSoundMem(SE_PA);
			PlaySoundMem(SE_enemyMove, DX_PLAYTYPE_LOOP);
			ranonce = TRUE;
			SEonce = false;
		}


	if (++E_count >= 120) {
		E_rand = rand() % 100;
		if (E_rand <= 30) {
			E_Gflg = 1;
		}
		else {
			E_Gflg = 0;
		}
		E_count = 0;
	}
	

	if (++fpscount >= 30)
	{
		EAnimation();
		
	}

	if (cflg == 1) {

		if (SEonce == false) {
			StopSoundMem(SE_enemyMove);
			PlaySoundMem(SE_PA, DX_PLAYTYPE_LOOP);
			SEonce = true;
			ranonce = FALSE;
		}
		EPA();
	}
	if (i>=8 && i < 13 && E_Gflg == 1) {
		i = 9;
	}

	if (cflg == 2) {
		EDeadAnim();
	}

	if (cflg == 0) {
		if (i >= 8 && i < 13) {
			EnemyMoveX(P);
			EnemyMoveY(P);     
			Estate = 1;
		}
			}
	

	/*if (CheckHitKey(KEY_INPUT_A) == TRUE) {
		cflg = TRUE;
	}*/

	//if (cflg == TRUE) {
	//	EDeadAnim();
	//}

	if (spflg == true) {
		EgetFx = ELocationX;
		EsplashAnim();
	}

	//デバッグ用
	if (P.GetPlayerImgNum() < 27) {
		DebagHit(P);
	}
	if (cflg != 2)ECheckY();
	//DebagHit(P);*/
	Eflgcnt++;
	if (Eflgcnt == 200) {
		c++;
	}
	
	if (Eflgcnt >= 200) {
		Eflgcnt = 0;
	}
	if (c > 1) {
		//Eflg = FALSE;
	}
	if (cflg != 0) {
		e = TRUE;
	}
	if (e == TRUE) {
		Efect();
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
		// プレイヤーと敵の風船
		//if (EfectFlag == TRUE&&enemy.type==0) {
		//	DrawGraph(ELocationX - 15, ELocationY - 30, EfectScore, TRUE);
		//	//DrawFormatString(ELocationX, ELocationY, 0xffffff,"%d",EfectScore);
			
		/*}*/
		//if (EfectFlag == TRUE && enemy.type == 1) {

		//	//DrawFormatString(ELocationX, ELocationY, 0xffffff,"%d",EfectScore);
		//	DrawGraph(ELocationX - 15, ELocationY - 30, EfectScore, TRUE);

		//}
		//if (EfectFlag == TRUE && enemy.type == 2) {

		//	//DrawFormatString(ELocationX, ELocationY, 0xffffff,"%d",EfectScore);
		//	DrawGraph(ELocationX - 15, ELocationY - 30, EfectScore, TRUE);

		//}
	// プレイヤーと敵
	
		//デバッグ用
		//DrawFormatString(0, 145, 0xffffff, "enemyLocatoinX::%f", ELocationX);
		//DrawFormatString(0, 160, 0xffffff, "time::%d", time);
		//DrawFormatString(0, 300, 0xffffff, "Score::%d", Score);
		if (reboundFlgStageY == TRUE) {
			//DrawFormatString(0, 205, 0xffffff, "Y:TRUE");
		}
		else {
			//DrawFormatString(0, 205, 0xffffff, "Y:FALSE");
		}
		if (reboundFlgStageX == TRUE) {
			///DrawFormatString(0, 220, 0xffffff, "X:TRUE");
		}
		else {
			//DrawFormatString(0, 220, 0xffffff, "X:FALSE");
		}
	}
	//DrawFormatString(0, 300, 0xffffff, "Score::%d", Score);
	//printfDx("%d", Eflg);
	
	//switch (switch_on)
	//{
	//case 0:
	//	break;
	//}
	
	/*if (c <= 1) {

		if (Eflgcnt <= 100) {
			if (Eflg == TRUE) {
				DrawGraph(ELocationX - 15, ELocationY - 30, Escore1, TRUE);
			}
		}
		
	}*/

	if(spflg == true)DrawGraph(ELocationX - 30, 415, EspAnim[spc], TRUE);

	//DrawFormatString(500, 0, 0xffffff, "%06d", n_score);
	//DrawFormatString(340, 340, 0xffffff, "%d", EdeadCount);
	//DrawFormatString(500, 340, 0xffffff, "E_rand:%d", E_rand);

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

	if (E_Gflg == 0) {

	

	if (ELocationX <= P.GetPlayerLocationX()) {
		EMoveX += enemy.MaxSpeed/50;
		Flag = TRUE;

	}
	else if (ELocationX >= P.GetPlayerLocationX()) {
		EMoveX -= enemy.MaxSpeed/50;
		Flag = FALSE;

	}

	if (E_Gflg == 1) {

		if (EMoveX >= 0) {
			EMoveX -= 0.001f;
		}
		
		if (EMoveX <= 0) {
			EMoveX += 0.001f;
		}
	}

	
	
	}
	if (EMoveX > enemy.MaxSpeed) {
		EMoveX = enemy.MaxSpeed;
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
	 if (flyingFlg == TRUE) {
			 EMoveY = 0;
			 
		 
		
	 }
	 
	 if (E_Gflg == 0) {
		if (ELocationY <= P.GetPlayerLocationY() && flyingFlg == FALSE) {	
			 EMoveY += enemy.MaxSpeed/150;
		 }
		 else if (ELocationY >= P.GetPlayerLocationY()) {
			 EMoveY -= enemy.MaxSpeed/150;
		 }
		
	 
	 }

	 if (ELocationY >= 419&&E_Gflg==1) {
		 E_Gflg = 0;
		 EMoveY = 0;
	 }


	 if (E_Gflg == 1&& flyingFlg == FALSE) {
		 EMoveY = enemy.MaxSpeed;
	 }
		
	 if (EMoveY > 0.8) {
			 EMoveY = 0.8;
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

		if (i >= 8 && E_Gflg == 0) {
			if (eflg == TRUE) {
				if (enemy.type != 2) {
					enemy.type = enemy.type + 1;
					eflg = FALSE;
				}
			}
			++i;
			
		}

	

		if (i == 12) {
		i = 8;
		}
	
}

void Enemy::EPA()
{


	EMoveX = PSpeedX;
	EMoveY =PSpeedY;


	PSpeedY += 0.01f;
	if (EMoveY >= 0.5f) {
		EMoveY = 0.5f;
	}

	if (f == FALSE) {
		PSpeedX += 0.02f;
	}
	else if (f == TRUE) {
		PSpeedX -= 0.02f;
	}

	if (EMoveX >= 0.5f) {
		EMoveX = 0;
		f = TRUE;
	}
	if (EMoveX < -0.5f) {
		EMoveX = 0;
		f = FALSE;
	}

	//パラシュート
	
	if (cflg == 1) {
		if (i >= 8 && i < 13) {
			i = 13;
		}
		if (++i >= 17) {
			i = 17;
		}
		
	}



	if (flyingFlg != FALSE) {
		EMoveY = 0;
		EMoveX = 0;
		i = 0;
		cflg = 0;
		eflg = TRUE;
	}
	
	
	ELocationX += EMoveX;
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
			spflg = true;
			//30%
			if (Fishprobability <= 30) {
				FishFlg = true;
			}
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
	float Ex = ELocationX - 10;
	float Exwidth = ELocationX  + 10;
	float Ey = ELocationY - 30;
	float Eywidth = ELocationY + 30;

	float px = P.GetPlayerLocationX() - 10;
	float pxwidth = px + 25;
	float py = P.GetPlayerLocationY();
	float pywidth = py + 32;

	bool a;
	/*DrawFormatString(500, 20, 0xffffff, "%06f", py);
	DrawFormatString(500, 30, 0xffffff, "%06f", Eywidth);
	ScreenFlip();*/
	count++;
	if (Ex <= pxwidth && Exwidth >= px && Ey <= pywidth && Eywidth >= py) {
		a = true;
	}
	else {
		a = false;
	}
	if (a) {
		
		if (count >= 20) {

			aflg = TRUE;
			if (cflg == 0 && i >= 8 && aflg == TRUE) {
				cflg = 1;
				aflg = FALSE;
				EfectFlag = TRUE;
				
				EScore();
				
			}

			if(aflg == TRUE ){

				if (once == false)
				{
					once = true;

					Enemy::EdeadCount += 1;

				}
				cflg = 2;
				aflg = FALSE;
				EfectFlag = TRUE;
				
				EScore();
				
			}
			count = 0;
		}
	}
}

void Enemy::Efect()
{
	
	if (efectcout++ >= 60) {
			EfectFlag = FALSE;
			efectcout = 0;
			e = FALSE;
		
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
			EfectScore = Escore2;
		
			
		}
		//風船割る
		else if (Estate == 1) {
			Score += 500;
			EfectScore = Escore1;

			

		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 1000;
			EfectScore = Escore3;

			

		}
		break;
	case 1:
		//地面に立ってる時
		if (Estate == 0) {
			Score += 1000;
			EfectScore = Escore3;

			

		}
		//風船割る
		else if (Estate == 1) {
			Score += 750;
			EfectScore = Escore2;

			

		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 1500;
			EfectScore = Escore4;

			

		}
		break;
	case 2:
		//地面に立ってる時
		if (Estate == 0) {
			Score += 1500;
			EfectScore = Escore4;

			

		}
		//風船割る
		else if (Estate == 1) {
			Score += 1000;
			EfectScore = Escore3;

		

		}
		//パラシュート状態の時
		else if (Estate == 2) {
			Score += 2000;
			EfectScore = Escore5;

			

		}
		break;
	}
	return Score;
}

void Enemy::ECheckY() {
	if (ELocationY > 460) {
		spflg = true;
		//DeadFlg = TRUE;
		if (once == false)
		{
			once = true;
			Enemy::EdeadCount += 1;
		}
	}
}

void Enemy::EsplashAnim()
{
	if (++count > 10) {
		spc += 1;
		count = 0;
	}
	if (spc > 4) {
		spc = 0;
		count = 0;
		spflg = false;
		FishFlg = false;
		DeadFlg = TRUE;
	}
}