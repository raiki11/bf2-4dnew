#pragma once
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

	int sakana;
	int FishImg;
};

