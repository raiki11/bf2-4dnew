#include "Player.h"
#include "PadInput.h"
#define _USE_MATH_DEFINES
#include <math.h>

Player::Player()
{
	playerLocationX = 320;
	playerLocationY = 140;
	playerMoveX = 0;
	playerMoveY = 1.0f;

	fallLimit = 1.0f;

	remainBalloon = 2;

	fps = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
	flyingFlg = 1;
	takeOffFlg = FALSE;
	flapFlg = FALSE;
	flapInterval = 3;

	LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, playerImg);
	playerImgNum = 0;
	playerImgReturnFlg = TRUE;
	playerImgFpsCnt = 0;
	playerImgTakeOffNum = 0;
	playerImgFlyFlg = FALSE;
	interval = 5;
	reboundFlgStageY = FALSE;
	reboundFlgStageX = FALSE;
	reboundFrameCntX = 0;

}

Player::~Player()
{
}

void Player::PlayerUpdate()
{
	
	//飛んでる時の処理
	if (flyingFlg == FALSE) {
		PlayerMoveX();
	}
	//歩いているときの処理
	else if (flyingFlg == TRUE) {
		PlayerMoveX();
		PlayerMoveY();
	}
	
	if (takeOffFlg == TRUE) {
		playerMoveY = -0.5;
		if (PlayerTakeOffAnim() == TRUE) {
			takeOffFlg = FALSE;
			//playerMoveY = 1;
		}
	}
	
	if (flapFlg == TRUE && takeOffFlg == FALSE) {
		if (PlayerFlyAnim() == TRUE) {
			flapFlg = FALSE;
		}
	}

	/***移動制限　ここから***/

	if (playerLocationX > 640) {
		playerLocationX = 0;
	}
	if (playerLocationX < 0) {
		playerLocationX = 640;
	}

	/***移動制限　ここまで***/


	SetRemainBalloon();
	SetFallLimit();
}

void Player::PlayerDraw() const
{
	DrawRotaGraph(playerLocationX, playerLocationY, 1.0f, 0, playerImg[playerImgNum], TRUE, playerImgReturnFlg);
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
	DrawFormatString(0, 40, 0xffffff, "count::%d", count);
	DrawFormatString(0, 55, 0xffffff, "flyButtonFlg::%d", flyButtonFlg);
	DrawFormatString(0, 70, 0xffffff, "moveFpsCountY::%d", moveFpsCountY);
	DrawFormatString(0, 85, 0xffffff, "playerMoveY::%f", playerMoveY);
	/*DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", playerLocationY);*/
	DrawFormatString(0, 100, 0xffffff, "rebound::%d", rebound);
	DrawFormatString(0, 115, 0xffffff, "playerMoveY::%f", playerMoveY);
	DrawFormatString(0, 130, 0xffffff, "playerLocatoinY::%f", playerLocationY);
	DrawFormatString(0, 145, 0xffffff, "flyingflg::%d", flyingFlg);
	DrawFormatString(0, 160, 0xffffff, "reboundflgx::%d", reboundFlgStageX);
	DrawFormatString(0, 175, 0xffffff, "reboundcntx::%d", reboundFrameCntX);
	DrawFormatString(0, 190, 0xffffff, "interval::%d", interval);
	DrawFormatString(0, 205, 0xffffff, "imgnum::%d", playerImgNum);
	DrawFormatString(0, 220, 0xffffff, "takeoff::%d", takeOffFlg);
	
}

