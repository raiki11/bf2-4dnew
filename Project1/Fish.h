#pragma once
#include<DxLib.h>
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	int Time;
	int fpscount;
	int i;
	
	int FishFlg;  // 0:�v���C���[���G�l�~�[�������ĂȂ� 1: �T�J�i����ɏオ�� 2: �T�J�i�����ɉ�����
	

public:

	// �R���X�g���N�^
	Fish();

	// �f�X�g���N�^
	~Fish();

	void FishUpdate(Player p, Enemy e[]);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // �v���C���[���T�J�i����яo���G���A�ɗ�����

	int FishProbability();  // �T�J�i�̏o���m���̊֐�
	bool Orientation();  // ���������߂�֐�

	void FishUpAnimation(); // �T�J�i�̏オ��A�j���[�V����
	void FishDownAnimation(); // �T�J�i�̉�����A�j���[�V����
	void FishPlayerHitAnimation(Player p); // �T�J�i�ɓ����������̃A�j���[�V����
	void FishEnemyHitAnimation(Enemy e[]); // �T�J�i�ɓ����������̃A�j���[�V����

	float FishLocationX() { return FishX; }
	float FishLocationY() { return FishY; }

	int FishAnimation() { return i; }

	float FishX = 320;  // �T�J�i��X���W
	float FishY = 420;  // �T�J�i��Y���W

	int sakana;       // �m�����ʂ�����ϐ�
	int FishImg[10];   // �摜������z�� 

	// �v���C���[���T�J�i�G���A�ɓ����Ă��邩�ǂ����̃t���O 
	// 0: �T�J�i�G���A�ɓ����ĂȂ� 1: �T�J�i�G���A�ɓ����� 2: �T�J�i�̏オ��A�j���[�V���� 3: �T�J�i��������A�j���[�V���� 4: �T�J�i�G���A�ɋ������Ă���
	int PFlg;
	int EFlg;      // �G���T�J�i�G���A�ɓ����Ă��邩�ǂ����̃t���O 0: �T�J�i�G���A�ɓ����ĂȂ� 1: �T�J�i�G���A�ɓ����� 2: �T�J�i�̃A�j���[�V�����J�n      
	bool FishOrientation;  // �T�J�i�̌��������߂�
	int sakanaOrientation;  // �T�J�i�̌��������߂闐��
};
