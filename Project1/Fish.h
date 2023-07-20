#pragma once
#include<DxLib.h>
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	int Time;
	int fpscount;
	int i;
public:

	// �R���X�g���N�^
	Fish();

	// �f�X�g���N�^
	~Fish();

	void FishUpdate(Player p, Enemy e);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // �v���C���[���T�J�i����яo���G���A�ɗ�����

	int FishProbability();  // �T�J�i�̏o���m���̊֐�
	bool Orientation();  // ���������߂�֐�

	void FishUpAnimation(); // �T�J�i�̏オ��A�j���[�V����
	void FishDownAnimation(); // �T�J�i�̉�����A�j���[�V����
	void FishHitAnimation(); // �T�J�i�ɓ����������̃A�j���[�V����

	int sakana;       // �m�����ʂ�����ϐ�
	int FishImg[10];   // �摜������z�� 

	int FishX = 320;  // �T�J�i��X���W
	int FishY = 484;  // �T�J�i��Y���W
	int FishFlg = 0;  // 0:�v���C���[���G�l�~�[�������ĂȂ� 1: �T�J�i����ɏオ�� 2: �T�J�i�����ɉ�����
	int PFlg = 0;      // �v���C���[���T�J�i�G���A�ɓ����Ă��邩�ǂ����̃t���O 0: �T�J�i�G���A�ɓ����ĂȂ� 1: �T�J�i�G���A�ɓ����� 2: �T�J�i�̃A�j���[�V�����J�n
	int EFlg = 0;      // �G���T�J�i�G���A�ɓ����Ă��邩�ǂ����̃t���O 0: �T�J�i�G���A�ɓ����ĂȂ� 1: �T�J�i�G���A�ɓ����� 2: �T�J�i�̃A�j���[�V�����J�n
	bool FishOrientation;  // �T�J�i�̌��������߂�
	int sakanaOrientation;  // �T�J�i�̌��������߂闐��
};
