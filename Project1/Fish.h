#pragma once
#include<DxLib.h>

class Fish {
private:
	
public:

	/*Player player;
	Enemy enemy;*/

	// �R���X�g���N�^
	Fish();

	// �f�X�g���N�^
	~Fish();

	void FishUpdate();

	void FishDraw() const;

	int FishProbability();  // �T�J�i�̏o���m���̊֐�

	int sakana;
	int FishImg[6];

	int FishX = 320;
	int FishY = 420;
	
};
