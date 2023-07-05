#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	playerLocationX = 320;
	playerLocationY = 240;
	playerMoveX = 0;
	playerMoveY = 0;
	fps = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
	flyingFlg = 1;
}

Player::~Player()
{
}

void Player::PlayerUpdate()
{
	/***飛んでる時の処理　ここから***/

	if (flyingFlg == TRUE) {

		/***上下の移動　ここから***/

		PlayerMoveY();

		/***上下の移動　ここまで***/


		/***左右の移動　ここから***/

		PlayerMoveX();

		/***左右の移動　ここまで***/

	}

	/***飛んでる時の処理　ここまで***/
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
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
	DrawFormatString(0, 40, 0xffffff, "count::%d", count);
	DrawFormatString(0, 55, 0xffffff, "fps::%d", fps);
	DrawFormatString(0, 70, 0xffffff, "moveFpsCountY::%d", moveFpsCountY);
	DrawFormatString(0, 85, 0xffffff, "playerMoveY::%f", playerMoveY);
	DrawFormatString(0, 100, 0xffffff, "rebound::%d", rebound);
	DrawFormatString(0, 115, 0xffffff, "playerMoveX::%f", playerMoveX);
	DrawFormatString(0, 130, 0xffffff, "playerLocatoinX::%f", playerLocationX);
}

void Player::PlayerMoveX()
{
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
			playerMoveX += 0.01f;
		}

		playerLocationX += playerMoveX;
		if ((playerMoveX > 0) || aButtonFlg == TRUE) {
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
	}
	else {
		lButtonFlg = FALSE;
	}

	if (lButtonFlg == TRUE) {
		if (playerMoveX >= 0) {
			playerMoveX -= 0.01f;
		}

		playerLocationX += playerMoveX;
		if ((playerMoveX < 0 ) || aButtonFlg == TRUE) {
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

		playerLocationX += playerMoveX;
	}
}

void Player::PlayerMoveY()
{
	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
		aButtonFlg = TRUE;
		if (count < 12) {
			count += 3;
			playerMoveY += 1;
		}
	}
	//重力と上昇
	if ((aButtonFlg == TRUE && moveFpsCountY < count) && reboundFlg == FALSE) {//上昇	  ふわふわ感を出すために10フレーム上がり続ける
		if (playerLocationY > 0) {
			playerLocationY -= playerMoveY;
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
		playerLocationY += playerMoveY;
	}
	//重力
	else {
		if (fps % 1 == 0) {
			playerLocationY += 1;
		}
		fps++;
		aButtonFlg = FALSE;
		reboundFlg = FALSE;
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
