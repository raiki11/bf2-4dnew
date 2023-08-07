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
			}
		}


		//プレイヤーと雷
		if (hit.PlayerAndThunder(player, thunder) == TRUE) {
			if (player.GetDeathFlg() == FALSE) {
				player.SetPlayerDeathFlg(TRUE);
				player.SetPlayerDeathFState(1);
			}
		}

		if (hit.ThunderAndStageUnder(thunder, stage) == TRUE) {
			thunder.ChangeAngle();
		}
	}
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
		

		/* 魚とプレイヤーの当たり判定 */

		if (fish.FishProbability() == TRUE && fish.PFlg == 1) {
			if (hit.FishAndPlayer(fish, player) == TRUE) {
				fish.FishPlayerHitAnimation(player);
				/*player.SetPlayerDeathFlg(TRUE);
				player.SetPlayerDeathFState(1);*/
				fish.FishDownAnimation();
			}
		}

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
				}
			}
		}
	}

	tst=player.GetPlayerLife();
	if (tst <= -1) {

		return new End;
	}
	return this;
}

void GameMain::Draw() const
{
	DrawFormatString(200, 300, 0xffffff, "life%d",tst);

	if (PauseFlg == TRUE) {
		DrawFormatString(0, 0, 0xffffff, "Pause");
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);	// ポーズ中に消したい描画↓
	}
	else 
	{ 
		DrawFormatString(0, 0, 0xffffff, "ゲームメイン"); 
	}
	

	player.PlayerDraw();

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		//DrawFormatString(200, 300, 0xffffff, "EnemyMax%d", Stage::EnemyMax[Stage::Snum]);
		if (enemy[i] != nullptr) {
			enemy[i]->EnemyDraw();

		}
		
	}

	if (Enemy::GetFishflg() == true)fish.EdeadFishAnim();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	stage.DrawStage();
	UI.DrawUI();
	hit.DrawHitBox();
	//enemy.EnemyDraw();
	fish.FishDraw(player);
	thunder.ThunderDraw();
	bubble.BabbleDraw();
	DrawFormatString(100, 0, 0xffffff, "%d", a);

	//DrawFormatString(300,0, 0xffffff, "%d", Enemy::Eflg);
	//DrawBox(200, 99, 242, 117, 0xff0000, TRUE);
}

