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
	int n;			// Num�̕ϐ�
	int Flag;
	int i;			//	Score�̕ϐ�
	int Score[6];

	int old_score;	// �n�C�X�R�A
	
	// �X�R�A
	int p_score;
	int p_top;
	int p_phase;
	int q;
	 
	//�v���C���[�c�@�擾�p
	int p_life;
	
public:
	static int m_DrawCount;
	static int b;
	static int getsco;		// ���݂̃X�R�A
	UI();
	~UI();
	void Update(int p);

	void DrawUI() const;
	
};