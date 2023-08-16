#include<time.h>
#include "Fish.h"
#include"DxLib.h"
#include"HitBox.h"


//#define FishAreaX0    160
//#define FishAreaX1    480
//#define FishAreaY     419

bool Fish::FyInitFlg = false;

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 11, 5, 2, 64, 64, FishImg);
	Time = 0;
	fpscount = 0;
	i = 10;
	Fishmove=0;
	Fy = 440;
	Fx = 0;
	Fimg = 1;
	count = 0;
	FishFlg = 0;
	PFlg = 0;
	EFlg = 0;
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e)
{
	/* プレイヤーがサカナの稼働エリアに入った時 */
	if (FishAreaX0 <= p.GetPlayerLocationX() - 16 && p.GetPlayerLocationX() + 16 <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() + 32 && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
		if (++fpscount >= 180) {  // ３秒以上たったら
			fpscount = 180;  // 加算し続けないように値を固定
			//if (FishProbability() == TRUE && PFlg == 1) { // サカナの確率
			//	PFlg = 2;
			//	FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
			//	FishOrientation = Orientation();  // サカナの向きを描く際の変数に入れる
			//	FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
			//}
		}
	}
	else { 
		fpscount = 0; // FPSのカウントをリセットする
	}

	if (FishFlg == 1 && PFlg == 2) {      // フィッシュフラグがサカナを上げるフラグになった時
		//FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
		/* アニメーション処理 */
		//FishUpAnimation();
		/*if (hb.FishAndPlayer(f, p) == TRUE) {
			FishPlayerHitAnimation(p);
			
		}*/
		if (i == 2 || i == 6) {
			PFlg = 3;
		}
	}
	
	if (PFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時

		/* アニメーション処理 */
		//FishDownAnimation();
		if (i == 5) {
			i = 10;
			/*PFlg = 4;
			FishFlg = 0;*/     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
			/*fpscount = 0;*/
		}
		
	}
	
	/* プレイヤーがサカナエリアに居続ける時の処理 */
	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0 && i == 10 && PFlg==4) {
		fpscount = 180;
	}


	if (FyInitFlg == true) {
		Fy = 445;
		FyInitFlg = false;
	}

	if (Enemy::GetFishflg() == true) {
		EdeadFish();
	}
	else {
		Fishmove = 0;
	}

	Fx = e.GetEnemyLocationX();

	/* 敵がサカナの稼働エリアに入った時 */
	//if (FishAreaX0 <= e[].GetEnemyLocationX() - 16 && e[].GetEnemyLocationX() + 16 <= FishAreaX1 && FishAreaY <= e[].GetEnemyLocationY() + 32 && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
	//	if (++fpscount >= 180) {  // ３秒以上たったら
	//		fpscount = 180;  // 加算し続けないように値を固定
	//		//if (FishProbability() == TRUE && PFlg == 1) { // サカナの確率
	//		//	PFlg = 2;
	//		//	FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
	//		//	FishOrientation = Orientation();  // サカナの向きを描く際の変数に入れる
	//		//	FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
	//		//}
	//	}
	//}
	//else {
	//	fpscount = 0; // FPSのカウントをリセットする
	//}

	//if (FishFlg == 1 && EFlg == 2) {      // フィッシュフラグがサカナを上げるフラグになった時
	//	//FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
	//	/* アニメーション処理 */
	//	//FishUpAnimation();
	//	/*if (hb.FishAndPlayer(f, p) == TRUE) {
	//		FishPlayerHitAnimation(p);

	//	}*/
	//	if (i == 2 || i == 6) {
	//		EFlg = 3;
	//	}
	//}

	//if (EFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時

	//	/* アニメーション処理 */
	//	//FishDownAnimation();
	//	if (i == 5) {
	//		i = 10;
	//		/*EFlg = 4;
	//		FishFlg = 0;*/     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
	//		/*fpscount = 0;*/
	//	}

	//}

	///* プレイヤーがサカナエリアに居続ける時の処理 */
	//if (FishAreaX0 <= e[].GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= e[].GetEnemyLocationY() && FishFlg == 0 && i == 10 && EFlg == 4) {
	//	fpscount = 180;
	//}
}

void Fish:: FishDraw(Player p) const
{
	DrawRotaGraph(FishX, FishY, 1.0f, 0, FishImg[i], TRUE, FishOrientation);

	/* デバック用 */
	//DrawFormatString(400, 200, 0xffffff, "playerLocationX::%f", p.GetPlayerLocationX());
	//DrawFormatString(400, 230, 0xffffff, "fishLocationX::%f", FishX);
	///*DrawFormatString(400, 260, 0xffffff, "FishOrientation::%d", FishOrientation);*/
	//DrawFormatString(400, 290, 0xffffff, "flg::%d", fpscount);
	//DrawFormatString(400, 350, 0xffffff, "Time::%d", Time);
	//DrawFormatString(400, 380, 0xffffff, "i::%d", i);
}

int Fish::FishProbability() 
{
	// 乱数を初期化
	srand((unsigned int)time(NULL));

	sakana = rand() % 10 + 1; // 乱数の生成（数字：１～１０）

	if (sakana <= 3) {
		return TRUE;
	}
	else return FALSE;
}

void Fish::FishUpAnimation()
{
	Time;
	if (i == 10) {
		i = 0;   // サカナが出てないときiをリセットする
	}

	if (i < 2 && ++Time % 30 == 0) { // 要調整
	i++;
	}
}

void Fish::FishDownAnimation()
{
	
	++Time;
	if (i == 6) {
		if (Time % 30 == 0) i = 2;
	}
	if (i < 5 && Time % 30 == 0) { // 要調整
		++i;
	}
	if (i == 5) {
		i = 10;
		Time = 0;
	}
	
}

void Fish::FishPlayerHitAnimation(Player p)
{
	i = 6;
}

void Fish::FishEnemyHitAnimation(Enemy enemy[]) {
	//switch(/* 何が当たったかをここに書く */)
	//	case 0:   // プレイヤーが当たった場合
	//		i = 7;
	//		break;
	//	case 1:   // ピンクの敵だったとき
	//		i = 8;
	//		break;
	//	case 2:   // 緑の敵だったとき
	//		i = 9;
	//		break;
	//	case 3:   // 黄色の敵だったとき
	//		i = 10;
	//		break;
	//	default:  // 誰も食えなかったとき
	//		i = 3;
	//		break;
}

bool Fish::Orientation() {
	// 乱数を初期化
	srand((unsigned int)time(NULL));

	sakanaOrientation = rand() % 2; // 乱数の生成（数字：０～１）

	if (sakanaOrientation == 0) {
		return TRUE;
	}
	else return FALSE;
}

void Fish::EdeadFish() {
	switch (Fishmove) {
	case 0:
		Fy--;
		if (Fy<=420) {
			Fishmove+=1;
		}
		break;
	case 1:
		count++;
		if (count > 20) {
			count = 0;
			Fishmove += 1;
		}
		break;
		case 2:
			Fy++;
			if (Fy>=440) {
				Fishmove +=1;

				count = 0;
			}
			break;
		case 3:
			Fishmove += 1;
			Fy = 440;
			break;
		default:
			break;
	}
}

void Fish::EdeadFishAnim()const{

	DrawRotaGraph(Enemy::EgetFx, Fy, 1.0f, 0, FishImg[Fimg], TRUE, FishOrientation);

}