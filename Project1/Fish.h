#pragma once
#include<DxLib.h>

class Fish {
private:
	
public:

	/*Player player;
	Enemy enemy;*/

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	void FishUpdate();

	void FishDraw() const;

	int FishProbability();  // サカナの出現確率の関数

	int sakana;
	int FishImg[6];

	int FishX = 320;
	int FishY = 420;
	
};
