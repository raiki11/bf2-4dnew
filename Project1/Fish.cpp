#include<time.h>
#include "Fish.h"
#include"DxLib.h"

#define FishAreaX0    160
#define FishAreaX1    480
#define FishAreaY     419

Fish::Fish()
{
	LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 6, 6, 1, 64, 64, FishImg);
}

Fish::~Fish()
{

}

void Fish::FishUpdate(Player p , Enemy e)
{
	/* プレイヤーがサカナの稼働エリアに入った時 */
	if (FishAreaX0 <= p.GetPlayerLocationX() <= FishAreaX1 && FishAreaY <= p.GetPlayerLocationY() && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
		if (Flg == 0) {
			Flg = 1;
		}
		else {
			Flg = 0;
		}
		
		if (FishProbability() == TRUE && Flg == 1) { // サカナの確率
			/* 処理を書く */
			Flg = 2;
			FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
			FishX = p.GetPlayerLocationX(); // プレイヤーがいたX座標にサカナを出現させる
		}
		//if (p.GetPlayerLocationX() < FishAreaX0 && FishAreaX1 <  p.GetPlayerLocationX() && FishAreaY > p.GetPlayerLocationY()) {// プレイヤーがサカナの範囲を出たとき
		//	FishFlg = 0;
		//}
		//else {
		//	FishFlg = 3;  // 範囲内に入った時、1回しかif文の中の条件を受付ないように設定
		//}
	}
	if (FishFlg == 1 && Flg == 2) {      // フィッシュフラグがサカナを上げるフラグになった時
		--FishY;             // フィッシュを上に上げる
		if (FishY == 420) {  // フィッシュのY座標が４２０になった時
			FishFlg = 2;     // フィッシュフラグをサカナが下がるフラグに変更
		}
	}
	if (FishFlg == 2) {      // フィッシュフラグがサカナを下げるフラグになった時
		FishY++;             // フィッシュを下に下げる
		if (FishY == 500) {  // フィッシュのY座標が５００になった時
			FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
			Flg = 0;
		}
	}
}

void Fish:: FishDraw(Player p) const
{
	for (int i = 0; i < 6; i++) {
		DrawRotaGraph(FishX, FishY, 1.0, 0, FishImg[i], TRUE, FALSE);
	}
	/* デバック用 */
	/*DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationY());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
	DrawFormatString(0, 260, 0xffffff, "fishflg::%d", FishFlg);
	DrawFormatString(0, 290, 0xffffff, "flg::%d", Flg);*/
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

