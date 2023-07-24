#include "TitleScene.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
	titleLogo = LoadGraph("images/Title/Title_Logo.png");
	titleSlectImg = LoadGraph("images/Title/Title_ModeSelect.png");
	titleCredit = LoadGraph("images/Title/Title_Credit.png");
	LoadDivGraph("images/Title/Title_CursorAnimation.png", 4, 4, 1, 32, 64, titleBalloon);

	time = 0;
}

TitleScene::~TitleScene()
{
}

AbstractScene* TitleScene::Update()
{
	return this;
}

void TitleScene::Draw() const
{
	DrawGraph(50, 20, titleLogo, TRUE);
	DrawGraph(170, 280, titleSlectImg, TRUE);

	DrawGraph(170, 430, titleCredit, TRUE);

}
