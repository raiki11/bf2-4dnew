#include<time.h>
#include "Fish.h"
#include"DxLib.h"

#define FishAreaX0    160
#define FishAreaX1    480
#define FishAreaY     419

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 6, 2, 64, 64, FishImg);
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e)
{
	/* �v���C���[���T�J�i�̉ғ��G���A�ɓ������� */
	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		if (PFlg == 0) {
			PFlg = 1;
		}
		else {
			PFlg = 0;
		}
		
		if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
			/* ���������� */
			PFlg = 2;
			FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
			FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
		}
		//if (p.GetPlayerLocationX() < FishAreaX0 && FishAreaX1 <  p.GetPlayerLocationX() && FishAreaY > p.GetPlayerLocationY()) {// �v���C���[���T�J�i�͈̔͂��o���Ƃ�
		//	FishFlg = 0;
		//}
		//else {
		//	FishFlg = 3;  // �͈͓��ɓ��������A1�񂵂�if���̒��̏�������t�Ȃ��悤�ɐݒ�
		//}
	}
	if (FishFlg == 1 && PFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		--FishY;             // �t�B�b�V������ɏグ��
		if (FishY == 420) {  // �t�B�b�V����Y���W���S�Q�O�ɂȂ�����
			FishFlg = 2;     // �t�B�b�V���t���O���T�J�i��������t���O�ɕύX
		}
	}
	if (FishFlg == 2) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
		FishY++;             // �t�B�b�V�������ɉ�����
		if (FishY == 500) {  // �t�B�b�V����Y���W���T�O�O�ɂȂ�����
			FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
			PFlg = 0;
		}
	}

	/* �G���T�J�i�̉ғ��G���A�ɓ������� */
	if (FishAreaX0 <= e.GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= e.GetEnemyLocationY() && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		if (EFlg == 0) {
			EFlg = 1;
		}
		else {
			EFlg = 0;
		}

		if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
			/* ���������� */
			PFlg = 2;
			FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
			FishX = e.GetEnemyLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
		}
		//if (p.GetPlayerLocationX() < FishAreaX0 && FishAreaX1 <  p.GetPlayerLocationX() && FishAreaY > p.GetPlayerLocationY()) {// �v���C���[���T�J�i�͈̔͂��o���Ƃ�
		//	FishFlg = 0;
		//}
		//else {
		//	FishFlg = 3;  // �͈͓��ɓ��������A1�񂵂�if���̒��̏�������t�Ȃ��悤�ɐݒ�
		//}
	}
	if (FishFlg == 1 && PFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		--FishY;             // �t�B�b�V������ɏグ��
		if (FishY == 420) {  // �t�B�b�V����Y���W���S�Q�O�ɂȂ�����
			FishFlg = 2;     // �t�B�b�V���t���O���T�J�i��������t���O�ɕύX
		}
	}
	if (FishFlg == 2) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
		FishY++;             // �t�B�b�V�������ɉ�����
		if (FishY == 500) {  // �t�B�b�V����Y���W���T�O�O�ɂȂ�����
			FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
			PFlg = 0;
		}
	}
}

void Fish:: FishDraw(Player p) const
{
	DrawRotaGraph(FishX, FishY, 1.0, 0, FishImg[2], TRUE, FALSE);

	/* �f�o�b�N�p */
	DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationY());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
	DrawFormatString(0, 260, 0xffffff, "fishflg::%d", FishFlg);
	DrawFormatString(0, 290, 0xffffff, "flg::%d", PFlg);
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

