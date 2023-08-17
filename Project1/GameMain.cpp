#include "GameMain.h"
#include"DxLib.h"
#include"PadInput.h"
#include "Stage.h"
#include "Player.h"
#include "End.h"
#include "UI.h"
#include "End.h"

Enemy* enemy[6];
Bubble* bubble[6];

GameMain::GameMain()
{
	PauseFlg = FALSE;
	ClearFlg = FALSE;
	Elast = -1;
	a = 0;
	count = 0;
	OldSnum = Stage::Snum;
	fishi = 0;

	image = LoadGraph("images/UI/UI_GameOver.png");
	GameoverFlg = FALSE;

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		enemy[i] = new Enemy(i, i);

		bubble[i] = new Bubble();
		
	}

	for (int i = 0; i < 20; i++) {
		reboundFlg[i] = { FALSE };
	}
	
	reboundPflg = FALSE;
	playerAndFishFlg = FALSE;
	

	o	= 0;
	//BGMの読み込み
	//(BGM = LoadSoundMem("sounds/BGM_Trip.wav"));

	//BGMの音量変更
	ChangeVolumeSoundMem(70, BGM);

	//SEの読み込み
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

	SE_restart = LoadSoundMem("sounds/SE_Restart.wav");
	ChangeVolumeSoundMem(70, SE_restart);
	restartFlg = FALSE;

	SE_eatable = LoadSoundMem("sounds/SE_Eatable.wav");
	ChangeVolumeSoundMem(70, SE_eatable);

	SE_stageclear = LoadSoundMem("sounds/SE_StageClear.wav");
	ChangeVolumeSoundMem(70, SE_stageclear);
	clearSoundFlg = FALSE;

}

GameMain::~GameMain()
{
	//BGMの削除
	DeleteSoundMem(BGM);
	DeleteSoundMem(Start_SE);
}

