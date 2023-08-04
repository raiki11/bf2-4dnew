#pragma once

class Bubble {
private:

public:
	// コンストラクタ
	Bubble();

	// デストラクタ
	~Bubble();

	// バブルのアップデート
	void BabbleUpdate();

	// バブルの描画
	void BabbleDraw() const;

	// バブルの画像表示
	int BubbleImg[4];

	// バブルの座標
	int BabbleX = 400;
	int BabbleY = 300;

};
