#pragma once
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

public:
	
	UI();
	~UI();

	void DrawUI() const;
};