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
		UI.Update(player.GetPlayerLife());
		// ゲームメイン処理
		player.PlayerUpdate();
		enemy.EnemyUpdate(player);
		fish.FishUpdate(player, enemy);
	}

	

	if (hit.PlayerAndStageUnder(player, stage) == TRUE) {
		//if (player.GetTakeOffFlg() == FALSE) {
			player.SetFlyingFlg(FALSE);
		/*}
		else {
			player.SetFlyingFlg(TRUE);
		}*/
	}
	else if (hit.PlayerAndStageUnder(player, stage) == FALSE) {
		if (player.GetFlyingFlg() == FALSE) {
			player.SetPlayerImgFpsCnt(0);
		}
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
	else if (hit.PlayerAndStageRight(player, stage) == FALSE) {
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


	//敵の当たり判定

	if (hit.EnemyAndStageUnder(enemy, stage) == TRUE) {
		enemy.ESetFlyingFlg(TRUE);
	}
	else if (hit.EnemyAndStageUnder(enemy, stage) == FALSE) {
		enemy.ESetFlyingFlg(FALSE);

	}
		
	if (hit.EnemyAndStageTop(enemy, stage) == TRUE) {
		enemy.ESetReboundFlgStageY(TRUE);
	}
	else if (hit.EnemyAndStageTop(enemy, stage) == FALSE) {
		enemy.ESetReboundFlgStageY(FALSE);
	}

	if (hit.EnemyAndStageRight(enemy, stage) == TRUE) {
		enemy.ESetReboundFlgStageX(TRUE);
	}
	else if (hit.EnemyAndStageRight(enemy, stage) == FALSE) {
		enemy.ESetReboundFlgStageX(FALSE);
	}

	if (hit.EnemyAndStageLeft(enemy, stage) == TRUE) {
		enemy.ESetReboundFlgStageX(TRUE);
	}
	else if (hit.EnemyAndStageLeft(enemy, stage) == FALSE) {
		if (enemy.EGetReboundFlgStageX() == TRUE /*&& player.GetReboundFrameCntX() <= 60*/) {
			enemy.ESetReboundFlgStageX(TRUE);
		}
		else {
			enemy.ESetReboundFlgStageX(FALSE);
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
	enemy.EnemyDraw();
	fish.FishDraw(player);
	DrawFormatString(100, 0, 0xffffff, "%d", a);
}
