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
	//�|�[�Y�t���O�؂�ւ�����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		PauseFlg = !PauseFlg;

	}
	//�|�[�Y���łȂ��Ƃ�
	if (PauseFlg == FALSE) {
		//
	}

	player.PlayerUpdate();
	enemy.EnemyUpdate(player);
=======
>>>>>>> parent of b0453aa (サカナ追加)
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��");
}