AbstractScene* GameMain::Update()
{

	//BGMの再生
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


	//ポーズフラグ切り替え処理
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		//PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);
		PauseFlg = !PauseFlg;

	}
	//ポーズ中でないとき
	if (PauseFlg == FALSE) {
		if (ClearFlg == FALSE) {
			if (GameoverFlg != TRUE) {
				// PHASE点滅カウント			
				UI.Update(player.GetPlayerLife());
				// ゲームメイン処理
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
			
			if (player.GetNoInputFlg() == TRUE && player.GetPlayerLife() != 2)
			{
				if (CheckSoundMem(SE_restart) == 0 && restartFlg == FALSE)
				{
					PlaySoundMem(SE_restart, DX_PLAYTYPE_BACK, TRUE);
					restartFlg = TRUE;
				}
			}
			if (player.AnyButtons() == TRUE) {
				restartFlg = FALSE;
			}

			//エネミーアップデート
			for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
				if (enemy[i] != nullptr) {
					enemy[i]->EnemyUpdate(player, i);
					fishi = i;
				}
				//エネミーを倒したら
				if (Enemy::EdeadCount == Stage::EnemyMax[Stage::Snum]) {
					if (++count > 15) {
						ClearFlg = TRUE;
						Enemy::EdeadCount = -1;
						Elast = i;
						Enemy::DeadFlg = FALSE;
						
						
					}

					}
					if (Enemy::DeadFlg == TRUE) {
						getenemyX[i] = enemy[i]->GetEnemyLocationX();
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


				//シャボン玉アップデート
				for (int i = 0; i < 6; i++) {

					if (bubble[i] != nullptr) {
						if (bubble[i]->BubbleDelete() == TRUE) {
							bubble[i] = nullptr;
						}
					}
					if (bubble[i] != nullptr) {
						if (getenemyX[i] != 0) {
							bubble[i]->BubbleUpdate(player, getenemyX[i]);
						}
					}

				}

		if (hit.PlayerAndStageUnder(player, stage) == TRUE) {
			
			player.SetFlyingFlg(FALSE);
			
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
			if (player.GetReboundFlgStageX() == TRUE ) {
				player.SetReboundFlgStageX(TRUE);
			}
			else {
				player.SetReboundFlgStageX(FALSE);
			}
		}

				for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
					if (enemy[i] != nullptr) {

						//敵の当たり判定
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
					if (enemy[i]->EGetReboundFlgStageX() == TRUE ) {
						enemy[i]->ESetReboundFlgStageX(TRUE);
					}
					else {
						enemy[i]->ESetReboundFlgStageX(FALSE);
					}
				}
			}
		}


				//プレイヤーと敵
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
							
							PlaySoundMem(SE_crack, DX_PLAYTYPE_BACK, TRUE);
							
							player.SetReboundEnemyX(TRUE);
							player.SetReboundEnemyY(TRUE);
						
							reboundFlg[i] = TRUE;
						}
						else {
							reboundFlg[i] = FALSE;
						}
					}
				}
			}
		}

				//敵と敵
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
						}
					}
				}
			}
		}


				//プレイヤーと雷
				if (hit.PlayerAndThunder(player, thunder) == TRUE) {
					if (player.GetDeathFlg() == FALSE) {
						player.SetPlayerDeathFlg(TRUE);
						player.SetPlayerDeathFState(1);
					}
				}
				b = hit.ThunderAndStageLeft(thunder, stage);
				// ステージと当たり判定
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



				/* 魚とプレイヤーの当たり判定 */

				/* プレイヤーがサカナの稼働エリアに入った時 */
				if (FishAreaX0 <= player.GetPlayerLocationX() && player.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= player.GetPlayerLocationY() + 32 && fish.FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
					if (fish.PFlg == 0) {
						fish.PFlg = 1;
					}
					else {
						fish.PFlg = 0;
					}
					if (fish.FPSCount() >= 180) {  // ３秒以上たったら
						fish.FPSCount();  // 加算し続けないように値を固定

						if (fish.FishProbability() == TRUE && fish.PFlg == 1) { // サカナの確率
							fish.PFlg = 2;
							fish.FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
							fish.FishOrientation = fish.Orientation();  // サカナの向きを描く際の変数に入れる
							fish.FishX = player.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
						}
					}
				}
				else fish.FPSCount();  // FPSのカウントをリセットする

				if (fish.FishFlg == 1 && fish.PFlg == 2 || fish.PFlg == 5) {      // フィッシュフラグがサカナを上げるフラグになった時
					//FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
					/* アニメーション処理 */
					fish.FishUpAnimation();
					if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1 /*|| fish.FishAnimation() == 2*/) {
						fish.FishPlayerHitAnimation(player);
						/*player.SetPlayerDeathFlg(TRUE);
						player.SetPlayerDeathFState(1);*/
						fish.PFlg = 5;

			player.SetPlayerDeathFlg(TRUE);
			player.SetPlayerDeathFState(3);
			playerAndFishFlg = TRUE;
			PlaySoundMem(SE_eatable, DX_PLAYTYPE_BACK, TRUE);
		}
		if (fish.FishAnimation() == 2 || fish.FishAnimation() == 6 || fish.PFlg == 5) {
			fish.PFlg = 3;
		}
	}

				if (fish.PFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時
					//FishY += 2;             // フィッシュを下に下げる
					/* アニメーション処理 */
					fish.FishDownAnimation();
					if (fish.FishAnimation() == 10) {
						fish.FishAnimation();  // i == 10
						fish.PFlg = 4;
						fish.FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
						/*fpscount = 0;*/
						if (playerAndFishFlg == TRUE) {
							player.SetFishFlg(TRUE);
							playerAndFishFlg = FALSE;
						}
					}

				}

				/* プレイヤーがサカナエリアに居続ける時の処理 */
				if (FishAreaX0 <= player.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= player.GetPlayerLocationY() && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.PFlg == 4) {
					fish.FPSCount();
				}

				/*
				 魚と敵の当たり判定
				敵がサカナの稼働エリアに入った時
				//if (FishAreaX0 <= *enemy[].GetEnemyLocationX() && enemy[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= enemy[].GetEnemyLocationY() + 32 && fish.FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
				//	if (fish.EFlg == 0) {
				//		fish.EFlg = 1;
				//	}
				//	else {
				//		fish.EFlg = 0;
				//	}
				//	if (fish.FPSCount() >= 180) {  // ３秒以上たったら
				//		fish.FPSCount();  // 加算し続けないように値を固定

				//		if (fish.FishProbability() == TRUE && fish.EFlg == 1) { // サカナの確率
				//			fish.EFlg = 2;
				//			fish.FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
				//			fish.FishOrientation = fish.Orientation();  // サカナの向きを描く際の変数に入れる
				//			fish.FishX = player.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
				//		}
				//	}
				//}
				//else fish.FPSCount();  // FPSのカウントをリセットする

				//if (fish.FishFlg == 1 && fish.EFlg == 2 || fish.EFlg == 5) {      // フィッシュフラグがサカナを上げるフラグになった時
				//	//FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
				//	 アニメーション処理
				//	fish.FishUpAnimation();
				//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1 || fish.FishAnimation() == 2) {
				//		fish.FishPlayerHitAnimation(player);
				//		player.SetPlayerDeathFlg(TRUE);
				//		player.SetPlayerDeathFState(1);
				//		fish.EFlg = 5;
				//	}
				//	*if (hb.FishAndPlayer(f, p) == TRUE) {
				//		FishPlayerHitAnimation(p);

				//	}*
				//	if (fish.FishAnimation() == 2 || fish.FishAnimation() == 6 || fish.EFlg == 5) {
				//		fish.EFlg = 3;
				//	}
				//}

				//if (fish.EFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時
				//	//FishY += 2;             // フィッシュを下に下げる
				//	* アニメーション処理 *
				//	fish.FishDownAnimation();
				//	if (fish.FishAnimation() == 10) {
				//		fish.FishAnimation();  // i == 10
				//		fish.EFlg = 4;
				//		fish.FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
				//		fpscount = 0;
				//	}

				//}

				//プレイヤーがサカナエリアに居続ける時の処理
				//if (FishAreaX0 <= *enemy[].GetEnemyLocationX() && enemy[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= enemy[].GetEnemyLocationY() + 32 && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.EFlg == 4) {
				//	fish.FPSCount();
				//}


				 当たった時の処理
				//if (fish.FishProbability() == TRUE /*&& fish.PFlg == 1) {
				//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() == 1) {
				//		fish.FishPlayerHitAnimation(player);
				//		player.SetPlayerDeathFlg(TRUE);
				//		player.SetPlayerDeathFState(1);
				//		fish.PFlg = 3;
				//	}
				//	if (hit.FishAndPlayer(fish, player) == TRUE && fish.FishAnimation() != 1) {
				//		fish.FishDownAnimation();
				//	}
				//}
			//	if (hit.FishAndPlayer(fish, player) == TRUE) {
				//	fish.FishPlayerHitAnimation(player);
				//	fish.FishDownAnimation();
				//}

				*/
			}
		}
	
}

	if (ClearFlg == TRUE) {
		if (clearSoundFlg == FALSE) {
			PlaySoundMem(SE_stageclear, DX_PLAYTYPE_BACK, TRUE);
			clearSoundFlg = TRUE;
		}
		//countで少しまってから
		if (++count > 100 && CheckSoundMem(SE_stageclear) == 0) {
			Fish::FyInitFlg = true;
			ClearFlg = FALSE;
			count = 0;
			enemy[Elast] = nullptr;
			Enemy::EdeadCount = -1;
			Stage::Snum += 1;
			player.InitPlayer();  //プレイヤーの初期化
			clearSoundFlg = FALSE;

					//ステージを最後までクリアしたらタイトルに戻る
					if (Stage::Snum > 4) {
						Stage::Snum = 0;
						UI::old_score = Enemy::Score;
						Enemy::Score = 0;
						UI::getsco = 0;
						for (int i = 0; i <= 6; i++) {
							//バブルの残りを削除
							bubble[i] = nullptr;
							getenemyX[i] = 0;
						}
						return new TitleScene;
					}


					//次のステージの敵生成
					if (OldSnum != Stage::Snum) {
						for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
							enemy[i] = new Enemy(i, i);

							//バブルの残りを削除
							bubble[i] = nullptr;
							getenemyX[i] = 0;
							bubble[i] = new Bubble();
						}
					}
				}
			}
			// ライフポイントが0になったらゲームオーバー
			if (player.GetPlayerLife() <= -1) {
				GameoverFlg = TRUE;
			}

			if (GameoverFlg == TRUE) {
				Fish::FyInitFlg = true;
				ClearFlg = FALSE;
				count = 0;
				enemy[Elast] = nullptr;
				Enemy::EdeadCount = -1;
				//player.InitPlayer();  //プレイヤーの初期化

				if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
					for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
						//バブルの残りを削除
						bubble[i] = nullptr;
						getenemyX[i] = 0;
					}

					return new TitleScene();
				}
				//return new End;

				Enemy::Score = 0;
				UI::getsco = 0;
				//return new End;
			}

			
			return this;
}

