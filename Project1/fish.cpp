#include<DxLib.h>
#include<time.h>
#include "fish.h"
Fish::Fish()
{
	FishImg = LoadGraph("../images/Enemy/Enemy_FishAnimation.png");
}

Fish::~Fish()
{

}

AbstractScene* Fish::Update()
{
	// —”‚Ì‰Šú‰»
	srand((unsigned int)time(NULL));

	sakana = rand() % 100;

	return 0;
}

void Fish::Draw() const
{
	if (sakana <= 30) {
		DrawGraph(320, 450, FishImg, TRUE);
	}
}
