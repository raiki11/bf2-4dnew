#pragma once
#include "AbstractScene.h"
class UI   
{
private:
	// UI画像
	int score;
	int top;
	int phase;
	int stock;
	int Num[10];
	int a;			// Numの変数
	int Flag;
	int i;			//	Scoreの変数
	int Score[6];
	

	
	// スコア
	int p_score;
	int p_top;
	int p_phase;
	int q;
	 
	//プレイヤー残機取得用
	int p_life;
	
public:
	static int m_DrawCount;
	static int b;
	UI();
	~UI();
	void Update(int p);

	void DrawUI() const;
	
};