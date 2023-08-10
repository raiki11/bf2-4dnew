#pragma once
#include"Player.h"
#include"Enemy.h"
class Bubble {
private:
	// バブルの画像表示
	int BubbleImg[4];

	// バブルの発生座標
	float BabbleX;
	float BabbleY;

	float babbleaddX;
	float babbleaddY;

	//バブルの移動用
	double additionX;
	double additionY;

	double rad;

	//バブルアニメーション用
	int count;
	int flg;//0:X座標プラス 1:X座標そのまま　2:X座標マイナス

	//バブルの当たり判定用

	float Px;//プレイヤーX座標
	float Py;//プレイヤーY座標
	float Pxy;//プレイヤーの中心

	float a,b,c;

	int check;//当たり判定できてるか確認用

public:
	// コンストラクタ
	Bubble();

	// デストラクタ
	~Bubble();

	// バブルのアップデート
	void BabbleUpdate(Player p,Enemy e);

	// バブルの描画
	void BabbleDraw() const;
};
