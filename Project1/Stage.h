#pragma once
#define stagenum 5	//Xe[WÌÅå
#define maxcie 19 //Xe[W©çæ¾·éÌÅå
#define blockxy 3
class Stage
{


private:
	int St_Footing;		//·¢Ìæ
	int St_Footing2;	//2ÔÚÉ·¢Ìæ
	int St_Footing3;	//3ÔÚÉ·¢Ìæ
	int St_FootingT;	//T^ÌÌæ
	int St_FootingM;	//êÔ¬³¢Ìæ
	int St_Footing6;	//FÌ
	int St_Footing7;	//i^Ì
	int St_Footing8;	//i^Ì·¢
	int St_Land_Left;	//¶ÌnÊÌæ
	int St_Land_Right;	//EÌnÊÌæ
	int St_LL;			//¶ÌFnÊÌæ
	int St_LR;			//EÌFnÊÌæ
	int St_Sea;			//CÌæ
	int cloud;			//_Ìæ
	int stage1;			//Xe[WÌ¼æ

	int a;

	int StageXY[stagenum][maxcie][blockxy] = 
	{
		{	//Xe[WP
			{175,282},//
			{455,297},
			{0,419},//¶ºÌnÊ
			{160,480},
			{480,419},//EºÌnÊ
			{640,480}
		},
		{
			//Xe[WQ
			{175,282},//
			{455,297},
			{100,169},//Eã
			{222,184},
			{460,152},//¶ã
			{582,167},
			{0,419},//¶ºÌnÊ
			{160,480},
			{480,419},//EºÌnÊ
			{640,480}
		},
		{
			//Xe[WR
			{160,270},//EºT¡Box
			{221,285},
			{181,285},//EºTcBox
			{199,333},
			{318,184},//T¡Box
			{379,199},
			{339,199},//TcBox
			{357,247},
			{500, 101},//¶ãT¡Box
			{561, 116},
			{521, 116},//¶ãTcBox
			{539, 164},
			{280, 367},//ºÌ
			{361, 383},
			{0,419},//¶ºÌnÊ
			{160,480},
			{480,419},//EºÌnÊ
			{640,480}
		},
		{
			//Stage4
}
	};

	//CÌÍÍ
	int Seaxy[2][2] = {
		{160,419},//
		{480, 478}//x'y'
	};


public:
	//RXgN^
	Stage();
	~Stage();

	void DrawStage() const;
	void Stage1() const;
	void Stage2() const;
	void Stage3() const;
	void Stage4() const;
	void Stage5() const;
};

