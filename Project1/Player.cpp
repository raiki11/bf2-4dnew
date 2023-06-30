#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	playerLocationX = 320;
	playerLocationY = 240;
	playerMoveX = 1;
	playerMoveY = 1;
	fps = 0;
}

Player::~Player()
{
}

void Player::PlayerUpdate()
{
	//Aボタンが押されたか
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) ) {
		aButtonFlg = TRUE;
	}
	//重力と上昇
	if (aButtonFlg == TRUE && fps < 10) {//上昇	  ふわふわ感を出すために10フレーム上がり続ける
		playerMoveY = -3;
		playerLocationY += playerMoveY;
		fps++;
	}
	else{//重力
		playerLocationY += 1;
		fps = 0;
		aButtonFlg = FALSE;
	}
	
}

void Player::PlayerDraw() const
{
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
}
