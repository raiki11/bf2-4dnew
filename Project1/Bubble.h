#pragma once

class Bubble {
private:
	// バブルの画像表示
	int BubbleImg[4];

	// バブルの発生座標
	float BabbleX;
	float BabbleY;

	double rad;
	int count;
	int flg;//0:X座標プラス 1:X座標そのまま　2:X座標マイナス

	//バブルの移動用
	double additionX;
	double additionY;

	//バブルの当たり判定用

public:
	// コンストラクタ
	Bubble();

	// デストラクタ
	~Bubble();

	// バブルのアップデート
	void BabbleUpdate();

	// バブルの描画
	void BabbleDraw() const;
};