void Player::PlayerMoveX()
{
	if (flyingFlg == TRUE) {
		//右移動
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) || PAD_INPUT::GetLStick().x >= 32000) {
			rButtonFlg = TRUE;
			rFlg = TRUE;
			reboundFrameCntX = 0;
			//reboundFlgStageX = FALSE;
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

			//playerLocationX += playerMoveX;
			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				playerMoveX += 0.01f;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
					playerMoveX += 1.0f;
			}
			else if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
				if (interval % 10 == 0) {
					playerMoveX += 1.0f;
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
			//reboundFlgStageX = FALSE;
			playerImgReturnFlg = FALSE;
		}
		else {
			lButtonFlg = FALSE;
		}

		if (lButtonFlg == TRUE) {
			if (playerMoveX > 0) {
				playerMoveX -= 0.01f;
			}

			////playerLocationX += playerMoveX;
			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				playerMoveX -= 0.01f;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
					playerMoveX -= 1.0f;
			}
			else if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
				if (interval % 10 == 0) {
					playerMoveX -= 1.0f;
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

			//playerLocationX += playerMoveX;
		}

		//リバウンド
		if (reboundFlgStageX == TRUE) {
			if (reboundFrameCntX == 0) {
				playerMoveX = -(playerMoveX * 0.8f);
			}
			
			reboundFrameCntX = 1;
			
		}
		else {
			//playerLocationX += playerMoveX;
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
			
		}
		else {
			rButtonFlg = FALSE;
			rFlg = FALSE;
		}

		if (rButtonFlg == TRUE) {
			if (playerMoveX <= 0) {
				playerMoveX += 0.1f;
				/*if (playerMoveX < 0) {
					playerImgNum = 11;
				}*/
			}

			//playerLocationX += playerMoveX;
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

			//playerLocationX += playerMoveX;
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
			
		}

		playerLocationX += playerMoveX;
		playerImgFpsCnt++;

		//飛び立ち
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
			
			flyingFlg = TRUE;
			flyButtonFlg = TRUE;
			playerImgFlyFlg = TRUE;
		
			/*if (rButtonFlg == TRUE || lButtonFlg == TRUE) {
				playerLocationX += playerMoveX + 5;
			}*/

			//playerLocationY -= 15;
			takeOffFlg = TRUE;
			playerImgTakeOffNum = 0;
		}


		/*if (takeOffFlg == TRUE) {
			if (PlayerFlyAnim() == TRUE) {
				takeOffFlg = FALSE;
			}
		}*/
		
	}
}

void Player::PlayerMoveY()
{
	/*if (++playerImgNum > 20 || playerImgNum < 16) {
		playerImgNum = 16;
	}*/


	if (playerLocationY < 25 || reboundFlgStageY == TRUE) {
		playerMoveY = (playerMoveY * 0.8f);
		rebound = 10;
		reboundFlgStageY = TRUE;
		reboundFlgY = TRUE;
		moveFpsCountY = 0;
	}


	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
			flapInterval = 6;
			
		}
		else {
			flapInterval = 4;
		}
		flapFlg = TRUE;
		/*playerImgFpsCnt = 0;*/
		if (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
			flyButtonFlg = TRUE;
			//playerImgFly = 0;
			//playerImgFlyFlg = TRUE;
			playerMoveY = -2;
			
		}

		if (count < 21 && (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A))) {
			count += 3;
			playerMoveY = -2;
		}

		if (playerMoveY != -2) {
			
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
		if (moveFpsCountY++ == 0) {
			//playerMoveY = -1 * playerMoveY;
		}
		if (moveFpsCountY == count/*moveFpsCountY >= rebound*/) {
			reboundFlgY = FALSE;
			playerMoveY = -1 * playerMoveY;
			
			//reboundFlgStageY == TRUE;
			/*playerMoveY = -(playerMoveY);*/
			//moveFpsCountY = 0;
		}
		if (playerMoveY < 1.0f) {
			//playerMoveY += 0.1f;
		}
		reboundFlgStageY == TRUE;
		playerLocationY -= (playerMoveY);
		
	}
	/*else if (reboundFlgStageY == TRUE) {
		playerMoveY = 100;
	}*/
	//重力
	else {
		if (fps % 1 == 0) {
			if (fps % 1 == 0) {
				//if (reboundFlgStageY == TRUE) {
				//	playerMoveY = playerMoveY * 0.8f;
				//	/*if (playerMoveY > -1.0f) {
				//		playerMoveY = -1.0f;
				//	}*/
				//}
				

				if (flyButtonFlg == FALSE) {
					
					if (playerMoveY < fallLimit) {
						playerMoveY += fallLimit / 10;
					}
					if (playerMoveY > fallLimit) {
						playerMoveY = fallLimit;
					}
				}
			}
			
			playerLocationY += playerMoveY;
		}
		
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
			//playerMoveY = 1;
		}
		
		/*if (playerLocationY > 25 && reboundFlgStageY == FALSE) {
			rebound = (count * 0.8f);
			reboundFlgY = TRUE;
			moveFpsCountY = 0;
		}*/
		//playerImgFpsCnt++;
	}


	//if (playerLocationY < 25 && reboundFlgStageY == FALSE) {
	//	rebound = (count * 0.8f);
	//	reboundFlgY = TRUE;
	//	moveFpsCountY = 0;
	//}

	
	//PlayerFlyAnim();

	playerImgFpsCnt++;
}

