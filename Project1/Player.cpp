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
	//A�{�^���������ꂽ��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) ) {
		aButtonFlg = TRUE;
	}
	//�d�͂Ə㏸
	if (aButtonFlg == TRUE && fps < 10) {//�㏸	  �ӂ�ӂ튴���o�����߂�10�t���[���オ�葱����
		playerMoveY = -3;
		playerLocationY += playerMoveY;
		fps++;
	}
	else{//�d��
		playerLocationY += 1;
		fps = 0;
		aButtonFlg = FALSE;
	}
	
}

void Player::PlayerDraw() const
{
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
}
