#pragma once

class Thunder {
private:
	// 雷の画像
	int ThunderImg[3];
	// 雷のX座標
	float ThunderX = 300;
	// 雷のY座標
	float ThunderY = 400;
	// 雷のフラグ
	int ThunderFlg = 2; // 雷の状態（0: 移動中 1: バー接触 2: 待機状態）
	// スピードフラグ
	int ThunderSpeed;
	// 雷の角度
	float ThunderAngle = 0.625f;
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
	void ChangeAngle();

	// 雷のX座標を持ってくる関数
	float GetThunderLocationX() { return ThunderX; }
	// 雷のY座標を持ってくる関数
	float GetThunderLocationY() { return ThunderY; }
	// 雷が動いているX座標を持ってくる関数
	float GetThunderMoveLocationX() { return MoveX; }
	// 雷が動いているY座標を持ってくる関数
	float GetThunderMoveLocationY() { return MoveY; }
	
};
