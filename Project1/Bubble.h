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

	int bimgnum;	//バブルの画像切り替え用
	int bimgcnt;    //バブルの画像切り替えカウント

	float amp;	//振幅
	float fre;	//頻度

	int BDeleteFlg;	//シャボンだまデリートフラグ

public:

	// コンストラクタ
	Bubble();

	// デストラクタ
	~Bubble();

	// バブルのアップデート
	void BubbleUpdate(Player p, int ex);

	// バブルの描画
	void BubbleDraw() const;

	int BubbleDelete();
};
