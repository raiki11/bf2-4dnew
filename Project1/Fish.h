#pragma once
#include<DxLib.h>
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	int Time;
	int fpscount;
	int i;
	
	int FishFlg;  // 0:プレイヤーかエネミーが入ってない 1: サカナが上に上がる 2: サカナが下に下がる
	

public:

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	void FishUpdate(Player p, Enemy e[]);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // プレイヤーがサカナが飛び出すエリアに来た時

	int FishProbability();  // サカナの出現確率の関数
	bool Orientation();  // 向きを決める関数

	void FishUpAnimation(); // サカナの上がるアニメーション
	void FishDownAnimation(); // サカナの下がるアニメーション
	void FishPlayerHitAnimation(Player p); // サカナに当たった時のアニメーション
	void FishEnemyHitAnimation(Enemy e[]); // サカナに当たった時のアニメーション

	float FishLocationX() { return FishX; }
	float FishLocationY() { return FishY; }

	int FishAnimation() { return i; }

	float FishX = 320;  // サカナのX座標
	float FishY = 420;  // サカナのY座標

	int sakana;       // 確率結果を入れる変数
	int FishImg[10];   // 画像を入れる配列 

	// プレイヤーがサカナエリアに入っているかどうかのフラグ 
	// 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナの上がるアニメーション 3: サカナが下がるアニメーション 4: サカナエリアに居続けてる状態
	int PFlg;
	int EFlg;      // 敵がサカナエリアに入っているかどうかのフラグ 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナのアニメーション開始      
	bool FishOrientation;  // サカナの向きを決める
	int sakanaOrientation;  // サカナの向きを決める乱数
};
