#include<time.h>
#include "Fish.h"
#include"DxLib.h"

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

void Fish::FishUpdate(Player p , Enemy e)
{
	/* �v���C���[���T�J�i�̉ғ��G���A�ɓ������� */
	if (160 <= p.GetPlayerLocationX() <= 480 && 419 <= p.GetPlayerLocationY() && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		Flg = 1;
		if (FishProbability() == TRUE && Flg == 1) { // �T�J�i�̊m��
			/* ���������� */
		FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
		}
	}
	else {
		Flg = 0;
	}

	if (FishFlg == 1) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		--FishY;             // �t�B�b�V������ɏグ��
		if (FishY == 420) {  // �t�B�b�V����Y���W���S�Q�O�ɂȂ�����
			FishFlg = 2;     // �t�B�b�V���t���O���T�J�i��������t���O�ɕύX
		}
	}
	if (FishFlg == 2) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
		FishY++;             // �t�B�b�V�������ɉ�����
		if (FishY == 500) {  // �t�B�b�V����Y���W���T�O�O�ɂȂ�����
			FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
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

