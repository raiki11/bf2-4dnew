#pragma once
#include<DxLib.h>
#include"Player.h"
#include"Enemy.h"

#define FishAreaX0    160
#define FishAreaX1    480
#define FishAreaY     419


class Fish {
private:
	int Time;
	int fpscount;
	int i;
	

	int Fishmove;
	int Fy;
	int Fx;
	int Fimg;
	int count;
public:

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	void FishUpdate(Player p, Enemy e);

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

	int FishTime() { return Time; }
	int FPSCount() { return fpscount; }

	float FishX = 320;  // サカナのX座標
	float FishY = 420;  // サカナのY座標

	void EdeadFish();		//くち動かしてさがる
	void EdeadFishAnim()const;	//やられたエネミー回収

	int sakana;       // 確率結果を入れる変数
	int FishImg[10];   // 画像を入れる配列 

	// プレイヤーがサカナエリアに入っているかどうかのフラグ 
	// 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナの上がるアニメーション 3: サカナが下がるアニメーション 4: サカナエリアに居続けてる状態
	int PFlg;
	int EFlg;      // 敵がサカナエリアに入っているかどうかのフラグ 0: サカナエリアに入ってない 1: サカナエリアに入った 2: サカナのアニメーション開始 
	int FishFlg;  // 0:プレイヤーかエネミーが入ってない 1: サカナが上に上がる 2: サカナが下に下がる
	bool FishOrientation;  // サカナの向きを決める
	int sakanaOrientation;  // サカナの向きを決める乱数

	static bool FyInitFlg;
};
