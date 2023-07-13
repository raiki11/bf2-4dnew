#pragma once
#include "AbstractScene.h"
class UI
{
private:
	// UI‰æ‘œ
	int score;
	int top;
	int phase;
	int stock;
	int Num[10];
	int Flag;
	int i;
	
	// ƒXƒRƒA
	int p_score;
	int p_top;
	int p_phase;
	 

	
public:
	static int m_DrawCount;

	UI();
	~UI();
	

	void DrawUI() const;
	
};