void GameMain::Draw() const
{
	DrawFormatString(200, 300, 0xffffff, "life%d",tst);
	stage.DrawStage();

	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);	// ポーズ中に消したい描画↓
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
	
	stage.DrawStage();
	if (GameoverFlg == FALSE) {
		player.PlayerDraw();
	}

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {

		//DrawFormatString(200, 300, 0xffffff, "EnemyMax%d", Stage::EnemyMax[Stage::Snum]);
		if (enemy[i] != nullptr) {
			enemy[i]->EnemyDraw();

		}
		
	}

	for (int i = 0; i < 6; i++) {

		if (bubble[i] != nullptr) {
			bubble[i]->BubbleDraw();

		}
	}

	if (Enemy::GetFishflg() == true)fish.EdeadFishAnim();

	fish.FishDraw(player);
	thunder.ThunderDraw();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	stage.DrawSea();
	UI.DrawUI();
	hit.DrawHitBox();

	DrawFormatString(100, 0, 0xffffff, "%d", a);

	if (GameoverFlg == TRUE) {
		DrawGraph(220, 220, image, TRUE);
	}

	//DrawFormatString(300,0, 0xffffff, "%d", Enemy::Eflg);
	//DrawBox(200, 99, 242, 117, 0xff0000, TRUE);

	DrawFormatString(400, 0, 0xffffff, "hitflg:%d", b);
}