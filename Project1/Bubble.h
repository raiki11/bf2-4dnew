#pragma once
#include"Player.h"
#include"Enemy.h"
class Bubble {
private:
	// �o�u���̉摜�\��
	int BubbleImg[4];

	// �o�u���̔������W
	float BabbleY;

	int flg;//���W����x�����󂯎��p

	//�o�u���̈ړ��p
	float babbleaddX;
	float babbleaddY;


	//�o�u���A�j���[�V�����p
	int count;


	//�o�u���̓����蔻��p

	float Px;//�v���C���[X���W
	float Py;//�v���C���[Y���W
	float Pxy;//�v���C���[�̒��S

	float a,b,c;

	//�����蔻��ł��Ă邩�m�F�p
	int check;//0:�������ĂȂ��@1:���������@2:�X�R�A�\��
	

	int bimgnum;	//�o�u���̉摜�؂�ւ��p
	int bimgcnt;    //�o�u���̉摜�؂�ւ��J�E���g

	float amp;	//�U��
	float fre;	//�p�x

	int BDeleteFlg;	//�V���{���ʃf���[�g�t���O
	int BscoFlg;	//�X�R�A����x�������₷�t���O

	int Bscoimg;	//�X�R�A�摜�\���t���O

public:

	// �R���X�g���N�^
	Bubble();

	// �f�X�g���N�^
	~Bubble();

	// �o�u���̃A�b�v�f�[�g
	void BubbleUpdate(Player p, int ex);

	// �o�u���̕`��
	void BubbleDraw() const;

	int BubbleDelete();
};
