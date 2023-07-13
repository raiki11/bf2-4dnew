#pragma once
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
	
	UI();
	~UI();

	void DrawUI() const;
};