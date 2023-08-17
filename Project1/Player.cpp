#include "Player.h"
#include "PadInput.h"
#define _USE_MATH_DEFINES
#include <math.h>

Player::Player()
{
	playerLocationX = 100;
	playerLocationY = 388;
	playerMoveX = 0;
	playerMoveY = 0.0f;

	fallLimit = 1.0f;

	remainBalloon = 2;
	deathFlg = FALSE;
	playerLife = 2;
	splashFlg = FALSE;

	fps = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
	flyingFlg = 1;
	takeOffFlg = FALSE;
	flapFlg = FALSE;
	flapInterval = 3;
	playerNoInputFlg = TRUE;

	LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, playerImg);
	LoadDivGraph("images/Stage/Stage_SplashAnimation.png", 4, 4, 1, 64, 32, splashImg);
	playerImgNum = 0;
	playerImgReturnFlg = TRUE;
	playerImgFpsCnt = 0;
	playerImgTakeOffNum = 0;
	playerImgFlyFlg = FALSE;
	interval = 5;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	reboundFrameCntX = 0;
	playerThunderFlg = FALSE;

	St_Sea = LoadGraph("images/Stage/Stage_Sea01.png");

	splashNum = 99;
	SEsplashFlg = FALSE;

	playerDeathState = -1;

	noInputFps = 0;

	reboundFlgEnemyY = FALSE;
	reboundFlgEnemyX = FALSE;

	seFlg = FALSE;
	fishFlg = FALSE;

	SEplayerjumpFlg = FALSE;
	SEplayerwalkFlg = FALSE;
	SEfallingFlg = FALSE;
}

Player::~Player()
{
	DeleteSoundMem(SEplayerwalk);
	DeleteSoundMem(SEplayerjump);
}

void Player::PlayerUpdate()
{
	noInputFps++;
	if (deathFlg == TRUE) {
		switch (playerDeathState)
		{
		case 0:

			if (PlayerDeathAnim() == TRUE) {
				deathFlg = FALSE;
				playerImgNum = 0;
				playerLocationX = 100;
				playerLocationY = 387;
				playerMoveX = 0;
				playerMoveY = 0.0f;
				remainBalloon = 2;
				splashNum = 99;
				playerLife--;
				playerNoInputFlg = TRUE;
				playerDeathState = -1;
				playerImgReturnFlg = TRUE;
				playerImgFpsCnt = 0;
				noInputFps = 0;
			}
			break;
		case 1:
			if (PlayerThunderDeathAnim() == TRUE) {
				deathFlg = FALSE;
				playerImgNum = 0;
				playerLocationX = 100;
				playerLocationY = 387;
				playerMoveX = 0;
				playerMoveY = 0.0f;
				remainBalloon = 2;
				splashNum = 99;
				playerLife--;
				playerNoInputFlg = TRUE;
				playerDeathState = -1;
				playerImgReturnFlg = TRUE;
				playerImgFpsCnt = 0;
				noInputFps = 0;

			}
			break;
		case 2:
			SEsplashFlg = TRUE;
			if (PlayerSplashAnim() == TRUE) {
				deathFlg = FALSE;
				playerImgNum = 0;
				playerLocationX = 100;
				playerLocationY = 387;
				playerMoveX = 0;
				playerMoveY = 0.0f;
				remainBalloon = 2;
				splashNum = 99;
				playerLife--;
				playerNoInputFlg = TRUE;
				playerDeathState = -1;
				playerImgReturnFlg = TRUE;
				playerImgFpsCnt = 0;
				noInputFps = 0;
				SEsplashFlg = FALSE;
			}
			break;
		case 3:
			playerImgNum = 40;
			if (fishFlg == TRUE) {
				deathFlg = FALSE;
				playerImgNum = 0;
				playerLocationX = 100;
				playerLocationY = 387;
				playerMoveX = 0;
				playerMoveY = 0.0f;
				remainBalloon = 2;
				splashNum = 99;
				playerLife--;
				playerNoInputFlg = TRUE;
				playerDeathState = -1;
				playerImgReturnFlg = TRUE;
				playerImgFpsCnt = 0;
				noInputFps = 0;
				fishFlg = FALSE;
			}
			break;
		}
	}
	else {

		//歩いているときの処理
		if (flyingFlg == FALSE) {
			PlayerMoveX();
			playerMoveY = 0;
		}
		//飛んでる時の処理
		else if (flyingFlg == TRUE) {
			PlayerMoveX();
			PlayerMoveY();
			
		}

		if (takeOffFlg == TRUE) {
			playerMoveY = -0.5;
			if (PlayerTakeOffAnim() == TRUE) {
				takeOffFlg = FALSE;
		
			}
		}

		if (flapFlg == TRUE && takeOffFlg == FALSE) {
			if (PlayerFlyAnim() == TRUE) {
				flapFlg = FALSE;
			}
		}

		//移動制限

		if (playerLocationX > 640) {
			playerLocationX = 0;
		}
		if (playerLocationX < 0) {
			playerLocationX = 640;
		}

		
		//無入力
		if (playerMoveY == 0 && playerMoveX == 0 && playerNoInputFlg == TRUE && noInputFps < 600) {
			PlayerNoInputAnim();
		}
		else if(AnyButtons() == TRUE || noInputFps >= 600) {
			playerNoInputFlg = FALSE;
		}

		SetRemainBalloon();
		SetFallLimit();

		//死亡
		if (remainBalloon == 0 ) {
			playerDeathState = 0;
			deathFlg = TRUE;
		}
		if (playerLocationY > 470) {
			playerDeathState = 2;
			deathFlg = TRUE;
		}
	}
}

