#pragma once
#define stagenum 5	//�X�e�[�W�̍ő吔
#define maxcie 10 //�X�e�[�W����擾���邘���̍ő吔
#define blockxy 3
class Stage
{


private:
	int St_Footing;		//���������̉摜
	int St_Land_Left;	//���̒n�ʂ̉摜
	int St_Land_Right;	//�E�̒n�ʂ̉摜
	int St_Sea;			//�C�̉摜
	int cloud;			//�_�̉摜
	int stage1;			//�X�e�[�W�̉��摜

	int StageXY[stagenum][maxcie][blockxy] = 
	{
		{	//�X�e�[�W�P
			{175,282},//��������
			{455,297},
			{0,419},//�����̒n��
			{160,480},
			{480,419},//�E���̒n��
			{640,480}
		}/*,
		{
			//�X�e�[�W�Q

		}*/
	};

	//�C�͈̔�
	int Seaxy[2][2] = {
		{160,419},//����
		{480, 478}//x'y'
	};


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
};

