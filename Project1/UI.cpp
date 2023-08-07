#include "UI.h"
#include "DxLib.h"
#include "FPS.h"
#include"Enemy.h"
#include "Stage.h"
int UI:: m_DrawCount;
int UI::b;
int UI::getsco;// 現在のスコア
int UI::old_score = 0;// ハイスコア
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
	n = 0;
	q = 100000;
	//getsco = 0;	// 現在のスコア
	old_score = 0;	// ハイスコア
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

	if (getsco >= 999999)
	{
		getsco = 999999;
	}
	else {
		getsco = Enemy::Score;

	}
	if (getsco >= old_score)
	{
		old_score = getsco;
	}
	/*else {

	}*/
}







void UI::DrawUI() const
{
	// 現在のスコア
	DrawGraph(60, 30, score, TRUE);
	DrawGraph(80, 25, Num[(getsco % 1000000)/100000], TRUE);
	DrawGraph(100, 25, Num[(getsco % 100000)/10000], TRUE);
	DrawGraph(120, 25, Num[(getsco % 10000) / 1000], TRUE);
	DrawGraph(140, 25, Num[(getsco % 1000)/ 100], TRUE);
	DrawGraph(160, 25, Num[(getsco % 100) / 10], TRUE);
	DrawGraph(180, 25, Num[(getsco % 10)], TRUE);

	/*DrawFormatString(400, 400, 0xffffff, "%d", Score[0]);
	DrawFormatString(400, 410, 0xffffff, "%d", Score[1]);
	DrawFormatString(400, 420, 0xffffff, "%d", Score[2]);
	DrawFormatString(400, 430, 0xffffff, "%d", Score[3]);
	DrawFormatString(400, 440, 0xffffff, "%d", Score[4]);*/
	//DrawFormatString(400, 400, 0xffffff, "getsco%d", getsco);
	//DrawFormatString(400, 380, 0xffffff, "getsco%d", (getsco - (getsco % q)) / q);
	
	// ハイスコア
	
		DrawGraph(220, 30, top, TRUE);
		
		DrawGraph(260, 25, Num[(old_score % 1000000) / 100000], TRUE);
		DrawGraph(280, 25, Num[(old_score % 100000) / 10000], TRUE);
		DrawGraph(300, 25, Num[(old_score % 10000) / 1000], TRUE);
		DrawGraph(320, 25, Num[(old_score % 1000) / 100], TRUE);
		DrawGraph(340, 25, Num[(old_score % 100) / 10], TRUE);
		DrawGraph(360, 25, Num[(old_score % 10)], TRUE);
	
	

	

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
