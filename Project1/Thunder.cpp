#include"Thunder.h"
#include"DxLib.h"


Thunder::Thunder() 
{
	LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, ThunderImg);
	MoveX = 0.0f;
	MoveY = 0.0f;
	// ����X���W
	ThunderX = 300.0;
	// ����Y���W
	ThunderY = 400.0;
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

		ChangeAngle(/*MoveX,MoveY*/);
	}
	else {
		ThunderX += MoveX;
		ThunderY += MoveY;
	}

	/* �ǁE�V��̔��� */
	if (ThunderX < 16 || ThunderX > 640 - 16) {
		if (ThunderX < 16) {
			ThunderX = 16;
		}
		else {
			ThunderX = 640 - 16;
		}
		ThunderAngle = (1 - ThunderAngle) + 0.5f;
		if (ThunderAngle > 1)ThunderAngle -= 1.0f;
		ChangeAngle(/*MoveX,MoveY*/);
	}

	if (ThunderY < 8) {
		ThunderAngle = (1 - ThunderAngle);
		ChangeAngle(/*MoveX,MoveY*/);
	}
	//if (ThunderY > 480 + 32) { // ������ʉ��ɗ�������
	//	ThunderFlg = 2; // �����X�^�[�g��Ԃɂ���
	//}


	//�f�o�b�O
	//// ����X���W
	//ThunderX = 200;
	//// ����Y���W
	//ThunderY = 350;

}

void Thunder::ThunderDraw() const
{
	DrawRotaGraph(ThunderX, ThunderY, 1.0f, 0, ThunderImg[2], TRUE, FALSE);
	/* �f�o�b�N�p */
	DrawFormatString(400, 130, 0xffffff, "ThunderLocationX::%f", ThunderX);
	DrawFormatString(400, 230, 0xffffff, "ThunderLocationY::%f", ThunderY);
	DrawFormatString(400, 260, 0xffffff, "MoveX::%f", MoveX);
	DrawFormatString(400, 290, 0xffffff, "MoveY::%f", MoveY);

}

void Thunder::ChangeAngle(/*float MoveX,float MoveY*/)
{
	float rad = ThunderAngle * (float)M_PI * 2;
	MoveX = (float)(ThunderSpeed * cosf(rad));
	MoveY = (float)(ThunderSpeed * sinf(rad));
}
