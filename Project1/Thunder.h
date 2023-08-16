#pragma once
#define _USE_MATH_DEFINES
#include<math.h>

class Thunder {
private:
	// 雷の画像
	int ThunderImg[3];
	// 雷のX座標
	float ThunderX;
	// 雷のY座標
	float ThunderY;
	// 雷のフラグ
	int ThunderFlg; // 雷の状態（0: 移動中 1: バー接触 2: 待機状態）
	
	// 雷が動くX座標の量
	float MoveX;
	// 雷が動くY座標の量
	float MoveY;
	//// 雷の当たり判定専用の座標
	//int tx1 = ThunderX - 32;
	//int tx2 = ThunderX + 32;
	//int ty1 = ThunderY - 32;
	//int ty2 = ThunderY + 32;

public:
	// コンストラクタ
	Thunder();

	// デストラクタ
	~Thunder();

	// 雷のアップデート
	void ThunderUpdate();

	// 雷の描画
	void ThunderDraw() const;

	// 角度調整
	void ChangeAngle(/*float MoveX,float MoveY*/);

	// スピードフラグ
	int ThunderSpeed;
	// 雷の角度
	float ThunderAngle;


	//座標を獲得、追記者 北村
	float GetThunderX() { return ThunderX; }
	float GetThunderY() { return ThunderY; }

	// 動く量を取得
	float GetThunderMoveLocationX() { return MoveX; }
	float GetThunderMoveLocationY() { return MoveY; }
};
