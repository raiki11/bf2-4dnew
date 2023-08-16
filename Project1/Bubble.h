#pragma once
#include"Player.h"
#include"Enemy.h"
class Bubble {
private:
	// バブルの画像表示
	int BubbleImg[4];

	// バブルの発生座標
	float BabbleY;

	int flg;//座標を一度だけ受け取る用

	//バブルの移動用
	float babbleaddX;
	float babbleaddY;


	//バブルアニメーション用
	int count;


	//バブルの当たり判定用

	float Px;//プレイヤーX座標
	float Py;//プレイヤーY座標
	float Pxy;//プレイヤーの中心

	float a,b,c;

	//当たり判定できてるか確認用
	int check;//0:当たってない　1:当たった　2:スコア表示
	

	int bimgnum;	//バブルの画像切り替え用
	int bimgcnt;    //バブルの画像切り替えカウント

	float amp;	//振幅
	float fre;	//頻度

	int BDeleteFlg;	//シャボン玉デリートフラグ
	int BscoFlg;	//スコアを一度だけ増やすフラグ

	int Bscoimg;	//スコア画像表示フラグ

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
