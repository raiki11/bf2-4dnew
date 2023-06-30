#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"

GameMain::GameMain()
{
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
	if (PauseFlg = FALSE) {
		//main処理
	}

	// ポーズ中
	if (PauseFlg = TRUE) {
		
	}
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "ゲームメイン");
	//一時停止中の描画
	if (PauseFlg == TRUE)
	{
		
	}
}
