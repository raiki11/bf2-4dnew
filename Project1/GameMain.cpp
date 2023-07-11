#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"
#include "Fish.h"

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
		//
	}

	player.PlayerUpdate();
	enemy.EnemyUpdate(player);
	fish.FishUpdate();
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
	else if (hit.PlayerAndStageRight(player, stage) == FALSE) {
		//if (player.GetReboundFlgStageX() == TRUE /*&& player.GetReboundFrameCntX() <= 60*/) {
		//	player.SetReboundFlgStageX(TRUE);
		//}
		//else {
		//	player.SetReboundFlgStageX(FALSE);
		//}
		player.SetReboundFlgStageX(FALSE);
	}


	/*if (160 <= player.PlayerMoveX() <= 480 && 419 <= player.PlayerMoveY() <= 478) {

	}*/
	return this;
}

void GameMain::Draw() const
{
	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
	player.PlayerDraw();
	stage.DrawStage();
	hit.DrawHitBox();
	enemy.EnemyDraw();
	fish.FishDraw();
	DrawFormatString(100, 0, 0xffffff, "%d", a);
}
