#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"

GameMain::GameMain()
{
	PauseFlg = FALSE;
	a = 0;
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
		//ゲームメイン処理
		player.PlayerUpdate();
		enemy.EnemyUpdate(player);
		if (hit.PlayerAndStageUnder(player, stage) == TRUE) {
			player.SetFlyingFlg(FALSE);
		}
		else if (hit.PlayerAndStageUnder(player, stage) == FALSE) {
			player.SetFlyingFlg(TRUE);
		}
	}

	
	return this;
}

void GameMain::Draw() const
{
	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
	player.PlayerDraw();
	enemy.EnemyDraw();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	stage.DrawStage();
	UI.DrawUI();
	hit.DrawHitBox();
	
	DrawFormatString(100, 0, 0xffffff, "%d", a);
}
