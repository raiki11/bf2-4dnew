#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"
#include "Player.h"
#include "End.h"
#include "UI.h"
#include "End.h"

Enemy* enemy[6];

GameMain::GameMain()
{
	PauseFlg = FALSE;
	ClearFlg = FALSE;
	Elast = -1;
	a = 0;
	count = 0;
	OldSnum = Stage::Snum;
	fishi = 0;

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		enemy[i] = new Enemy(i, i);
	}

	for (int i = 0; i < 20; i++) {
		reboundFlg[i] = { FALSE };
	}
	
	reboundPflg = FALSE;
	playerAndFishFlg = FALSE;
	

	o	= 0;
	//BGM�̓ǂݍ���
	(BGM = LoadSoundMem("sounds/BGM_Trip.wav"));

	//BGM�̉��ʕύX
	ChangeVolumeSoundMem(70, BGM);

	//SE�̓ǂݍ���
	(Start_SE = LoadSoundMem("sounds/SE_Start.wav"));
	ChangeVolumeSoundMem(70,Start_SE);

	(SE_playerjump = LoadSoundMem("sounds/SE_Playerjump.wav"));
	SE_playerwalk = LoadSoundMem("sounds/SE_PlayerWalk.wav");
	ChangeVolumeSoundMem(70, SE_playerwalk);
	ChangeVolumeSoundMem(70, SE_playerjump);

	SE_splash = LoadSoundMem("sounds/SE_Splash.wav");
	ChangeVolumeSoundMem(70, SE_splash);

	SE_crack = LoadSoundMem("sounds/SE_crack.wav");
	ChangeVolumeSoundMem(70, SE_crack);

	SE_falling = LoadSoundMem("sounds/SE_Falling.wav");
	ChangeVolumeSoundMem(70, SE_falling);
}

GameMain::~GameMain()
{
	//BGM�̍폜
	DeleteSoundMem(BGM);
	DeleteSoundMem(Start_SE);
}

