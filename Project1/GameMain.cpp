#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"

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

	player.PlayerUpdate();
	enemy.EnemyUpdate(player);
	return this;
}

void GameMain::Draw() const
{
	if (PauseFlg == FALSE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
}
	stage.DrawStage();
}
