#pragma once
#include<DxLib.h>
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

	//int FishAppearance(); // サカナの出現

	int sakana;
	int FishImg[6];

	
};
