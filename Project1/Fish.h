#pragma once
#include<DxLib.h>
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	
public:

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	void FishUpdate(Player p, Enemy e);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // プレイヤーがサカナが飛び出すエリアに来た時

	int FishProbability();  // サカナの出現確率の関数

	int sakana;       // 確率結果を入れる変数
	int FishImg[10];   // 画像を入れる配列 

	int FishX = 320;  // サカナのX座標
	int FishY = 500;  // サカナのY座標
	int FishFlg = 0;  // 0:プレイヤーかエネミーが入ってない 1: サカナが上に上がる 2: サカナが下に下がる
	int PFlg = 0;      // プレイヤーがサカナエリアに入っているかどうかのフラグ 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナのアニメーション開始
	int EFlg = 0;      // 敵がサカナエリアに入っているかどうかのフラグ 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナのアニメーション開始

};