AbstractScene* GameMain::Update()
{
	
	//BGM�̍Đ�
	if (CheckSoundMem(Start_SE) == 0)
	{

		PlaySoundMem(Start_SE, DX_PLAYTYPE_BACK, TRUE);

		//StopSoundMem(BGM);
		//PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE);
		o++;
	}

	if (o > 1) {
		StopSoundMem(Start_SE);
		if (CheckSoundMem(BGM) == 0)
		{
			PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, TRUE);
		}
	}

	
	//�|�[�Y�t���O�؂�ւ�����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		//PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);
		PauseFlg = !PauseFlg;

	}
	//�|�[�Y���łȂ��Ƃ�
	if (PauseFlg == FALSE) {
		if (ClearFlg == FALSE) {
			// PHASE�_�ŃJ�E���g			
			UI.Update(player.GetPlayerLife());
			// �Q�[�����C������
			player.PlayerUpdate();
			if (player.GetSEWalk() == TRUE)
			{
				if (CheckSoundMem(SE_playerwalk) == 0)
				{
					PlaySoundMem(SE_playerwalk, DX_PLAYTYPE_BACK, TRUE);
					player.SetSEWalk(FALSE);
				}
			}
			else {
				StopSoundMem(SE_playerwalk);
			}

			if (player.GetSEJump() == TRUE)
			{
				if (CheckSoundMem(SE_playerjump) == 0)
				{
					PlaySoundMem(SE_playerjump, DX_PLAYTYPE_BACK, TRUE);
					player.SetSEJump(FALSE);
				}
			}

			if (player.GetplayerDeathState() >= 0 && player.GetplayerDeathState() <= 1)
			{
				if (CheckSoundMem(SE_falling) == 0 && CheckSoundMem(SE_splash) == 0)
				{
					PlaySoundMem(SE_falling, DX_PLAYTYPE_BACK, TRUE);
				}
			}



			if (player.GetSESplash() == TRUE)
			{
				StopSoundMem(SE_falling);
				if (CheckSoundMem(SE_splash) == 0)
				{
					PlaySoundMem(SE_splash, DX_PLAYTYPE_BACK, TRUE);
					player.SetSplash(FALSE);
				}
			}
			
		

			//�G�l�~�[�A�b�v�f�[�g
			for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
				if (enemy[i] != nullptr) {
					enemy[i]->EnemyUpdate(player, i);
					fishi = i;
				}
				//�G�l�~�[��|������
				if (Enemy::EdeadCount == Stage::EnemyMax[Stage::Snum]) {
					if (++count > 15) {
						ClearFlg = TRUE;
						Enemy::EdeadCount = -1;
						Elast = i;
						Enemy::DeadFlg = FALSE;
						
						//enemy[i] = nullptr;
					}

				}
				if (Enemy::DeadFlg == TRUE) {
					enemy[i] = nullptr;
					Enemy::DeadFlg = FALSE;
					
				}


			}
			for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
				if (enemy[i] != nullptr) {
					fish.FishUpdate(player, *enemy[i]);
				}
			}
			thunder.ThunderUpdate();
			bubble.BabbleUpdate();
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
			if (enemy[i] != nullptr) {

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
		}


		//�v���C���[�ƓG
		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
			if (enemy[i] != nullptr) {
				if (player.GetPlayerImgNum() >= 0 && player.GetPlayerImgNum() <= 26) {
					if (enemy[i]->GetI() >= 8 && enemy[i]->GetI() <= 12) {
						if (hit.PlayerAndEnemy(player, *enemy[i]) == TRUE) {
							player.SetReboundEnemyX(TRUE);
							enemy[i]->ESetReboundFlgStageX(TRUE);
						
						}

						else if (player.GetRemainBalloon() > 0) {
							if (hit.PlayerBalloonAndEnemy(player, *enemy[i]) == TRUE && reboundPflg == FALSE) {
								if (player.GetNoInputFlg() == FALSE) {
									player.SubtractRemainBalloon();
				
									if (CheckSoundMem(SE_crack) == 0)
									{
										PlaySoundMem(SE_crack, DX_PLAYTYPE_BACK, TRUE);
									}
							
								}
								player.SetReboundEnemyX(TRUE);
								player.SetReboundEnemyY(TRUE);
								player.SetPlayerImgFpsCnt(0);
								enemy[i]->ESetReboundFlgStageX(TRUE);
								enemy[i]->ESetReboundFlgStageY(TRUE);
								reboundPflg = TRUE;
							}
							else {
								reboundPflg = FALSE;
							}
						}

					}
					if (enemy[i]->GetI() >= 8 && enemy[i]->GetI() <= 17) {
						
						if (hit.PlayerAndEnemyBalloon(player, *enemy[i]) == TRUE && reboundFlg[i] == FALSE) {
							//player.SubtractRemainBalloon();
							
							//player.SetReboundFlgStageX(TRUE);
							//player.SetReboundFlgStageY(TRUE);
							//player.SetPlayerMoveY();
							
							PlaySoundMem(SE_crack, DX_PLAYTYPE_BACK, TRUE);
							
							player.SetReboundEnemyX(TRUE);
							player.SetReboundEnemyY(TRUE);
							/*player.SetPlayerLocationX();
							player.SetPlayerLocationY();*/
							//player.SetReboundEnemyY(TRUE);

							reboundFlg[i] = TRUE;
						}
						else {
							reboundFlg[i] = FALSE;
						}
					}
				}
			}
		}

		//�G�ƓG
		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
			if (enemy[i] != nullptr) {
				for (int j = i + 1; j <= Stage::EnemyMax[Stage::Snum]; j++) {
					if (enemy[j] != nullptr) {
						if (hit.EnemyAndEnemy(*enemy[i], *enemy[j]) == TRUE) {
							if (enemy[i]->GetEnemyLocationX() < enemy[j]->GetEnemyLocationX()) {
								enemy[j]->ESetReboundFlgStageX(TRUE);
							}
							else {
								enemy[i]->ESetReboundFlgStageX(TRUE);
							}


							if (enemy[i]->GetEnemyLocationY() > enemy[j]->GetEnemyLocationY()) {
								enemy[j]->ESetReboundFlgStageY(TRUE);
							}
							else {
								enemy[i]->ESetReboundFlgStageY(TRUE);
							}
							//enemy[i]->ESetReboundFlgStageY(TRUE);


							//enemy[i]->ESetReboundFlgStageY(TRUE);
						}
					}
				}
			}
		}


		//�v���C���[�Ɨ�
		if (hit.PlayerAndThunder(player, thunder) == TRUE) {
			if (player.GetDeathFlg() == FALSE) {
				player.SetPlayerDeathFlg(TRUE);
				player.SetPlayerDeathFState(1);
			}
		}
		b = hit.ThunderAndStageLeft(thunder, stage);
		// �X�e�[�W�Ɠ����蔻��
		if (hit.ThunderAndStageLeft(thunder, stage) == TRUE) {
			thunder.ChangeAngle(/*thunder.GetThunderMoveLocationX(),thunder.GetThunderMoveLocationY()*/);
		}
		if (hit.ThunderAndStageRight(thunder, stage) == TRUE) {
			thunder.ChangeAngle(/*thunder.GetThunderMoveLocationX(), thunder.GetThunderMoveLocationY()*/);
		}
		if (hit.ThunderAndStageUnder(thunder, stage) == TRUE) {
			thunder.ChangeAngle(/*thunder.GetThunderMoveLocationX(), thunder.GetThunderMoveLocationY()*/);
		}
		if (hit.ThunderAndStageTop(thunder, stage) == TRUE) {
			thunder.ChangeAngle(/*thunder.GetThunderMoveLocationX(), thunder.GetThunderMoveLocationY()*/);
		}
	}
	//���̃X�e�[�W�̓G����
	//if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
	//	if (Stage::Snum >= 4) { Stage::Snum = 0; }
	//		Stage::Snum += 1;
	//	if (OldSnum != Stage::Snum) {
	//		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
	//			enemy[i] = new Enemy(i, i);
	//		}
	//	}
	//}
		

	/* ���ƃv���C���[�̓����蔻�� */

	/* �v���C���[���T�J�i�̉ғ��G���A�ɓ������� */
	if (FishAreaX0 <= player.GetPlayerLocationX() && player.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= player.GetPlayerLocationY() + 32 && fish.FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
		if (fish.PFlg == 0) {
			fish.PFlg = 1;
		}
		else {
			fish.PFlg = 0;
		}
		if (fish.FPSCount() >= 180) {  // �R�b�ȏソ������
			fish.FPSCount();  // ���Z�������Ȃ��悤�ɒl���Œ�

			if (fish.FishProbability() == TRUE && fish.PFlg == 1) { // �T�J�i�̊m��
				fish.PFlg = 2;
				fish.FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
				fish.FishOrientation = fish.Orientation();  // �T�J�i�̌�����`���ۂ̕ϐ��ɓ����
				fish.FishX = player.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
			}
		}
	}
	else fish.FPSCount();  // FPS�̃J�E���g�����Z�b�g����

	if (fish.FishFlg == 1 && fish.PFlg == 2 || fish.PFlg == 5) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
		//FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
		/* �A�j���[�V�������� */
		fish.FishUpAnimation();
		if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1 /*|| fish.FishAnimation() == 2*/) {
			fish.FishPlayerHitAnimation(player);
			/*player.SetPlayerDeathFlg(TRUE);
			player.SetPlayerDeathFState(1);*/
			fish.PFlg = 5;

			player.SetPlayerDeathFlg(TRUE);
			player.SetPlayerDeathFState(3);
			playerAndFishFlg = TRUE;
		}
		if (fish.FishAnimation() == 2 || fish.FishAnimation() == 6 || fish.PFlg == 5) {
			fish.PFlg = 3;
		}
	}

	if (fish.PFlg == 3) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
		//FishY += 2;             // �t�B�b�V�������ɉ�����
		/* �A�j���[�V�������� */
		fish.FishDownAnimation();
		if (fish.FishAnimation() == 10) {
			fish.FishAnimation();  // i == 10
			fish.PFlg = 4;
			fish.FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
			/*fpscount = 0;*/
			if (playerAndFishFlg == TRUE) {
				player.SetFishFlg(TRUE);
				playerAndFishFlg = FALSE;
			}
		}

	}

	/* �v���C���[���T�J�i�G���A�ɋ������鎞�̏��� */
	if (FishAreaX0 <= player.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= player.GetPlayerLocationY() && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.PFlg == 4) {
		fish.FPSCount();
	}

	/* ���ƓG�̓����蔻�� */
	/* �G���T�J�i�̉ғ��G���A�ɓ������� */
	//if (FishAreaX0 <= *enemy[].GetEnemyLocationX() && enemy[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= enemy[].GetEnemyLocationY() + 32 && fish.FishFlg == 0) {// �v���C���[���T�J�i�͈̔͂ɓ�������
	//	if (fish.EFlg == 0) {
	//		fish.EFlg = 1;
	//	}
	//	else {
	//		fish.EFlg = 0;
	//	}
	//	if (fish.FPSCount() >= 180) {  // �R�b�ȏソ������
	//		fish.FPSCount();  // ���Z�������Ȃ��悤�ɒl���Œ�

	//		if (fish.FishProbability() == TRUE && fish.EFlg == 1) { // �T�J�i�̊m��
	//			fish.EFlg = 2;
	//			fish.FishFlg = 1;         // �t�B�b�V���t���O���T�J�i���オ��t���O�ɕύX
	//			fish.FishOrientation = fish.Orientation();  // �T�J�i�̌�����`���ۂ̕ϐ��ɓ����
	//			fish.FishX = player.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
	//		}
	//	}
	//}
	//else fish.FPSCount();  // FPS�̃J�E���g�����Z�b�g����

	//if (fish.FishFlg == 1 && fish.EFlg == 2 || fish.EFlg == 5) {      // �t�B�b�V���t���O���T�J�i���グ��t���O�ɂȂ�����
	//	//FishX = p.GetPlayerLocationX(); // �v���C���[������X���W�ɃT�J�i���o��������
	//	/* �A�j���[�V�������� */
	//	fish.FishUpAnimation();
	//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1 /*|| fish.FishAnimation() == 2*/) {
	//		fish.FishPlayerHitAnimation(player);
	//		/*player.SetPlayerDeathFlg(TRUE);
	//		player.SetPlayerDeathFState(1);*/
	//		fish.EFlg = 5;
	//	}
	//	/*if (hb.FishAndPlayer(f, p) == TRUE) {
	//		FishPlayerHitAnimation(p);

	//	}*/
	//	if (fish.FishAnimation() == 2 || fish.FishAnimation() == 6 || fish.EFlg == 5) {
	//		fish.EFlg = 3;
	//	}
	//}

	//if (fish.EFlg == 3) {      // �t�B�b�V���t���O���T�J�i��������t���O�ɂȂ�����
	//	//FishY += 2;             // �t�B�b�V�������ɉ�����
	//	/* �A�j���[�V�������� */
	//	fish.FishDownAnimation();
	//	if (fish.FishAnimation() == 10) {
	//		fish.FishAnimation();  // i == 10
	//		fish.EFlg = 4;
	//		fish.FishFlg = 0;     // �t�B�b�V���t���O���v���C���[��G�l�~�[�������Ă��Ȃ���Ԃɂ���B
	//		/*fpscount = 0;*/
	//	}

	//}

	///* �v���C���[���T�J�i�G���A�ɋ������鎞�̏��� */
	//if (FishAreaX0 <= *enemy[].GetEnemyLocationX() && enemy[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= enemy[].GetEnemyLocationY() + 32 && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.EFlg == 4) {
	//	fish.FPSCount();
	//}


	/* �����������̏��� */
	//if (fish.FishProbability() == TRUE /*&& fish.PFlg == 1*/) {
	//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1) {
	//		fish.FishPlayerHitAnimation(player);
	//		/*player.SetPlayerDeathFlg(TRUE);
	//		player.SetPlayerDeathFState(1);*/
	//		fish.PFlg = 3;
	//	}
	//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() != 1) {
	//		fish.FishDownAnimation();
	//	}
	//}
	/*if (hit.FishAndPlayer(fish, player) == TRUE) {
		fish.FishPlayerHitAnimation(player);
		fish.FishDownAnimation();
	}*/

		//���̃X�e�[�W�̓G����
		//if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		//	if (Stage::Snum >= 4) { Stage::Snum = 0; }
		//		Stage::Snum += 1;
		//	if (OldSnum != Stage::Snum) {
		//		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		//			enemy[i] = new Enemy(i, i);
		//		}
		//	}
		//}

	if (ClearFlg == TRUE) {
		//count�ŏ����܂��Ă���
		if (++count > 100) {
			Fish::FyInitFlg = true;
			ClearFlg = FALSE;
			count = 0;
			enemy[Elast] = nullptr;
			Enemy::EdeadCount = -1;
			Stage::Snum += 1;
			player.InitPlayer();  //�v���C���[�̏�����

			//�X�e�[�W���Ō�܂ŃN���A������^�C�g���ɖ߂�
			if (Stage::Snum > 4) {
				Stage::Snum = 0;
				UI::old_score = Enemy::Score;
				Enemy::Score = 0;
				UI::getsco = 0;
				return new TitleScene;
			}
		
	
			//���̃X�e�[�W�̓G����
			if (OldSnum != Stage::Snum) {
				for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
					enemy[i] = new Enemy(i, i);
				}
			}
		}
	}
	// ���C�t�|�C���g��0�ɂȂ�����Q�[���I�[�o�[
	tst=player.GetPlayerLife();
	if (tst <= -1) {
		
		Enemy::Score = 0;
		UI::getsco = 0;
		return new End;
	}
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(200, 300, 0xffffff, "life%d",tst);

	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);	// �|�[�Y���ɏ��������`�恫
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��"); 
	}
	
	stage.DrawStage();
	player.PlayerDraw();

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		//DrawFormatString(200, 300, 0xffffff, "EnemyMax%d", Stage::EnemyMax[Stage::Snum]);
		if (enemy[i] != nullptr) {
			enemy[i]->EnemyDraw();

		}
		
	}

	if (Enemy::GetFishflg() == true)fish.EdeadFishAnim();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	stage.DrawSea();
	UI.DrawUI();
	hit.DrawHitBox();
	//enemy.EnemyDraw();
	fish.FishDraw(player);
	thunder.ThunderDraw();
	bubble.BabbleDraw();
	DrawFormatString(100, 0, 0xffffff, "%d", a);

	//DrawFormatString(300,0, 0xffffff, "%d", Enemy::Eflg);
	//DrawBox(200, 99, 242, 117, 0xff0000, TRUE);

	DrawFormatString(400, 0, 0xffffff, "hitflg:%d", b);
}