int Player::PlayerTakeOffAnim()
{
	if (playerImgFlyFlg == TRUE) {
		if (playerImgFpsCnt % 3 == 0) {
			if (remainBalloon == 2) {
				switch (playerImgTakeOffNum)
				{
				case 0:
					if (playerImgNum == 16) {
						playerImgNum = 17;
					}
					else {
						playerImgNum = 18;
					}
					playerImgTakeOffNum = 1;
					break;
				case 1:
					if (playerImgNum == 17) {
						playerImgNum = 18;
					}
					else {
						playerImgNum = 17;
					}
					playerImgTakeOffNum = 2;
					break;
				case 2:
					if (playerImgNum == 18) {
						playerImgNum = 19;
						playerImgTakeOffNum = 3;
						break;
					}
					playerImgNum = 16;
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
					if (playerImgNum == 24) {
						playerImgNum = 25;
					}
					else {
						playerImgNum = 26;
					}
					playerImgTakeOffNum = 1;
					break;
				case 1:
					if (playerImgNum == 25) {
						playerImgNum = 26;
					}
					else {
						playerImgNum = 25;
					}
					playerImgTakeOffNum = 2;
					break;
				case 2:
					if (playerImgNum == 26) {
						playerImgNum = 27;
						playerImgTakeOffNum = 3;
						break;
					}
					playerImgNum = 24;
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

int Player::PlayerFlyAnim()
{

	//playerImgNum = 17;

	/*if (playerImgNum >= 18) {
		playerImgNum = 17;
	}
	else if (playerImgNum == 17) {
		playerImgNum = 16;
	}
	else if (playerImgNum == 16) {
		playerImgNum = 17;
	}*/

	if (playerImgFpsCnt % flapInterval == 0) {
		if (remainBalloon == 2) {
			switch (playerImgNum)
			{
			case 17:
				playerImgNum = 16;
				break;
			case 16:
				playerImgNum = 17;
				playerImgFpsCnt = 0;
				return TRUE;
				break;
			default:
				playerImgNum = 17;
				break;
			}
		}
		else if (remainBalloon == 1) {
			switch (playerImgNum)
			{
			case 25:
				playerImgNum = 24;
				break;
			case 24:
				playerImgNum = 25;
				playerImgFpsCnt = 0;
				return TRUE;
				break;
			default:
				playerImgNum = 25;
				break;
			}
		}
	}
	return FALSE;
	
}

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

int Player::PlayerWalkAnim()
{
	if (playerImgFpsCnt % 5 == 0) {
		if (remainBalloon == 2) {
			if (++playerImgNum > 10 || playerImgNum < 8) {
				playerImgNum = 8;
			}
		}
		else if (remainBalloon == 1) {
			if (++playerImgNum > 14 || playerImgNum < 12) {
				playerImgNum = 12;
			}
		}
	}
	return 0;
}

int Player::PlayerFlyingAnim()
{
	if (playerImgFpsCnt % 30 == 0) {
		if (remainBalloon == 2) {
			if (++playerImgNum > 20 || playerImgNum < 18) {
				playerImgNum = 18;
			}
		}
		else if (remainBalloon == 1) {
			if (++playerImgNum > 28 || playerImgNum < 26) {
				playerImgNum = 26;
			}
		}
	}
	return 0;
}

void Player::SetFallLimit()
{
	if (remainBalloon == 2) {
		fallLimit = 1;
	}
	else if (remainBalloon == 1) {
		fallLimit = 2;
	}
}

void Player::SetRemainBalloon()
{
	if (CheckHitKey(KEY_INPUT_1) == TRUE) {
		remainBalloon = 1;
	}

	if (CheckHitKey(KEY_INPUT_2) == TRUE) {
		remainBalloon = 2;
	}
}
