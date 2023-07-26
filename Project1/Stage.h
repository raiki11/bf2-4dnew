#pragma once
#define stagenum 5	//�X�e�[�W�̍ő吔
#define maxcie 20 //�X�e�[�W����擾���邘���̍ő吔
#define blockxy 3
class Stage
{


private:
	int St_Footing;		//���������̉摜
	int St_Footing2;	//2�Ԗڂɒ��������̉摜
	int St_Footing3;	//3�Ԗڂɒ��������̉摜
	int St_FootingT;	//T�^�̕����̉摜
	int St_FootingM;	//��ԏ����������̉摜
	int St_Footing6;	//���F�̕���
	int St_Footing7;	//i���^�̕���
	int St_Footing8;	//i���^�̒�������
	int St_Land_Left;	//���̒n�ʂ̉摜
	int St_Land_Right;	//�E�̒n�ʂ̉摜
	int St_LL;			//���̒��F�n�ʂ̉摜
	int St_LR;			//�E�̒��F�n�ʂ̉摜
	int St_Sea;			//�C�̉摜
	int cloud;			//�_�̉摜
	int stage1;			//�X�e�[�W�̉��摜


	int a;

	int StageXY[stagenum][maxcie][blockxy] = 
	{
		{	//�X�e�[�W�P
			{175,282},//��������
			{455,297},
			{0,419},//�����̒n��
			{160,480},
			{480,419},//�E���̒n��
			{640,480}
		},
		{
			//�X�e�[�W�Q
			{175,282},//��������
			{455,297},
			{100,169},//�E�㕂��
			{222,184},
			{460,152},//���㕂��
			{582,167},
			{0,419},//�����̒n��
			{160,480},
			{480,419},//�E���̒n��
			{640,480}
		},
		{
			//�X�e�[�W�R
			{160,270},//����T������Box
			{221,285},
			{181,285},//����T�����cBox
			{200, 99},
			{242,117},//����������
			{199,333},
			{318,184},//����T������Box
			{379,199},
			{339,199},//����T�����cBox
			{357,247},
			{500, 101},//�E��T������Box
			{561, 116},
			{521, 116},//�E��T�����cBox
			{539, 164},
			{280, 367},//�������̕���
			{361, 383},
			{0,419},//�����̒n��
			{160,480},
			{480,419},//�E���̒n��
			{640,480}
		},
		{
			//�X�e�[�W4
			{120, 267},
			{182, 283},//���[�����\��
			{240, 302},
			{302, 318},//���������\��
			{320, 184},
			{382, 200},//�㑤�����\��
			{360, 368},
			{422, 384},//���������\��
			{460, 287},
			{522, 303},//�E�[�����\��
			{0,419},//�����̒n��
			{160,480},
			{480,419},//�E���̒n��
			{640,480},
		},
		{//�X�e�[�W5
			{201, 332},
			{260, 348},//���F�̕����@�C�ʕt�߂̍�
			{381, 337},
			{440, 353},//���F�̕����@�C�ʕt�߂̉E
			{221, 82},
			{280, 98},//���F�̕����@��
			{101, 202},
			{120, 251},//i���^�������[
			{261, 170},
			{280, 219},//i���^��������
			{501, 152},
			{520, 217},//i���^�̒��������E�[
			{0, 419},
			{160, 480},//�����̒n�ʕ\��
			{480, 419},
			{640, 480},//�E���̒n�ʕ\��
}
	};

	

	//�X�e�[�W���Ƃ̉_�̒��S���W�����̔z����

	//�C�͈̔�
	int Seaxy[2][2] = {
		{160,419},//����
		{480, 478}//x'y'
	};

	/*int cloudxy[2][2] = {
		{200,75},
		{120}
	}*/

public:
	//�R���X�g���N�^
	Stage();
	~Stage();

	void DrawStage() const;
	void Stage1() const;
	void Stage2() const;
	void Stage3() const;
	void Stage4() const;
	void Stage5() const;

	static float EnemyX[stagenum][6];
	static float EnemyY[stagenum][6];
	static float EnemyXY[stagenum][6][6];
	static int EnemyType[stagenum][6];
	static int Snum;	//���̃X�e�[�W
	static int EnemyMax[5];//�X�e�[�W���ƂɌ����G�l�~�[��
	static int MaxCoord[stagenum];  //�X�e�[�W�̍��W�̐�

	int GetStageXY(int snum, int m, int xy)
	{
		return StageXY[snum][m][xy];
	}
};

