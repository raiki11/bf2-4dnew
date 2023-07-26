#pragma once

class Thunder {
private:

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

	// 雷の画像
	int ThunderImg[3];

	// 雷のX座標
	int ThunderX = 300;
	// 雷のY座標
	int ThunderY = 200;
	// 雷のフラグ
	int ThunderFlg = 2; // 雷の状態（0: 移動中 1: バー接触 2: 待機状態）
	// スピードフラグ
	int ThunderSpeed; 
	// 雷の角度
	float ThunderAngle;
	// 雷が動くX座標の量
	int MoveX;
	// 雷が動くY座標の量
	int MoveY;  
	// 雷の当たり判定専用の座標
	int tx1 = ThunderX - 32;
	int tx2 = ThunderX + 32;
	int ty1 = ThunderY - 32;
	int ty1 = ThunderY + 32;

};
