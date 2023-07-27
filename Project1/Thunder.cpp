#include"Thunder.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>

Thunder::Thunder() 
{
	LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, ThunderImg);
}

Thunder::~Thunder()
{

}

void Thunder::ThunderUpdate() 
{
	if (ThunderFlg == 2) {
		ThunderFlg = 0;  // ���̏�Ԃ��ړ����ɐݒ肷��
		// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
		ThunderSpeed = 2;
		ThunderAngle = 0.625f;

		ChangeAngle();
	}
	else {
		ThunderX += MoveX;
		ThunderY += MoveY;
	}
	//ThunderFlg = 0;  // ���̏�Ԃ��ړ����ɐݒ肷��
	//// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
	//ThunderSpeed = 1;
	//ThunderAngle = 0.625f;

	//ChangeAngle();

	/* �ǁE�V��̔��� */
	if (ThunderX < 32 || ThunderX > 640 - 32) {
		if (ThunderX < 32) {
			ThunderX = 32;
		}
		else {
			ThunderX = 640 - 32;
		}
		ThunderAngle = (1 - ThunderAngle) + 0.5f;
		if (ThunderAngle > 1)ThunderAngle -= 1.0f;
		ChangeAngle();
	}

	if (ThunderY < 8) {
		ThunderAngle = (1 - ThunderAngle);
		ChangeAngle();
	}
	if (ThunderY > 480 + 32) { // ������ʉ��ɗ�������
		ThunderFlg = 2; // �����X�^�[�g��Ԃɂ���
	}


	//�f�o�b�O
	//// ����X���W
	//ThunderX = 200;
	//// ����Y���W
	//ThunderY = 350;

}

void Thunder::ThunderDraw() const
{
	DrawRotaGraph(ThunderX, ThunderY, 1.0f, 0, ThunderImg[2], TRUE, FALSE);
	DrawFormatString(400, 130, 0xffffff, "ThunderLocationX::%d", ThunderX);
	DrawFormatString(400, 230, 0xffffff, "ThunderLocationY::%d", ThunderY);
}

void Thunder::ChangeAngle()
{
	float rad = ThunderAngle * (float)M_PI * 2;
	MoveX = (int)(ThunderSpeed * cosf(rad));
	MoveY = (int)(ThunderSpeed * sinf(rad));
}
