#pragma once
class UI
{
private:
	// UI�摜
	int score;
	int top;
	int phase;
	int stock;
	// �X�R�A
	int p_score;
	int p_top;
	int p_phase;
public:

	UI();
	~UI();

	void DrawUI() const;
};