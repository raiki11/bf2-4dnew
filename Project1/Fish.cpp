#include<time.h>
#include "Fish.h"
#include"GameMain.h"
Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 6, 6, 1, 64, 64, FishImg);
}

Fish::~Fish()
{

}

AbstractScene* Fish::Update()
{
	// —”‚Ì¶¬
	srand((unsigned int)time(NULL));

	sakana = rand() % 100;

	/*int FishAppearance();*/

	if (sakana >= 70) {
		return new GameMain();
	}

	return this;
}

void Fish::Draw() const
{
	
	if (sakana <= 30) {
		for (int i = 0; i < 6; i++) {
			DrawGraph(320, 419, FishImg[i], TRUE);
		}
	}
}

//int Fish::FishAppearance() {
//	// —”‚Ì¶¬
//	srand((unsigned int)time(NULL));
//
//	sakana = rand() % 100;
//
//	return sakana;
//}
