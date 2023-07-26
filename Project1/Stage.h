#pragma once
#define stagenum 5	//ステージの最大数
#define maxcie 19 //ステージから取得するｘｙの最大数
#define blockxy 3
class Stage
{


private:
	int St_Footing;		//長い浮島の画像
	int St_Footing2;	//2番目に長い浮島の画像
	int St_Footing3;	//3番目に長い浮島の画像
	int St_FootingT;	//T型の浮島の画像
	int St_FootingM;	//一番小さい浮島の画像
	int St_Footing6;	//茶色の浮島
	int St_Footing7;	//i字型の浮島
	int St_Footing8;	//i字型の長い浮島
	int St_Land_Left;	//左の地面の画像
	int St_Land_Right;	//右の地面の画像
	int St_LL;			//左の茶色地面の画像
	int St_LR;			//右の茶色地面の画像
	int St_Sea;			//海の画像
	int cloud;			//雲の画像
	int stage1;			//ステージの仮画像


	int a;

	int StageXY[stagenum][maxcie][blockxy] = 
	{
		{	//ステージ１
			{175,282},//中央浮島
			{455,297},
			{0,419},//左下の地面
			{160,480},
			{480,419},//右下の地面
			{640,480}
		},
		{
			//ステージ２
			{175,282},//中央浮島
			{455,297},
			{100,169},//右上浮島
			{222,184},
			{460,152},//左上浮島
			{582,167},
			{0,419},//左下の地面
			{160,480},
			{480,419},//右下の地面
			{640,480}
		},
		{
			//ステージ３
			{160,270},//右下T浮島横Box
			{221,285},
			{181,285},//右下T浮島縦Box
			{199,333},
			{318,184},//中央T浮島横Box
			{379,199},
			{339,199},//中央T浮島縦Box
			{357,247},
			{500, 101},//左上T浮島横Box
			{561, 116},
			{521, 116},//左上T浮島縦Box
			{539, 164},
			{280, 367},//中央下の浮島
			{361, 383},
			{0,419},//左下の地面
			{160,480},
			{480,419},//右下の地面
			{640,480}
		},
		{
			//Stage4

}
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

	static float EnemyX[stagenum][6];
	static float EnemyY[stagenum][6];
	static float EnemyXY[stagenum][6][6];
	static int EnemyType[stagenum][6];
	static int Snum;	//今のステージ
	static int EnemyMax[5];//ステージごとに現れるエネミー数

	int GetStageXY(int snum, int m, int xy)
	{
		return StageXY[snum][m][xy];
	}
};

