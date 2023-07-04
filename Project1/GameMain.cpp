#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"

GameMain::GameMain()
{
	PauseFlg = FALSE;
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	//ポーズフラグ切り替え処理
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		PauseFlg = !PauseFlg;

	}
	//ポーズ中でないとき
	if (PauseFlg == FALSE) {
		//
	}

	return this;
}

void GameMain::Draw() const
{
	
	
	//ポーズ中の描画
	if (PauseFlg == TRUE)
	{
		DrawFormatString(0, 0, 0xffffff, "pause");
	}
	else {
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン");
	}
}
