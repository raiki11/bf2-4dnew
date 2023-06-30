#pragma once
class Stage
{
private:
	int Cloud;//雲の画像
	int St_Footing;//
	int St_Land_Left;
	int St_Land_Right;
	int St_Sea;
	int stage1;

public:
	//コンストラクタ
	Stage();
	~Stage();

	void DrawStage() const;
};

