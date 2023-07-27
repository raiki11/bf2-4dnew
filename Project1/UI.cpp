#include "UI.h"
#include "DxLib.h"
#include "FPS.h"
#include"Enemy.h"
#include "Stage.h"
int UI:: m_DrawCount;
int UI::b;
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
	b = 0;
	p_life = 0;
	q = 100000;
	a = 0;
	for (int i = 0; i > 6; i++) {
		Score[i] = 0;
	}
}

UI::~UI()
{
}

void UI::Update(int p)
{
	m_DrawCount++;

	if (m_DrawCount == 60) {
		b++;
	}

	if (m_DrawCount >= 70) {		
		m_DrawCount = 0;
	}

	p_life = p;

	for (int i = 0;  i>5; i++)
	{
		Score[i] = Enemy::GetScore() / q;
		i = a;
		q = q / 10;
	}

}






void UI::DrawUI() const
{
	// 現在のスコア
	DrawGraph(50, 30, score, TRUE);
	DrawGraph(240, 25, Num[a], TRUE);

	
	// ハイスコア
	DrawGraph(220, 30, top, TRUE);
	for (int a = 1; a <= 5; a++) {
		DrawGraph((20 * a) + 240, 25, Num[i], TRUE);
	}

	if (b <= 3)			// 4回表示
	{
		// ステージ数
		if (m_DrawCount <= 60) {
			DrawGraph(220, 60, phase, TRUE);
			DrawGraph(335, 50, Num[0], TRUE);
			DrawGraph( 350, 50, Num[Stage::Snum + 1], TRUE);
			/*for (int a = 1; a <= 2; a++) {
				DrawGraph((15 * a) + 320, 50, Num[Stage::Snum+1], TRUE);
			}*/
		}
	}

	//DrawFormatString(400, 300, GetColor(255, 0, 0), "UI_FPS:%d", m_DrawCount);
	
	// ライフ
	for (int j = 0; j < p_life; j++)
	{
		DrawGraph(130 + (j * 15), 50, stock, TRUE);
	}

	


	//DrawFormatString(80, 30, 0xffffff, "%06d", p_score);
	//DrawFormatString(270, 30, 0xffffff, "%06d", p_top);
	//DrawFormatString(350,50, 0xffffff, "%02d", p_phase);
}
