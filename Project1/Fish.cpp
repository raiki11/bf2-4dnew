#include<time.h>
#include "Fish.h"
#include"DxLib.h"

#define FishAreaX0    160
#define FishAreaX1    480
#define FishAreaY     419

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 11, 5, 2, 64, 64, FishImg);
	Time = 0;
	fpscount = 0;
	i = 0;
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e[])
{
	/* プレイヤーがサカナの稼働エリアに入った時 */
	if (FishAreaX0 <= p.GetPlayerLocationX() && p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() + 32 && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
		if (PFlg == 0) {
			PFlg = 1;
		}
		else {
			PFlg = 0;
		}
		if (++fpscount >= 180) {  // ３秒以上たったら
			fpscount = 180;  // 加算し続けないように値を固定
			if (FishProbability() == TRUE && PFlg == 1) { // サカナの確率
				PFlg = 2;
				FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
				FishOrientation = Orientation();  // サカナの向きを描く際の変数に入れる
				FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
			}
		}
	}
	else fpscount = 0;  // FPSのカウントをリセットする

	if (FishFlg == 1 && PFlg == 2) {      // フィッシュフラグがサカナを上げるフラグになった時
		//FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
		/* アニメーション処理 */
		FishUpAnimation();
		/*if (p.GetPlayerLocationX() == FishX && p.GetPlayerLocationY() == FishY) {
			FishHitAnimation();
			
		}*/
		if (i == 2) {
			PFlg = 3;
		}
	}
	
	if (PFlg == 3) {      // フィッシュフラグがサカナを下げるフラグになった時
		//FishY += 2;             // フィッシュを下に下げる
		/* アニメーション処理 */
		FishDownAnimation();
		if (i == 5) {
			i = 10;
			PFlg = 0;
			FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
			/*fpscount = 0;*/
		}
	}

	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0 && i == 10) {
		fpscount = 180;
	}
	

	/* 敵がサカナの稼働エリアに入った時 */
	//if (FishAreaX0 <= e.GetEnemyLocationX() <= FishAreaX1 && FishAreaY <= e.GetEnemyLocationY() && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
	//	if (EFlg == 0) {
	//		EFlg = 1;
	//	}
	//	else {
	//		EFlg = 0;
	//	}

	//	if (FishProbability() == TRUE && PFlg == 1) { // サカナの確率
	//		/* 処理を書く */
	//		PFlg = 2;
	//		FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
	//		FishX = e.GetEnemyLocationX(); // プレイヤーがいたX座標にサカナを出現させる
	//	}
	//	//if (p.GetPlayerLocationX() < FishAreaX0 && FishAreaX1 <  p.GetPlayerLocationX() && FishAreaY > p.GetPlayerLocationY()) {// プレイヤーがサカナの範囲を出たとき
	//	//	FishFlg = 0;
	//	//}
	//	//else {
	//	//	FishFlg = 3;  // 範囲内に入った時、1回しかif文の中の条件を受付ないように設定
	//	//}
	//}
	//if (FishFlg == 1 && PFlg == 2) {      // フィッシュフラグがサカナを上げるフラグになった時
	//	--FishY;             // フィッシュを上に上げる
	//	if (FishY == 420) {  // フィッシュのY座標が４２０になった時
	//		FishFlg = 2;     // フィッシュフラグをサカナが下がるフラグに変更
	//	}
	//}
	//if (FishFlg == 2) {      // フィッシュフラグがサカナを下げるフラグになった時
	//	FishY++;             // フィッシュを下に下げる
	//	if (FishY == 500) {  // フィッシュのY座標が５００になった時
	//		FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
	//		PFlg = 0;
	//	}
	//}
}

void Fish:: FishDraw(Player p) const
{
	DrawRotaGraph(FishX, FishY, 1.0f, 0, FishImg[i], TRUE, FishOrientation);

	/* デバック用 */
	DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationY());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
	DrawFormatString(0, 260, 0xffffff, "FishOrientation::%d", FishOrientation);
	DrawFormatString(0, 290, 0xffffff, "flg::%d", fpscount);
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
	if (i == 10) i = 0;   // サカナが出てないときiをリセットする

	if (i < 2 && ++Time % 15 == 0) {
		i++;
	}
}

void Fish::FishDownAnimation()
{
	
	++Time;

	if (i < 5 && Time % 15 == 0) {
		++i;
	}
}

void Fish::FishHitAnimation()
{
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