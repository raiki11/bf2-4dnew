#pragma once
#include<DxLib.h>
#include "AbstractScene.h"

class Fish : public AbstractScene {
private:

public:

	// �R���X�g���N�^
	Fish();

	// �f�X�g���N�^
	~Fish();

	AbstractScene* Update() override;

	void Draw() const override;

	//int FishAppearance(); // �T�J�i�̏o��

	int sakana;
	int FishImg[6];

	
};
