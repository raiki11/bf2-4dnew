#pragma once
#include "AbstractScene.h"
class UI   
{
private:
	// UI�摜
	int score;
	int top;
	int phase;
	int stock;
	int Num[10];
	int Flag;
	int i;


	
	// �X�R�A
	int p_score;
	int p_top;
	int p_phase;
	 
	//�v���C���[�c�@�擾�p
	int p_life;
	
public:
	static int m_DrawCount;
	static int b;
	UI();
	~UI();
	void Update(int p);

	void DrawUI() const;
	
};