#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"

#include "UI.h"

Enemy* enemy[6];

GameMain::GameMain()
{
	PauseFlg = FALSE;
	a = 0;

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		enemy[i] = new Enemy(i, i);
	}
}

GameMain::~GameMain()
{
}

AbstractScene* GameMain::Update()
{
	//�|�[�Y�t���O�؂�ւ�����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		PauseFlg = !PauseFlg;

	}
	//�|�[�Y���łȂ��Ƃ�
	if (PauseFlg == FALSE) {
		// PHASE�_�ŃJ�E���g
		UI.Update(player.GetPlayerLife());
		// �Q�[�����C������
		player.PlayerUpdate();
		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
			enemy[i]->EnemyUpdate(player);
		}

		fish.FishUpdate(player, enemy[0]);
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
		if (player.GetDeathFlg() == FALSE) {
			if (player.GetFlyingFlg() == FALSE) {
				player.SetPlayerImgFpsCnt(0);
			}
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

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		//�G�̓����蔻��
		if (hit.EnemyAndStageUnder(*enemy[i], stage) == TRUE) {
			enemy[i]->ESetFlyingFlg(TRUE);
		}
		else if (hit.EnemyAndStageUnder(*enemy[i], stage) == FALSE) {
			enemy[i]->ESetFlyingFlg(FALSE);

		}

		if (hit.EnemyAndStageTop(*enemy[i], stage) == TRUE) {
			enemy[i]->ESetReboundFlgStageY(TRUE);
		}
		else if (hit.EnemyAndStageTop(*enemy[i], stage) == FALSE) {
			enemy[i]->ESetReboundFlgStageY(FALSE);
		}

		if (hit.EnemyAndStageRight(*enemy[i], stage) == TRUE) {
			enemy[i]->ESetReboundFlgStageX(TRUE);
		}
		else if (hit.EnemyAndStageRight(*enemy[i], stage) == FALSE) {
			enemy[i]->ESetReboundFlgStageX(FALSE);
		}

		if (hit.EnemyAndStageLeft(*enemy[i], stage) == TRUE) {
			enemy[i]->ESetReboundFlgStageX(TRUE);
		}
		else if (hit.EnemyAndStageLeft(*enemy[i], stage) == FALSE) {
			if (enemy[i]->EGetReboundFlgStageX() == TRUE /*&& player.GetReboundFrameCntX() <= 60*/) {
				enemy[i]->ESetReboundFlgStageX(TRUE);
			}
			else {
				enemy[i]->ESetReboundFlgStageX(FALSE);
			}
		}
	}
	
	return this;
}


void GameMain::Draw() const
{
	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);	// �|�[�Y���ɏ��������`�恫
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��"); 
	}
	
	player.PlayerDraw();

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {

		//DrawFormatString(200, 300, 0xffffff, "EnemyMax%d", Stage::EnemyMax[Stage::Snum]);
		enemy[i]->EnemyDraw();
	}


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	stage.DrawStage();
	UI.DrawUI();
	hit.DrawHitBox();
	//enemy.EnemyDraw();
	fish.FishDraw(player);
	DrawFormatString(100, 0, 0xffffff, "%d", a);
}
