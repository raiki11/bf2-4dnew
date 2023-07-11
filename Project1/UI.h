#pragma once
class UI
{
private:
	// UI‰æ‘œ
	int score;
	int top;
	int phase;
	int stock;
	// ƒXƒRƒA
	int p_score;
	int p_top;
	int p_phase;
public:

	UI();
	~UI();

	void DrawUI() const;
};