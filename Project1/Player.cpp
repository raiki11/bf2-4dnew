#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"
#define _USE_MATH_DEFINES
#include <math.h>

Player::Player()
{
	playerLocationX = 320;
	playerLocationY = 140;
	playerMoveX = 0;
	playerMoveY = 0;
	fps = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
	flyingFlg = 1;
	LoadDivGraph("images/Player/Player_Animation.png", 24, 8, 4, 64, 64, playerImg);
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
	if (flyingFlg == TRUE) {
		PlayerMoveY();
		PlayerMoveX();
	}
	//歩いているときの処理
	else if (flyingFlg == FALSE) {
		PlayerMoveX();
	}
	

	/***移動制限　ここから***/

	if (playerLocationX > 640) {
		playerLocationX = 0;
	}
	if (playerLocationX < 0) {
		playerLocationX = 640;
	}

	/***移動制限　ここまで***/
}

void Player::PlayerDraw() const
{
	DrawRotaGraph(playerLocationX, playerLocationY, 1.0f, 0, playerImg[0], TRUE, TRUE);
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
	DrawFormatString(0, 40, 0xffffff, "count::%d", count);
	DrawFormatString(0, 55, 0xffffff, "fps::%d", fps);
	DrawFormatString(0, 70, 0xffffff, "moveFpsCountY::%d", moveFpsCountY);
	DrawFormatString(0, 85, 0xffffff, "playerMoveY::%f", playerMoveY);
	/*DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", playerLocationY);*/
	DrawFormatString(0, 100, 0xffffff, "rebound::%d", rebound);
	DrawFormatString(0, 115, 0xffffff, "playerMoveX::%f", playerMoveX);
	DrawFormatString(0, 130, 0xffffff, "playerLocatoinX::%f", playerLocationX);
	DrawFormatString(0, 145, 0xffffff, "flyingflg::%d", flyingFlg);
	DrawFormatString(0, 160, 0xffffff, "reboundflgx::%d", reboundFlgStageX);
	DrawFormatString(0, 175, 0xffffff, "reboundcntx::%d", reboundFrameCntX);
	
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
		}
		else {
			rButtonFlg = FALSE;
			rFlg = FALSE;
		}

		if (rButtonFlg == TRUE) {
			if (playerMoveX <= 0) {
				playerMoveX += 0.01f;
			}

			//playerLocationX += playerMoveX;
			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				playerMoveX += INERTIA;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
				playerMoveX += 1.0f;
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
		}
		else {
			lButtonFlg = FALSE;
		}

		if (lButtonFlg == TRUE) {
			if (playerMoveX >= 0) {
				playerMoveX -= 0.01f;
			}

			//playerLocationX += playerMoveX;
			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				playerMoveX -= INERTIA;
			}

			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
				playerMoveX -= 1.0f;
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
		if (reboundFlgStageX == TRUE) {
			if (reboundFrameCntX == 0) {
				playerMoveX = -(playerMoveX * 0.8f);
			}
			playerLocationX += playerMoveX;
			reboundFrameCntX = 1;
			
		}
		else {
			playerLocationX += playerMoveX;
		}
		
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
			}

			playerLocationX += playerMoveX;
			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				playerMoveX += INERTIA;
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
			}

			playerLocationX += playerMoveX;
			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				playerMoveX -= INERTIA;
			}


			if (playerMoveX < -3) {
				playerMoveX = -3;
			}
		}

		//立ち止まり
		if (rButtonFlg == FALSE && lButtonFlg == FALSE) {

			if (playerMoveX > -0.1f && playerMoveX < 0.1f) {
				playerMoveX = 0;
			}

			if (playerMoveX > 0) {
				playerMoveX -= 0.1f;
			}
			else if (playerMoveX < 0) {
				playerMoveX += 0.1f;
			}

			playerLocationX += playerMoveX;
		}

		//飛び立ち
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
			flyingFlg = TRUE;
			flyButtonFlg = TRUE;
			playerLocationY -= 10;
		}
	}
}

void Player::PlayerMoveY()
{
	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
		if (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
			flyButtonFlg = TRUE;
		}
		if (count < 21 && (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A))) {
			count += 3;
			playerMoveY = 2;
		}
	}
	//重力と上昇
	if ((flyButtonFlg == TRUE && moveFpsCountY < count) && reboundFlgY == FALSE) {//上昇	  ふわふわ感を出すために10フレーム上がり続ける
		if (playerLocationY > 0 && reboundFlgStageY == FALSE) {
			playerLocationY -= playerMoveY;
			moveFpsCountY++;
			fps = 0;
		}
		else {
			rebound = (count * 0.8f);
			reboundFlgY = TRUE;
			moveFpsCountY = 0;
		}

		interval++;
	}
	//反発
	else if (moveFpsCountY < rebound && reboundFlgY == TRUE) {
		moveFpsCountY++;
		playerLocationY += playerMoveY;
	}
	//重力
	else {
		if (fps % 1 == 0) {
			playerLocationY += 1;
		}
		fps++;
		if (++interval > 10) {
			interval = 0;
		}
		
		flyButtonFlg = FALSE;
		reboundFlgY = FALSE;
		if (moveFpsCountY >= count) {
			moveFpsCountY = 0;
		}

		if (fps >= 10) {
			count = 0;
			moveFpsCountY = 0;
			fps = 0;
			playerMoveY = 0;
		}
	}
}