void Player::PlayerDraw() const
{
	DrawRotaGraph(playerLocationX, playerLocationY, 1.0f, 0, playerImg[playerImgNum], TRUE, playerImgReturnFlg);
	DrawRotaGraph(playerLocationX, 430, 1.0f, 0, splashImg[splashNum], TRUE, FALSE);
	
}

void Player::PlayerMoveX()
{
	if (flyingFlg == TRUE) {
		//右移動
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) || PAD_INPUT::GetLStick().x >= 32000) {
			rButtonFlg = TRUE;
			rFlg = TRUE;
			reboundFrameCntX = 0;
			playerImgReturnFlg = TRUE;
			
		}
		else {
			rButtonFlg = FALSE;
			rFlg = FALSE;
		}

		if (rButtonFlg == TRUE) {
			if (playerMoveX < 0) {
				playerMoveX += 0.01f;
			}

			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				playerMoveX += 0.01f;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
				playerMoveX += 0.6f;
				
			}
			else if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
				if (interval % 10 == 0) {
					playerMoveX += 0.6f;
				}
			}

			if (playerMoveX > 3) {
				playerMoveX = 3;
			}
		}

		//左移動
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) || PAD_INPUT::GetLStick().x <= -32000) {
			lButtonFlg = TRUE;
			reboundFrameCntX = 0;
			playerImgReturnFlg = FALSE;
		}
		else {
			lButtonFlg = FALSE;
		}

		if (lButtonFlg == TRUE) {
			if (playerMoveX > 0) {
				playerMoveX -= 0.01f;
			}

			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				playerMoveX -= 0.01f;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
					playerMoveX -= 0.6f;
				
			}
			else if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
				if (interval % 10 == 0) {
					playerMoveX -= 0.6f;
					
				}
			}
			
			if (playerMoveX < -3) {
				playerMoveX = -3;
			}
		}

		//立ち止まり
		if (rButtonFlg == FALSE && lButtonFlg == FALSE) {

			if (playerMoveX > -0.0001f && playerMoveX < 0.0001f) {
				playerMoveX = 0;
			}

			if (playerMoveX > 0) {
				playerMoveX -= 0.01f;
			}
			else if (playerMoveX < 0) {
				playerMoveX += 0.01f;
			}

		}

		//リバウンド
		if (reboundFlgStageX == TRUE) {
			if (reboundFrameCntX == 0) {
				playerMoveX = -(playerMoveX * 0.8f);
			}
			
			reboundFrameCntX = 1;
			
		}
	
		
		playerLocationX += playerMoveX;
	}
	else if (flyingFlg == FALSE) {

		reboundFrameCntX = 0;
		reboundFlgStageX = FALSE;
		
		//右移動
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) || PAD_INPUT::GetLStick().x >= 32000) {
			
			rButtonFlg = TRUE;
			rFlg = TRUE;
			SEplayerwalkFlg = TRUE;
		}
		else {
			rButtonFlg = FALSE;
			rFlg = FALSE;
		}

		if (rButtonFlg == TRUE) {
			if (playerMoveX <= 0) {
				playerMoveX += 0.1f;
			}

			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				PlayerWalkAnim();
				playerMoveX += INERTIA;
				playerImgReturnFlg = TRUE;
			}

			if (playerMoveX > 3) {
				playerMoveX = 3;
			}
		}

		//左移動
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) || PAD_INPUT::GetLStick().x <= -32000) {
			
			lButtonFlg = TRUE;
			SEplayerwalkFlg = TRUE;
		}
		else {
			lButtonFlg = FALSE;
		}

		if (lButtonFlg == TRUE) {
			if (playerMoveX >= 0) {
				playerMoveX -= 0.1f;
				if (playerMoveX > 0) {
					playerImgNum = 11;
				}
			}

			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				PlayerWalkAnim();
				playerMoveX -= INERTIA;
				playerImgReturnFlg = FALSE;
			}


			if (playerMoveX < -3) {
				playerMoveX = -3;
			}
		}

		//立ち止まり
		if (rButtonFlg == FALSE && lButtonFlg == FALSE) {

			if (playerImgFlyFlg == FALSE) {
				playerImgFlyFlg = TRUE;
				playerImgFpsCnt = 0;
				playerImgTakeOffNum = 0;
			}


			//慣性あり
			/*if (playerMoveX > -0.1f && playerMoveX < 0.1f) {
				playerMoveX = 0;
			}

			if (playerMoveX > 0) {
				playerMoveX -= 0.1f;
				playerImgNum = 11;
			}
			else if (playerMoveX < 0) {
				playerMoveX += 0.1f;
				playerImgNum = 11;
			}
			else {
				if (playerImgFpsCnt % 30 == 0) {
					if (++playerImgNum > 2) {
						playerImgNum = 0;
					}
				}
			}*/

			//慣性なし
			if (playerMoveX != 0) {
				playerImgFpsCnt = 0;
				playerMoveX = 0;
			}
			PlayerWaitAnim();
			SEplayerwalkFlg = FALSE;
		}

		playerLocationX += playerMoveX;
		playerImgFpsCnt++;

		//飛び立ち
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
			
			flyingFlg = TRUE;
			flyButtonFlg = TRUE;
			playerImgFlyFlg = TRUE;
			
			takeOffFlg = TRUE;
			playerImgTakeOffNum = 0;


			SEplayerjumpFlg = TRUE;

		}
		
	}
}

