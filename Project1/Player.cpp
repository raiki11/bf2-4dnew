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
	fps = 0;
	count = 0;
	moveFpsCountY = 0;
	rebound = 10000.0f;
	flyingFlg = 1;
	LoadDivGraph("images/Player/Player_Animation.png", 24, 8, 4, 64, 64, playerImg);
	playerImgNum = 0;
	playerImgReturnFlg = TRUE;
	playerImgFpsCnt = 0;
	playerImgFly = 0;
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
	
	//���ł鎞�̏���
	if (flyingFlg == TRUE) {
		PlayerMoveY();
		PlayerMoveX();
	}
	//�����Ă���Ƃ��̏���
	else if (flyingFlg == FALSE) {
		PlayerMoveX();
	}
	

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
	DrawRotaGraph(playerLocationX, playerLocationY, 1.0f, 0, playerImg[playerImgNum], TRUE, playerImgReturnFlg);
	DrawCircle(playerLocationX, playerLocationY, 4, 0xff0000, TRUE);
	DrawFormatString(0, 40, 0xffffff, "count::%d", count);
	DrawFormatString(0, 55, 0xffffff, "moveFpsCountY::%d", moveFpsCountY);
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
	
}

void Player::PlayerMoveX()
{
	if (flyingFlg == TRUE) {
		//�E�ړ�
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
			if (playerMoveX <= 0) {
				playerMoveX += 0.1f;
			}

			//playerLocationX += playerMoveX;
			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				playerMoveX += INERTIA;
			}

			/*if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
				playerMoveX += 1.0f;
			}*/

			if (playerMoveX > 3) {
				playerMoveX = 3;
			}
		}

		//���ړ�
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
			if (playerMoveX >= 0) {
				playerMoveX -= 0.1f;
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

		//�����~�܂�
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

		//���o�E���h
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

		//�E�ړ�
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
				if (playerMoveX < 0) {
					playerImgNum = 11;
				}
			}

			//playerLocationX += playerMoveX;
			if ((playerMoveX > 0) || flyButtonFlg == TRUE) {
				if (playerImgFpsCnt % 5 == 0) {
					if (++playerImgNum > 10 || playerImgNum < 8) {
						playerImgNum = 8;
					}
				}
				playerMoveX += INERTIA;
				playerImgReturnFlg = TRUE;
			}

			if (playerMoveX > 3) {
				playerMoveX = 3;
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
			if (playerMoveX >= 0) {
				playerMoveX -= 0.1f;
				if (playerMoveX > 0) {
					playerImgNum = 11;
				}
			}

			//playerLocationX += playerMoveX;
			if ((playerMoveX < 0) || flyButtonFlg == TRUE) {
				if (playerImgFpsCnt % 5 == 0) {
					if (++playerImgNum > 10 || playerImgNum < 8) {
						playerImgNum = 8;
					}
				}
				playerMoveX -= INERTIA;
				playerImgReturnFlg = FALSE;
			}


			if (playerMoveX < -3) {
				playerMoveX = -3;
			}
		}

		//�����~�܂�
		if (rButtonFlg == FALSE && lButtonFlg == FALSE) {

			if (playerImgFlyFlg == FALSE) {
				playerImgFlyFlg = TRUE;
				playerImgFpsCnt = 0;
				playerImgFly = 0;
			}


			//��������
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

			//�����Ȃ�
			if (playerMoveX != 0) {
				playerImgFpsCnt = 0;
				playerMoveX = 0;
			}
			if (playerImgFpsCnt % 150 == 0) {
				if (++playerImgNum > 2) {
					playerImgNum = 0;
				}
			}
			
		}

		playerLocationX += playerMoveX;
		playerImgFpsCnt++;

		//��ї���
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B) && playerImgFlyFlg == TRUE) {
			
			flyingFlg = TRUE;
			flyButtonFlg = TRUE;
			playerImgFlyFlg = TRUE;
		
			if (rButtonFlg == TRUE || lButtonFlg == TRUE) {
				playerLocationX += playerMoveX + 5;
			}

			playerLocationY -= 15;
			PlayerFlyAnim();
		}
		
	}
}

void Player::PlayerMoveY()
{
	/*if (++playerImgNum > 20 || playerImgNum < 16) {
		playerImgNum = 16;
	}*/
	//A�{�^���������ꂽ��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) || PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) {
		if (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
			flyButtonFlg = TRUE;
			playerImgFly = 0;
			playerImgFlyFlg = TRUE;
		}
		if (count < 21 && (interval % 10 == 0 || PAD_INPUT::OnButton(XINPUT_BUTTON_A))) {
			count += 3;
			playerMoveY = 2;
		}
	}
	//�d�͂Ə㏸
	if ((flyButtonFlg == TRUE && moveFpsCountY < count) && reboundFlgY == FALSE) {//�㏸	  �ӂ�ӂ튴���o�����߂�10�t���[���オ�葱����
		if (playerLocationY > 25 && reboundFlgStageY == FALSE) {
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
	//����
	else if (moveFpsCountY < rebound && reboundFlgY == TRUE) {
		moveFpsCountY++;
		if (moveFpsCountY >= rebound) {
			reboundFlgY = FALSE;
		}
		playerLocationY += (playerMoveY);
	}
	//�d��
	else {
		if (fps % 1 == 0) {
			/*if (playerMoveY < 1.0f) {
				playerMoveY += 0.1f;
			}*/
			//playerMoveY = 1;
			playerLocationY += playerMoveY;
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

		if (playerImgFpsCnt % 30 == 0) {
			if (++playerImgNum > 20 || playerImgNum < 18) {
				playerImgNum = 18;
			}
		}

		if (fps > 10) {
			count = 0;
			moveFpsCountY = 0;
			fps = 0;
			playerMoveY = 1;
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

	PlayerFlyAnim();

	playerImgFpsCnt++;
}

void Player::PlayerFlyAnim()
{
	if (playerImgFlyFlg == TRUE) {
		if (playerImgFpsCnt % 2 == 0) {
			switch (playerImgFly)
			{
			case 0:
				if (playerImgNum == 16) {
					playerImgNum = 17;
				}
				else {
					playerImgNum = 18;
				}
				playerImgFly = 1;
				break;
			case 1:
				if (playerImgNum == 17) {
					playerImgNum = 18;
				}
				else {
					playerImgNum = 17;
				}
				playerImgFly = 2;
				break;
			case 2:
				if (playerImgNum == 18) {
					playerImgFly = 3;
					break;
				}
				playerImgNum = 16;
				playerImgFly = 0;
				break;
			case 3:
				playerImgNum = 19;
				playerImgFlyFlg = FALSE;
				playerImgFly = 0;
				playerImgFpsCnt = 0;
				break;
			}
		}
	}
}
