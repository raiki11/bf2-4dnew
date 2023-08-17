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
	if (GameoverFlg != TRUE) {

		//ポーズ中でないとき
		if (PauseFlg == FALSE) {
			if (ClearFlg == FALSE) {
				// PHASE点滅カウント			
				UI.Update(player.GetPlayerLife());
				// ゲームメイン処理
				player.PlayerUpdate();
				//printfDx("%d", Enemy::EdeadCount);

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
			}

			if (ClearFlg == FALSE) {
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
						if (enemy[i]->EGetReboundFlgStageX() == TRUE /*&& player.GetReboundFrameCntX() <= 60*/) {
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
								player.SetReboundFlgStageX(TRUE);
								enemy[i]->ESetReboundFlgStageX(TRUE);

							}

							if (player.GetRemainBalloon() > 0) {
								if (hit.PlayerBalloonAndEnemy(player, *enemy[i]) == TRUE) {
									if (player.GetNoInputFlg() == FALSE) {
										player.SubtractRemainBalloon();
									}
									player.SetReboundFlgStageX(TRUE);
									player.SetReboundFlgStageY(TRUE);
									player.SetPlayerImgFpsCnt(0);
									enemy[i]->ESetReboundFlgStageX(TRUE);
									enemy[i]->ESetReboundFlgStageY(TRUE);
								}
							}

						}
						if (enemy[i]->GetI() >= 8 && enemy[i]->GetI() <= 17) {

							if (hit.PlayerAndEnemyBalloon(player, *enemy[i]) == TRUE) {
								//player.SubtractRemainBalloon();

								player.SetReboundFlgStageX(TRUE);
								//player.SetReboundFlgStageY(TRUE);
								player.SetPlayerMoveY();
							}
						}
					}


					//bubble[i].BabbleUpdate(player, *enemy[i]);


				}
			}


			//プレイヤーと雷
			//if (hit.PlayerAndThunder(player, thunder) == TRUE) {
			//	if (player.GetDeathFlg() == FALSE) {
			//		player.SetPlayerDeathFlg(TRUE);
			//		player.SetPlayerDeathFState(1);
			//	}
			//}

			// ステージと当たり判定
			if (hit.ThunderAndStageLeft(thunder, stage) == TRUE) {
				thunder.ChangeAngle();
			}
			if (hit.ThunderAndStageRight(thunder, stage) == TRUE) {
				thunder.ChangeAngle();
			}
			if (hit.ThunderAndStageUnder(thunder, stage) == TRUE) {
				thunder.ChangeAngle();
			}
			if (hit.ThunderAndStageTop(thunder, stage) == TRUE) {
				thunder.ChangeAngle();
			}
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
			}

		}

		/* プレイヤーがサカナエリアに居続ける時の処理 */
		if (FishAreaX0 <= player.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= player.GetPlayerLocationY() && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.PFlg == 4) {
			fish.FPSCount();
		}

		/* 魚と敵の当たり判定 */
		/* 敵がサカナの稼働エリアに入った時 */
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
		//	/* アニメーション処理 */
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

		//if (fish.EFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時
		//	//FishY += 2;             // フィッシュを下に下げる
		//	/* アニメーション処理 */
		//	fish.FishDownAnimation();
		//	if (fish.FishAnimation() == 10) {
		//		fish.FishAnimation();  // i == 10
		//		fish.EFlg = 4;
		//		fish.FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
		//		/*fpscount = 0;*/
		//	}

		//}

		///* プレイヤーがサカナエリアに居続ける時の処理 */
		//if (FishAreaX0 <= *enemy[].GetEnemyLocationX() && enemy[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= enemy[].GetEnemyLocationY() + 32 && fish.FishFlg == 0 && fish.FishAnimation() == 10 && fish.EFlg == 4) {
		//	fish.FPSCount();
		//}


		/* 当たった時の処理 */
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

		//次のステージの敵生成
		//if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		//	if (Stage::Snum >= 4) { Stage::Snum = 0; }
		//		Stage::Snum += 1;
		//	if (OldSnum != Stage::Snum) {
		//		for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		//			enemy[i] = new Enemy(i, i);
		//		}
		//	}
		//}
	}


	if (ClearFlg == TRUE) {
		//countで少しまってから
		if (++count > 100) {
			Fish::FyInitFlg = true;
			ClearFlg = FALSE;
			count = 0;
			enemy[Elast] = nullptr;
			Enemy::EdeadCount = -1;
			Stage::Snum += 1;
			player.InitPlayer();  //プレイヤーの初期化

			//ステージを最後までクリアしたらタイトルに戻る
			if (Stage::Snum > 4) {
				Stage::Snum = 0;
				return new TitleScene;
			}
			// ライフポイントが0になったらゲームオーバー
		/*	if (player.GetPlayerLife()==-1) {
				return new End;
			}*/
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


	tst=player.GetPlayerLife();
	if (tst <= -1) {
		GameoverFlg = TRUE;

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
				bubble[i] = new Bubble();
			}

			return new TitleScene();
		}
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

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	UI.DrawUI();
	hit.DrawHitBox();
	//enemy.EnemyDraw();
	fish.FishDraw(player);
	thunder.ThunderDraw();

	stage.DrawSea();
	DrawFormatString(100, 0, 0xffffff, "%d", a);

	if (GameoverFlg == TRUE) {
		DrawGraph(220, 220, image, TRUE);
	}

	//DrawFormatString(300,0, 0xffffff, "%d", Enemy::Eflg);
	//DrawBox(200, 99, 242, 117, 0xff0000, TRUE);
}

