#include "UI.h"
#include "DxLib.h"
UI::UI()
{

	score= LoadGraph("images/UI/UI_Score.png");
	top= LoadGraph("images/UI/UI_HiScore.png");
	phase= LoadGraph("images/UI/UI_Phase.png");
	stock= LoadGraph("images/UI/UI_Stock.png");
	p_score = 0;
	p_top = 0;
	p_phase = 0;
	i = 0;
	Flag = FALSE;
	LoadDivGraph("images/UI/UI_NumAnimation.png", 10, 1, 10, 32, 32, Num, TRUE); // âÊëúÇÃï™äÑì«Ç›çûÇ›
}

UI::~UI()
{
}

void UI::DrawUI() const
{
	DrawRotaGraph(0,0,1.0,0,Num[1],TRUE,Flag);
	DrawGraph(50,30 , score, TRUE);
	DrawGraph(220, 30, top, TRUE);
	DrawGraph(220, 50, phase, TRUE);
	DrawGraph(110, 50, stock, TRUE);

	DrawFormatString(80, 30, 0xffffff, "%06d", p_score);
	DrawFormatString(270, 30, 0xffffff, "%06d", p_top);
	DrawFormatString(350,50, 0xffffff, "%02d", p_phase);
}
