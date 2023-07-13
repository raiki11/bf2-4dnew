#pragma once
#include<DxLib.h>
//#include"GameMain.h"
#include"Player.h"
#include"Enemy.h"

class Fish {
private:
	
public:

	/*Player player;
	Enemy enemy;*/

	// コンストラクタ
	Fish();

	// デストラクタ
	~Fish();

	void FishUpdate(Player p, Enemy e);

	void FishDraw(Player p) const;

	//void PlayerFish(Player p);      // プレイヤーがサカナが飛び出すエリアに来た時

	int FishProbability();  // サカナの出現確率の関数

	int sakana;       // 確率結果を入れる変数
	int FishImg[6];   // 画像を入れる配列 

	int FishX = 320;  // サカナのX座標
	int FishY = 500;  // サカナのY座標
	int FishFlg = 0;  // 0:プレイヤーかエネミーが入ってない 1: サカナが上に上がる 2: サカナが下に下がる
	int Flg = 0;      // プレイヤーがサカナエリアに入っているかどうかのフラグ

};
