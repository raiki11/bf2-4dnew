#include<time.h>
#include "Fish.h"
#include"DxLib.h"

#define FishAreaX0    160
#define FishAreaX1    480
#define FishAreaY     419

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 11, 5, 2, 64, 64, FishImg);
	Time = 0;
	fpscount = 0;
	i = 0;
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e[])
{
	/* �v���C���[���T�J�i�̉ғ��G���A�ɓ������� */
	if (FishAreaX0 <= p.GetPlayerLocationX() && p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() + 32 && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		if (PFlg == 0) {
			PFlg = 1;
		}
		else {
			PFlg = 0;
		}
		if (++fpscount >= 180) {  // �R�b�ȏソ������
			fpscount = 180;  // ���Z�������Ȃ��悤�ɒl���Œ�
			if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
				PFlg = 2;
				FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
				FishOrientation = Orientation();  // �T�J�i�̌�����`���ۂ̕ϐ��ɓ����
				FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
			}
		}
	}
	else fpscount = 0;  // FPS�̃J�E���g�����Z�b�g����

	if (FishFlg == 1 && PFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		//FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
		/* �A�j���[�V�������� */
		FishUpAnimation();
		/*if (p.GetPlayerLocationX() == FishX && p.GetPlayerLocationY() == FishY) {
			FishHitAnimation();
			
		}*/
		if (i == 2) {
			PFlg = 3;
		}
	}
	
	if (PFlg == 3) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
		//FishY += 2;             // �t�B�b�V�������ɉ�����
		/* �A�j���[�V�������� */
		FishDownAnimation();
		if (i == 5) {
			i = 10;
			PFlg = 0;
			FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
			/*fpscount = 0;*/
		}
	}

	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0 && i == 10) {
		fpscount = 180;
	}
	

	/* �G���T�J�i�̉ғ��G���A�ɓ������� */
	//if (FishAreaX0 <= e.GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= e.GetEnemyLocationY() && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
	//	if (EFlg == 0) {
	//		EFlg = 1;
	//	}
	//	else {
	//		EFlg = 0;
	//	}

	//	if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
	//		/* ���������� */
	//		PFlg = 2;
	//		FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
	//		FishX = e.GetEnemyLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
	//	}
	//	//if (p.GetPlayerLocationX() < FishAreaX0 && FishAreaX1 <  p.GetPlayerLocationX() && FishAreaY > p.GetPlayerLocationY()) {// �v���C���[���T�J�i�͈̔͂��o���Ƃ�
	//	//	FishFlg = 0;
	//	//}
	//	//else {
	//	//	FishFlg = 3;  // �͈͓��ɓ��������A1�񂵂�if���̒��̏�������t�Ȃ��悤�ɐݒ�
	//	//}
	//}
	//if (FishFlg == 1 && PFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
	//	--FishY;             // �t�B�b�V������ɏグ��
	//	if (FishY == 420) {  // �t�B�b�V����Y���W���S�Q�O�ɂȂ�����
	//		FishFlg = 2;     // �t�B�b�V���t���O���T�J�i��������t���O�ɕύX
	//	}
	//}
	//if (FishFlg == 2) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
	//	FishY++;             // �t�B�b�V�������ɉ�����
	//	if (FishY == 500) {  // �t�B�b�V����Y���W���T�O�O�ɂȂ�����
	//		FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
	//		PFlg = 0;
	//	}
	//}
}

void Fish:: FishDraw(Player p) const
{
	DrawRotaGraph(FishX, FishY, 1.0f, 0, FishImg[i], TRUE, FishOrientation);

	/* �f�o�b�N�p */
	DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationY());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
	DrawFormatString(0, 260, 0xffffff, "FishOrientation::%d", FishOrientation);
	DrawFormatString(0, 290, 0xffffff, "flg::%d", fpscount);
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

void Fish::FishUpAnimation()
{
	Time;
	if (i == 10) i = 0;   // �T�J�i���o�ĂȂ��Ƃ�i�����Z�b�g����

	if (i < 2 && ++Time % 15 == 0) {
		i++;
	}
}

void Fish::FishDownAnimation()
{
	
	++Time;

	if (i < 5 && Time % 15 == 0) {
		++i;
	}
}

void Fish::FishHitAnimation()
{
	//switch(/* ���������������������ɏ��� */)
	//	case 0:   // �v���C���[�����������ꍇ
	//		i = 7;
	//		break;
	//	case 1:   // �s���N�̓G�������Ƃ�
	//		i = 8;
	//		break;
	//	case 2:   // �΂̓G�������Ƃ�
	//		i = 9;
	//		break;
	//	case 3:   // ���F�̓G�������Ƃ�
	//		i = 10;
	//		break;
	//	default:  // �N���H���Ȃ������Ƃ�
	//		i = 3;
	//		break;
}

bool Fish::Orientation() {
	// ������������
	srand((unsigned int)time(NULL));

	sakanaOrientation = rand() % 2; // �����̐����i�����F�O�`�P�j

	if (sakanaOrientation == 0) {
		return TRUE;
	}
	else return FALSE;
}