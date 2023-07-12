#include<time.h>
#include "Fish.h"
#include"GameMain.h"
#include"Enemy.h"

#define FishAreaX0    160;
#define FishAreaX1    480;
#define FishAreaY     419;

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 6, 6, 1, 64, 64, FishImg);
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p)
{
	
	if (160 <= p.GetPlayerLocationX() <= 480 && 419 <= p.GetPlayerLocationY()) { // �v���C���[���T�J�i�͈̔͂ɓ�������
		//if (FishProbability() == TRUE) { // �T�J�i�̊m��
			/* ���������� */
		FishFlg = 1;
		/*}*/
	}
	if (FishFlg == 1) {
		--FishY;
		if (FishY == 200) {
			FishFlg = 2;
		}
	}
	if (FishFlg == 2) {
		FishY++;
		if (FishY == 480) {
			FishFlg = 0;
		}
	}
}

void Fish:: FishDraw(Player p) const
{
	for (int i = 0; i < 6; i++) {
		DrawRotaGraph(FishX, FishY, 1.0, 0, FishImg[i], TRUE, FALSE);
	}
	/* �f�o�b�N�p */
	DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationX());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
}

int Fish::FishProbability() 
{
	// ������������
	srand((unsigned int)time(NULL));

	sakana = rand() % 10 + 1; // �����̐����i�����F�P�`�P�O�j

	if (sakana <= 3) {
		return TRUE;
	}
	else return FALSE;
}
