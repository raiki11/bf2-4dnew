#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"
#include "Fish.h"

#include "UI.h"
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
		// PHASE点滅カウント
		UI.Update();
		// ゲームメイン処理
		player.PlayerUpdate();
		enemy.EnemyUpdate(player);
		if (hit.PlayerAndStageUnder(player, stage) == TRUE) {
			player.SetFlyingFlg(FALSE);
		}
		else if (hit.PlayerAndStageUnder(player, stage) == FALSE) {
			player.SetFlyingFlg(TRUE);
		}

		if (hit.PlayerAndStageTop(player, stage) == TRUE) {
			player.SetReboundFlgStageY(TRUE);
		}
		else if (hit.PlayerAndStageTop(player, stage) == FALSE) {
			player.SetReboundFlgStageY(FALSE);
		}

		if (hit.PlayerAndStageRight(player, stage) == TRUE) {
			player.SetReboundFlgStageX(TRUE);
		}
		else if (hit.PlayerAndStageLeft(player, stage) == FALSE) {
			player.SetReboundFlgStageX(FALSE);
		}

		if (hit.PlayerAndStageLeft(player, stage) == TRUE) {
			player.SetReboundFlgStageX(TRUE);
		}
		else if (hit.PlayerAndStageLeft(player, stage) == FALSE) {
			if (player.GetReboundFlgStageX() == TRUE /*&& player.GetReboundFrameCntX() <= 60*/) {
				player.SetReboundFlgStageX(TRUE);
			}
			else {
				player.SetReboundFlgStageX(FALSE);
			}
		}
	}
	return this;
}
void GameMain::Draw() const
{
	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);	// ポーズ中に消したい描画↓
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
	
	player.PlayerDraw();
	enemy.EnemyDraw();
	fish.FishDraw(player);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		// ポーズ中に消したい描画↑
	stage.DrawStage();
	UI.DrawUI();
	hit.DrawHitBox();
	//enemy.EnemyDraw();
	DrawFormatString(100, 0, 0xffffff, "%d", a);
}
