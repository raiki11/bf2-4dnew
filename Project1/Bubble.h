#pragma once
#include"Player.h"
#include"Enemy.h"
class Bubble {
private:
	// �o�u���̉摜�\��
	int BubbleImg[4];

	// �o�u���̔������W
	float BabbleX;
	float BabbleY;

	float babbleaddX;
	float babbleaddY;

	//�o�u���̈ړ��p
	double additionX;
	double additionY;

	double rad;

	//�o�u���A�j���[�V�����p
	int count;
	int flg;//0:X���W�v���X 1:X���W���̂܂܁@2:X���W�}�C�i�X

	//�o�u���̓����蔻��p

	float Px;//�v���C���[X���W
	float Py;//�v���C���[Y���W
	float Pxy;//�v���C���[�̒��S

	float a,b,c;

	int check;//�����蔻��ł��Ă邩�m�F�p

	int bimgnum;	//�o�u���̉摜�؂�ւ��p
	int bimgcnt;    //�o�u���̉摜�؂�ւ��J�E���g

	float amp;	//�U��
	float fre;	//�p�x

	int BDeleteFlg;	//�V���{�����܃f���[�g�t���O

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
