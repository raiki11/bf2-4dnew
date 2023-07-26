#pragma once

class Babble {
private:

public:
	// コンストラクタ
	Babble();

	// デストラクタ
	~Babble();

	// バブルのアップデート
	void BabbleUpdate();

	// バブルの描画
	void BabbleDraw() const;

	// バブルの座標
	int BabbleX;
	int BabbleY;

};
