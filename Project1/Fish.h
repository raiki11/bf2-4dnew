#pragma once
#include<DxLib.h>
//#include"GameMain.h"
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	
public:

	/*Player player;
	Enemy enemy;*/

	// �R���X�g���N�^
	Fish();

	// �f�X�g���N�^
	~Fish();

	void FishUpdate(Player p, Enemy e);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // �v���C���[���T�J�i����яo���G���A�ɗ�����

	int FishProbability();  // �T�J�i�̏o���m���̊֐�

	int sakana;       // �m�����ʂ�����ϐ�
	int FishImg[6];   // �摜������z�� 

	int FishX = 320;  // �T�J�i��X���W
	int FishY = 500;  // �T�J�i��Y���W
	int FishFlg = 0;  // 0:�v���C���[���G�l�~�[�������ĂȂ� 1: �T�J�i����ɏオ�� 2: �T�J�i�����ɉ�����
	int Flg = 0;      // �v���C���[���T�J�i�G���A�ɓ����Ă��邩�ǂ����̃t���O

};
