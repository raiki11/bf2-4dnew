#pragma once
#include "AbstractScene.h"

class Fish : public AbstractScene {
private:
	
public:

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	AbstractScene* Update() override;

	void Draw() const override;

	int sakana;
	int FishImg;
};

