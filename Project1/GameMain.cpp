#include "GameMain.h"
#include"DxLib.h"


GameMain::GameMain()
{
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	player.PlayerUpdate();
	enemy.EnemyUpdate(player);
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "ƒQ[ƒ€ƒƒCƒ“");
	player.PlayerDraw();
	enemy.EnemyDraw();
}
