#include<time.h>
#include "Fish.h"
#include"DxLib.h"
#include"HitBox.h"


//#define FishAreaX0    160
//#define FishAreaX1    480
//#define FishAreaY     419

bool Fish::FyInitFlg = false;

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 11, 5, 2, 64, 64, FishImg);
	Time = 0;
	fpscount = 0;
	i = 10;
	Fishmove=0;
	Fy = 440;
	Fx = 0;
	Fimg = 1;
	count = 0;
	FishFlg = 0;
	PFlg = 0;
	EFlg = 0;
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e)
{
	/* �v���C���[���T�J�i�̉ғ��G���A�ɓ������� */
	if (FishAreaX0 <= p.GetPlayerLocationX() - 16 && p.GetPlayerLocationX() + 16 <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() + 32 && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		if (++fpscount >= 180) {  // �R�b�ȏソ������
			fpscount = 180;  // ���Z�������Ȃ��悤�ɒl���Œ�
			//if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
			//	PFlg = 2;
			//	FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
			//	FishOrientation = Orientation();  // �T�J�i�̌�����`���ۂ̕ϐ��ɓ����
			//	FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
			//}
		}
	}
	else { 
		fpscount = 0; // FPS�̃J�E���g�����Z�b�g����
	}

	if (FishFlg == 1 && PFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		//FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
		/* �A�j���[�V�������� */
		//FishUpAnimation();
		/*if (hb.FishAndPlayer(f, p) == TRUE) {
			FishPlayerHitAnimation(p);
			
		}*/
		if (i == 2 || i == 6) {
			PFlg = 3;
		}
	}
	
	if (PFlg == 3) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����

		/* �A�j���[�V�������� */
		//FishDownAnimation();
		if (i == 5) {
			i = 10;
			/*PFlg = 4;
			FishFlg = 0;*/     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
			/*fpscount = 0;*/
		}
		
	}
	
	/* �v���C���[���T�J�i�G���A�ɋ������鎞�̏��� */
	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0 && i == 10 && PFlg==4) {
		fpscount = 180;
	}


	if (FyInitFlg == true) {
		Fy = 445;
		FyInitFlg = false;
	}

	if (Enemy::GetFishflg() == true) {
		EdeadFish();
	}
	else {
		Fishmove = 0;
	}

	Fx = e.GetEnemyLocationX();

	/* �G���T�J�i�̉ғ��G���A�ɓ������� */
	//if (FishAreaX0 <= e[].GetEnemyLocationX() - 16 && e[].GetEnemyLocationX() + 16 <= FishAreaX1 && FishAreaY <= e[].GetEnemyLocationY() + 32 && FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
	//	if (++fpscount >= 180) {  // �R�b�ȏソ������
	//		fpscount = 180;  // ���Z�������Ȃ��悤�ɒl���Œ�
	//		//if (FishProbability() == TRUE && PFlg == 1) { // �T�J�i�̊m��
	//		//	PFlg = 2;
	//		//	FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
	//		//	FishOrientation = Orientation();  // �T�J�i�̌�����`���ۂ̕ϐ��ɓ����
	//		//	FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
	//		//}
	//	}
	//}
	//else {
	//	fpscount = 0; // FPS�̃J�E���g�����Z�b�g����
	//}

	//if (FishFlg == 1 && EFlg == 2) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
	//	//FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
	//	/* �A�j���[�V�������� */
	//	//FishUpAnimation();
	//	/*if (hb.FishAndPlayer(f, p) == TRUE) {
	//		FishPlayerHitAnimation(p);

	//	}*/
	//	if (i == 2 || i == 6) {
	//		EFlg = 3;
	//	}
	//}

	//if (EFlg == 3) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����

	//	/* �A�j���[�V�������� */
	//	//FishDownAnimation();
	//	if (i == 5) {
	//		i = 10;
	//		/*EFlg = 4;
	//		FishFlg = 0;*/     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
	//		/*fpscount = 0;*/
	//	}

	//}

	///* �v���C���[���T�J�i�G���A�ɋ������鎞�̏��� */
	//if (FishAreaX0 <= e[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= e[].GetEnemyLocationY() && FishFlg == 0 && i == 10 && EFlg == 4) {
	//	fpscount = 180;
	//}
}

void Fish:: FishDraw(Player p) const
{
	DrawRotaGraph(FishX, FishY, 1.0f, 0, FishImg[i], TRUE, FishOrientation);

	/* �f�o�b�N�p */
	//DrawFormatString(400, 200, 0xffffff, "playerLocationX::%f", p.GetPlayerLocationX());
	//DrawFormatString(400, 230, 0xffffff, "fishLocationX::%f", FishX);
	///*DrawFormatString(400, 260, 0xffffff, "FishOrientation::%d", FishOrientation);*/
	//DrawFormatString(400, 290, 0xffffff, "flg::%d", fpscount);
	//DrawFormatString(400, 350, 0xffffff, "Time::%d", Time);
	//DrawFormatString(400, 380, 0xffffff, "i::%d", i);
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
	if (i == 10) {
		i = 0;   // �T�J�i���o�ĂȂ��Ƃ�i�����Z�b�g����
	}

	if (i < 2 && ++Time % 30 == 0) { // �v����
	i++;
	}
}

void Fish::FishDownAnimation()
{
	
	++Time;
	if (i == 6) {
		if (Time % 30 == 0) i = 2;
	}
	if (i < 5 && Time % 30 == 0) { // �v����
		++i;
	}
	if (i == 5) {
		i = 10;
		Time = 0;
	}
	
}

void Fish::FishPlayerHitAnimation(Player p)
{
	i = 6;
}

void Fish::FishEnemyHitAnimation(Enemy enemy[]) {
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

void Fish::EdeadFish() {
	switch (Fishmove) {
	case 0:
		Fy--;
		if (Fy<=420) {
			Fishmove+=1;
		}
		break;
	case 1:
		count++;
		if (count > 20) {
			count = 0;
			Fishmove += 1;
		}
		break;
		case 2:
			Fy++;
			if (Fy>=440) {
				Fishmove +=1;

				count = 0;
			}
			break;
		case 3:
			Fishmove += 1;
			Fy = 440;
			break;
		default:
			break;
	}
}

void Fish::EdeadFishAnim()const{

	DrawRotaGraph(Enemy::EgetFx, Fy, 1.0f, 0, FishImg[Fimg], TRUE, FishOrientation);

}