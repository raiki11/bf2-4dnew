#include "TitleScene.h"
#include "DxLib.h"
#include "PadInput.h"
#include "GameMain.h"

TitleScene::TitleScene()
{
	titleLogo = LoadGraph("images/Title/Title_Logo.png");
	titleSelectImg = LoadGraph("images/Title/Title_ModeSelect.png");
	titleCredit = LoadGraph("images/Title/Title_Credit.png");
	LoadDivGraph("images/Title/Title_CursorAnimation.png", 4, 4, 1, 32, 64, titleBalloon);

	time = 0;
	num = 0;
	turnNum = 0;

	selectNum = 0;

	//ResetScore();
}

TitleScene::~TitleScene()
{
}

AbstractScene* TitleScene::Update()
{
	if (++time % 20 == 0) {
		
		switch (turnNum)
		{
		case 0:
			num = 0;
			turnNum = 1;
			break;
		case 1:
			if (num == 0) {
				turnNum = 2;
			}
			else if (num == 2) {
				turnNum = 0;
			}
			num = 1;

			break;
		case 2:
			if (num == 1) {
				turnNum = 3;
			}
			else if (num == 3) {
				turnNum = 1;
			}
			num = 2;

			break;
		case 3:
			num = 3;
			turnNum = 2;
			break;
		}
		
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) || PAD_INPUT::GetLStick().y >= 32000) {
		selectNum--;
		if (selectNum < 0) {
			selectNum = 2;
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) || PAD_INPUT::GetLStick().y <= -32000) {
		selectNum++;
		if (selectNum > 2) {
			selectNum = 0;
		}
	}

	if (selectNum == 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return new GameMain();
	}
	Stage::Snum = 0;
	UI::getsco = 0;
	return this;
}

void TitleScene::Draw() const
{
	DrawGraph(50, 20, titleLogo, TRUE);
	DrawGraph(170, 280, titleSelectImg, TRUE);
	DrawRotaGraph(150, 292 + (selectNum * 36), 1.0f, 0, titleBalloon[num], TRUE);
	DrawGraph(170, 430, titleCredit, TRUE);

}
