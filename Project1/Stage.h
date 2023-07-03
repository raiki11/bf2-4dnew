#pragma once
class Stage
{
private:
	int St_Footing;		//長い浮島の画像
	int St_Land_Left;	//左の地面の画像
	int St_Land_Right;	//右の地面の画像
	int St_Sea;			//海の画像
	int cloud;			//雲の画像
	int stage1;			//ステージの仮画像

public:
	//コンストラクタ
	Stage();
	~Stage();

	void DrawStage() const;
};

