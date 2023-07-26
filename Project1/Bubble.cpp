#include"Bubble.h"
#include"DxLib.h"

Bubble::Bubble() 
{
	LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 4, 4, 1, 32, 32, BubbleImg);
}

Bubble::~Bubble() 
{

}

void Bubble::BabbleUpdate() 
{
	
}

void Bubble::BabbleDraw() const 
{
	DrawRotaGraph(BabbleX, BabbleY, 1.0f, 0, BubbleImg[0], TRUE, FALSE);
}