void Player::PlayerMoveY()
{

	if (playerLocationY < 25 || reboundFlgStageY == TRUE) {
		playerMoveY = (playerMoveY * 0.8f);
		rebound = 10;
		reboundFlgStageY = TRUE;
		reboundFlgY = TRUE;
		moveFpsCountY = 0;
	}


	if (reboundFlgEnemyX == TRUE) {
		playerMoveX = playerMoveX * -1 * 0.8f;
		reboundFlgEnemyX = FALSE;
	}

	if (reboundFlgEnemyY == TRUE) {
		
		if (playerMoveY > 0) {
			playerMoveY *= -1 * 0.8f;
		}
		playerMoveY = -3 * 0.8f;
		reboundFlgEnemyY = FALSE;
	}


	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B) || PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
			
			flapInterval = 6;
			flapFlg = TRUE;
			
		}
		else {
			flapInterval = 4;
			flapFlg = TRUE;
		}


		if (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
			flyButtonFlg = TRUE;
			if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B) && PAD_INPUT::GetOldKey(XINPUT_BUTTON_B) == TRUE) {
				playerMoveY += -0.5f;
			}
			else {
				playerMoveY += -2.0f;
			}
			
			if (playerMoveY < -2) {
				playerMoveY = -2;
			}
			

			SEplayerjumpFlg = TRUE;
		}

		if (count < 21 && (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A))) {
			count += 3;
		}
	}
	else {
		flyButtonFlg = FALSE;
	}

	//重力と上昇
	if ((flyButtonFlg == TRUE && moveFpsCountY < count) && reboundFlgY == FALSE) {//上昇	  ふわふわ感を出すために10フレーム上がり続ける
		if (playerLocationY > 25 && reboundFlgStageY == FALSE) {
			playerLocationY += playerMoveY;
			moveFpsCountY++;
			fps = 0;
			
		}
		else {
			playerMoveY = (playerMoveY * 0.8f);
			reboundFlgY = TRUE;
			moveFpsCountY = 0;
		}

		interval++;
	}
	//反発
	else if (moveFpsCountY < count && reboundFlgY == TRUE) {
		moveFpsCountY++;
		
		if (moveFpsCountY == count) {
			reboundFlgY = FALSE;
			playerMoveY = -1 * playerMoveY;
		
		}
	
		reboundFlgStageY == TRUE;
		playerLocationY -= (playerMoveY);
		
	}
	
	//重力
	else {
	
		if (flyButtonFlg == FALSE) {
					
			if (playerMoveY < fallLimit) {
				playerMoveY += fallLimit / 10;
			}
			if (playerMoveY > fallLimit) {
				playerMoveY = fallLimit;
			}
		}
		
		playerLocationY += playerMoveY;
		
		if (++interval > 10) {
			interval = 0;
		}
		
		flyButtonFlg = FALSE;
		reboundFlgY = FALSE;
		if (moveFpsCountY >= count) {
			moveFpsCountY = 0;
		}

		PlayerFlyingAnim();

		if (++fps > 10) {
			count = 0;
			moveFpsCountY = 0;
			fps = 0;
		}
		
	}


	playerImgFpsCnt++;
}
//飛び立ちアニメーション
int Player::PlayerTakeOffAnim()
{
	if (playerImgFlyFlg == TRUE) {
		if (playerImgFpsCnt % 3 == 0) {
			
			if (remainBalloon == 2) {
				switch (playerImgTakeOffNum)
				{
				case 0:
					if (playerImgNum == 17) {
						playerImgNum = 18;
					}
					else {
						playerImgNum = 19;
					}
					playerImgTakeOffNum = 1;
					break;
				case 1:
					if (playerImgNum == 18) {
						playerImgNum = 19;
					}
					else {
						playerImgNum = 18;
					}
					playerImgTakeOffNum = 2;
					break;
				case 2:
					if (playerImgNum == 19) {
						playerImgNum = 20;
						playerImgTakeOffNum = 3;
						break;
					}
					playerImgNum = 17;
					playerImgTakeOffNum = 0;
					break;
				case 3:

					playerImgFlyFlg = FALSE;
					playerImgTakeOffNum = 0;
					playerImgFpsCnt = 0;
					playerLocationY += playerMoveY;
					return TRUE;
					break;
				}
			}
			else if (remainBalloon == 1) {
				switch (playerImgTakeOffNum)
				{
				case 0:
					if (playerImgNum == 22) {
						playerImgNum = 23;
					}
					else {
						playerImgNum = 24;
					}
					playerImgTakeOffNum = 1;
					break;
				case 1:
					if (playerImgNum == 23) {
						playerImgNum = 24;
					}
					else {
						playerImgNum = 23;
					}
					playerImgTakeOffNum = 2;
					break;
				case 2:
					if (playerImgNum == 24) {
						playerImgNum = 25;
						playerImgTakeOffNum = 3;
						break;
					}
					playerImgNum = 22;
					playerImgTakeOffNum = 0;
					break;
				case 3:

					playerImgFlyFlg = FALSE;
					playerImgTakeOffNum = 0;
					playerImgFpsCnt = 0;
					playerLocationY += playerMoveY;
					return TRUE;
					break;
				}
			}
			
		}
		playerLocationY += playerMoveY;
		return FALSE;
	}
	return FALSE;
}
//羽ばたきアニメーション
int Player::PlayerFlyAnim()
{


	if (playerImgFpsCnt % flapInterval == 0) {
		if (remainBalloon == 2) {
			switch (playerImgNum)
			{
			case 18:
				playerImgNum = 17;
				break;
			case 17:
				playerImgNum = 18;
				playerImgFpsCnt = 0;
				return TRUE;
				break;
			default:
				playerImgNum = 18;
				break;
			}
		}
		else if (remainBalloon == 1) {
			switch (playerImgNum)
			{
			case 24:
				playerImgNum = 23;
				break;
			case 23:
				playerImgNum = 24;
				playerImgFpsCnt = 0;
				return TRUE;
				break;
			default:
				playerImgNum = 24;
				break;
			}
		}
	}
	return FALSE;
	
}
//立ち止まりアニメーション
int Player::PlayerWaitAnim()
{
	if (playerImgFpsCnt % 30 == 0) {
		if (remainBalloon == 2) {
			if (++playerImgNum > 2) {
				playerImgNum = 0;
			}
		}
		else if (remainBalloon == 1) {
			if (playerImgNum < 4) {
				playerImgNum = 4;
			}
			if (++playerImgNum > 6) {
				playerImgNum = 4;
			}
		}
	}

	return 0;
}
//歩きアニメーション
int Player::PlayerWalkAnim()
{
	if (playerImgFpsCnt % 5 == 0) {
		if (remainBalloon == 2) {
			if (++playerImgNum > 10 || playerImgNum < 8) {
				playerImgNum = 8;
			}
		}
		else if (remainBalloon == 1) {
			if (++playerImgNum > 15 || playerImgNum < 13) {
				playerImgNum = 13;
			}
		}
	}
	return 0;
}
//飛んでる時のアニメーション
int Player::PlayerFlyingAnim()
{
	if (playerImgFpsCnt % 30 == 0) {
		if (remainBalloon == 2) {
			if (++playerImgNum > 21 || playerImgNum < 19) {
				playerImgNum = 19;
			}
		}
		else if (remainBalloon == 1) {
			if (++playerImgNum > 24 || playerImgNum < 26) {
				playerImgNum = 24;
			}
		}
	}
	return 0;
}
//死亡時のアニメーション
int Player::PlayerDeathAnim()
{
	if (playerImgNum < 27 || playerImgNum > 30) {
		playerImgNum = 27;
		playerMoveY = -2;
		playerImgFpsCnt = 0;
	}

	if (playerImgFpsCnt++ % 5 == 0) {
		if (++playerImgNum > 29 || playerImgNum < 27) {
			playerImgNum = 27;
		}
	}

	if (playerImgFpsCnt > 10) {
		playerMoveY += 0.1f;
		if (playerMoveY > 5.0f) {
			playerMoveY = 5.0f;
		}
	}

	
	playerLocationY += playerMoveY;

	if (playerLocationY > 450) {
		if (PlayerSplashAnim() == TRUE) {
			return TRUE;
		}
	}

	return 0;
}
//雷で死亡時のアニメーション
int Player::PlayerThunderDeathAnim()
{
	if (playerThunderFlg == FALSE) {
		playerImgFpsCnt = 0;
		playerImgNum = 27;
		playerThunderFlg = TRUE;
	}
	if (playerImgFpsCnt < 60) {
		if (playerImgFpsCnt++ % 3 == 0) {
			if (playerImgNum == 27) {
				playerImgNum = 30;
			}
			else if (playerImgNum == 30) {
				playerImgNum = 27;
			}
		}
	}
	else {
		if (PlayerDeathAnim() == TRUE) {
			playerThunderFlg = FALSE;
			return TRUE;
		}
	}
	return 0;
}
//無入力アニメーション
int Player::PlayerNoInputAnim()
{
	if (remainBalloon == 2) {
		if (playerImgNum != 1 && playerImgNum != 3) {
			playerImgNum = 1;
		}
	}
	else if (remainBalloon == 1) {
		if (playerImgNum != 5 && playerImgNum != 7) {
			playerImgNum = 5;
		}
	}
	if (playerImgFpsCnt % 3 == 0) {
		if (remainBalloon == 2) {
			if (playerImgNum == 1) {
				playerImgNum = 3;
			}
			else if (playerImgNum == 3) {
				playerImgNum = 1;
			}
		}
		else if (remainBalloon == 1) {
			if (playerImgNum == 5) {
				playerImgNum = 7;
			}
			else if (playerImgNum == 7) {
				playerImgNum = 5;
			}
		}

	}

	return 0;
}
//水柱が上がるアニメーション
int Player::PlayerSplashAnim()
{
	if (splashNum == 99) {
		splashNum = 0;
		SEsplashFlg = TRUE;
	}
	if (++playerImgFpsCnt % 5 == 0) {
		if (splashNum++ > 3) {
			
			return TRUE;
		}
	}

	return 0;
}

