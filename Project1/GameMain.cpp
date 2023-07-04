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
	enemy.EnemyUpdate();
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��");
	player.PlayerDraw();
	enemy.EnemyDraw();
}
