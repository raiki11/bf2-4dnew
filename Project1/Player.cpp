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
	/***�㉺�̈ړ��@��������***/

	//A�{�^���������ꂽ��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) ) {
		aButtonFlg = TRUE;
		if (count < 12) {
			count += 3;
			speed += 1;
		}
	}
	//�d�͂Ə㏸
	if ((aButtonFlg == TRUE && moveFpsCountY < count) && reboundFlg == FALSE) {//�㏸	  �ӂ�ӂ튴���o�����߂�10�t���[���オ�葱����
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
	//����
	else if (moveFpsCountY < rebound && reboundFlg == TRUE) {
		moveFpsCountY++;
		playerLocationY -= playerMoveY;
	}
	//�d��
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
	
	/***�㉺�̈ړ��@�����܂�***/


	/***���E�̈ړ��@��������***/

	//�E�ړ�
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

	//���ړ�
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

	//�����~�܂�
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
	
	/***���E�̈ړ��@�����܂�***/


	/***�ړ������@��������***/

	if (playerLocationX > 640) {
		playerLocationX = 0;
	}
	if (playerLocationX < 0) {
		playerLocationX = 640;
	}

	/***�ړ������@�����܂�***/
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
