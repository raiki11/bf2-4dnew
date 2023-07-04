#pragma once
#define stagenum 5	//ステージの最大数
#define maxcie 10 //ステージから取得するｘｙの最大数
#define blockxy 3
class Stage
{


private:
	int St_Footing;		//長い浮島の画像
	int St_Land_Left;	//左の地面の画像
	int St_Land_Right;	//右の地面の画像
	int St_Sea;			//海の画像
	int cloud;			//雲の画像
	int stage1;			//ステージの仮画像

	int StageXY[stagenum][maxcie][blockxy] = 
	{
		{	//ステージ１
			{175,282},//中央浮島
			{455,297},
			{0,419},//左下の地面
			{160,480},
			{480,419},//右下の地面
			{640,480}
		}/*,
		{
			//ステージ２

		}*/
	};

	//海の範囲
	int Seaxy[2][2] = {
		{160,419},//ｘｙ
		{480, 478}//x'y'
	};


public:
	//コンストラクタ
	Stage();
	~Stage();

	void DrawStage() const;
	void Stage1() const;
	void Stage2() const;
	void Stage3() const;
	void Stage4() const;
	void Stage5() const;
};

