#pragma once
class Stage
{
private:
	int St_Footing;		//
	int St_Land_Left;	//
	int St_Land_Right;	//
	int St_Sea;			//海の画像
	int cloud;			//雲の画像
	int stage1;			//ステージの仮画像

public:
	//コンストラクタ
	Stage();
	~Stage();

	void DrawStage() const;
};

