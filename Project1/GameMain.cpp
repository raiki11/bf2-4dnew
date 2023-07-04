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
<<<<<<< HEAD
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
=======
>>>>>>> parent of b0453aa (繧ｵ繧ｫ繝願ｿｽ蜉)
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "ゲームメイン");
}
