#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	playerLocationX = 320;
	playerLocationY = 240;
	playerMoveX = 0;
	playerMoveY = 1;
	fps = 0;
	speed = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
}

Player::~Player()
{
}

void Player::PlayerUpdate()
{
	/***上下の移動　ここから***/

	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) ) {
		aButtonFlg = TRUE;
		if (count < 12) {
			count += 3;
			speed += 1;
		}
	}
	//重力と上昇
	if ((aButtonFlg == TRUE && moveFpsCountY < count) && reboundFlg == FALSE) {//上昇	  ふわふわ感を出すために10フレーム上がり続ける
		if (playerLocationY > 0) {
			playerMoveY = -(speed);
			playerLocationY += playerMoveY;
			moveFpsCountY++;
			fps = 0;
		}
		else {
			rebound = (count * 0.8f);
			reboundFlg = TRUE;
			moveFpsCountY = 0;
		}
	}
	//反発
	else if (moveFpsCountY < rebound && reboundFlg == TRUE) {
		moveFpsCountY++;
		playerLocationY -= playerMoveY;
	}
	//重力
	else{
		playerLocationY += 1;
		fps++;
		aButtonFlg = FALSE;
		reboundFlg = FALSE;
		if (moveFpsCountY >= count) {
			moveFpsCountY = 0;
		}

		if (fps >= 30) {
			count = 0;
			moveFpsCountY = 0;
			fps = 0;
			speed = 0;
		}
	}
	
	/***上下の移動　ここまで***/


	/***左右の移動　ここから***/

	//右移動
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) || PAD_INPUT::GetLStick().x >= 32000) {
		rButtonFlg = TRUE;
	}
	else {
		rButtonFlg = FALSE;
	}

	if (rButtonFlg == TRUE) {
		if (playerMoveX < 0) {
			playerMoveX += INERTIA;
		}

		playerLocationX += playerMoveX;
		if (playerMoveX < 3) {
			playerMoveX += INERTIA;
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
		if (playerMoveX > 0) {
			playerMoveX -= INERTIA;
		}

		playerLocationX += playerMoveX;
		if (playerMoveX > -3) {
			playerMoveX -= INERTIA;
		}
	}

	//立ち止まり
	if (rButtonFlg == FALSE && lButtonFlg == FALSE) {

		if (playerMoveX > -0.0001f && playerMoveX < 0.0001f) {
			playerMoveX = 0;
		}

		if (playerMoveX > 0) {
			playerMoveX -= INERTIA;
		}
		else if (playerMoveX < 0) {
			playerMoveX += INERTIA;
		}

		playerLocationX += playerMoveX;
	}
	
	/***左右の移動　ここまで***/


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
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
	DrawFormatString(0, 40, 0xffffff, "%d", count);
	DrawFormatString(0, 50, 0xffffff, "%d", fps);
	DrawFormatString(0, 60, 0xffffff, "%d", moveFpsCountY);
	DrawFormatString(0, 70, 0xffffff, "%f", playerMoveY);
	DrawFormatString(0, 80, 0xffffff, "rebound%d", rebound);
}
