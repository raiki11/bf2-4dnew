#include<time.h>
#include "Fish.h"
#include"GameMain.h"
#include"Player.h"
Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 6, 6, 1, 64, 64, FishImg);
}

Fish::~Fish()
{

}

void Fish::FishUpdate()
{
	
	//if (160 <= player.PlayerMoveX() <= 480 && 419 <= player.PlayerMoveY() <= 478) { // �v���C���[���T�J�i�͈̔͂ɓ�������
	//	if (FishProbability() == TRUE) { // �T�J�i�̊m��
	//		/* ���������� */
	//	}
	//}

}

void Fish:: FishDraw() const
{
	/*if (sakana <= 30) {*/
	for (int i = 0; i < 6; i++) {
		DrawRotaGraph(FishX, FishY, 1.0, 0, FishImg[i], TRUE, FALSE);
	}
	/*}*/
}

int Fish::FishProbability() 
{
	// �����̐���
	srand((unsigned int)time(NULL));

	sakana = rand() % 100;

	if (sakana <= 30) {
		return TRUE;
	}
	else return FALSE;
}
