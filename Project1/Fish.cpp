#include<time.h>
#include "Fish.h"
#include"DxLib.h"

#define FishAreaX0    160;
#define FishAreaX1    480;
#define FishAreaY     419;

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
	if (160 <= p.GetPlayerLocationX() <= 480 && 419 <= p.GetPlayerLocationY() && FishFlg == 0) {// プレイヤーがサカナの範囲に入った時
		Flg = 1;
		if (FishProbability() == TRUE && Flg == 1) { // サカナの確率
			/* 処理を書く */
		FishFlg = 1;         // フィッシュフラグをサカナが上がるフラグに変更
		}
	}
	else {
		Flg = 0;
	}

	if (FishFlg == 1) {      // フィッシュフラグがサカナを上げるフラグになった時
		--FishY;             // フィッシュを上に上げる
		if (FishY == 420) {  // フィッシュのY座標が４２０になった時
			FishFlg = 2;     // フィッシュフラグをサカナが下がるフラグに変更
		}
	}
	if (FishFlg == 2) {      // フィッシュフラグがサカナを下げるフラグになった時
		FishY++;             // フィッシュを下に下げる
		if (FishY == 500) {  // フィッシュのY座標が５００になった時
			FishFlg = 0;     // フィッシュフラグをプレイヤーやエネミーが入っていない状態にする。
		}
	}
}

void Fish:: FishDraw(Player p) const
{
	for (int i = 0; i < 6; i++) {
		DrawRotaGraph(FishX, FishY, 1.0, 0, FishImg[i], TRUE, FALSE);
	}
	/* デバック用 */
	DrawFormatString(0, 200, 0xffffff, "playerLocationY::%f", p.GetPlayerLocationX());
	DrawFormatString(0, 230, 0xffffff, "fishLocationY::%d", FishY);
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