//落下速度制限
void Player::SetFallLimit()
{
	if (remainBalloon == 2) {
		fallLimit = 1;
	}
	else if (remainBalloon == 1) {
		fallLimit = 1.5f;
	}
}
//バルーンの数設定
void Player::SetRemainBalloon()
{
	if (CheckHitKey(KEY_INPUT_1) == TRUE) {
		remainBalloon = 1;
	}

	if (CheckHitKey(KEY_INPUT_2) == TRUE) {
		remainBalloon = 2;
	}

	if (CheckHitKey(KEY_INPUT_0) == TRUE) {
		remainBalloon = 0;
	}
}
//何かボタンが押されたら
int Player::AnyButtons()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B) || 
		PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) || PAD_INPUT::GetLStick().x >= 32000 || 
		PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) || PAD_INPUT::GetLStick().x <= -32000)
	{
		return 1;
	}
	return 0;
}
//プレイヤー初期化
void Player::InitPlayer()
{
	playerImgNum = 0;
	playerLocationX = 100;
	playerLocationY = 387;
	playerMoveX = 0;
	playerMoveY = 0.0f;

	flyingFlg = 1;
	takeOffFlg = FALSE;
	flapFlg = FALSE;
	flapInterval = 3;
	playerNoInputFlg = TRUE;
	playerImgReturnFlg = TRUE;
}
