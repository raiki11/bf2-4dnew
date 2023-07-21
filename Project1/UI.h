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
	int Flag;
	int i;


	
	// スコア
	int p_score;
	int p_top;
	int p_phase;
	 
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