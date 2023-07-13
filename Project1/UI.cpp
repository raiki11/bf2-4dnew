#include "UI.h"
#include "DxLib.h"
int UI:: m_DrawCount;
UI::UI()
{
	m_DrawCount = 0;
	LoadDivGraph("images/UI/UI_NumAnimation.png", 10, 10, 1, 32, 32, Num); // 画像の分割読み込み
	score= LoadGraph("images/UI/UI_Score.png");
	top= LoadGraph("images/UI/UI_HiScore.png");
	phase= LoadGraph("images/UI/UI_Phase.png");
	stock= LoadGraph("images/UI/UI_Stock.png");
	p_score = 3;
	p_top = 0;
	p_phase = 0;
	i = 0;
	Flag = FALSE;	
}

UI::~UI()
{
}



void UI::DrawUI() const
{
	// 現在のスコア
	DrawGraph(50, 30, score, TRUE);
	for (int a = 1; a<=6; a++) {
		DrawGraph((15*a)+60, 25, Num[i], TRUE);
	}
	
	// ハイスコア
	DrawGraph(220, 30, top, TRUE);
	for (int a = 1; a <= 6; a++) {
		DrawGraph((15 * a) + 240, 25, Num[i], TRUE);
	}

	// 2フレームに1回描画
	if (m_DrawCount % 50 == 0)
	{
		// ステージ数
		DrawGraph(220, 60, phase, TRUE);
		for (int a = 1; a <= 2; a++) {
			DrawGraph((15 * a) + 320, 50, Num[i], TRUE);
		}
	}

	
	
	DrawGraph(110, 50, stock, TRUE);

	//DrawFormatString(80, 30, 0xffffff, "%06d", p_score);
	//DrawFormatString(270, 30, 0xffffff, "%06d", p_top);
	//DrawFormatString(350,50, 0xffffff, "%02d", p_phase);
}
