#include "UI.h"
#include "DxLib.h"
#include "FPS.h"
//#include "Enemy.h"
int UI:: m_DrawCount;
int UI::b;
UI::UI()
{
	m_DrawCount = 0;
	LoadDivGraph("images/UI/UI_NumAnimation.png", 10, 10, 1, 32, 32, Num); // �摜�̕����ǂݍ���
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
	
}

UI::~UI()
{
}

void UI::Update()
{
	m_DrawCount++;

	if (m_DrawCount == 60) {
		b++;
	}

	if (m_DrawCount >= 70) {		
		m_DrawCount = 0;
	}

}






void UI::DrawUI() const
{
	// ���݂̃X�R�A
	DrawGraph(50, 30, score, TRUE);
	for (int a = 1; a<=6; a++) {
		DrawGraph((20*a)+50, 25, Num[9], TRUE);
	}
	
	// �n�C�X�R�A
	DrawGraph(220, 30, top, TRUE);
	for (int a = 1; a <= 6; a++) {
		DrawGraph((20 * a) + 240, 25, Num[i], TRUE);
	}

	if (b <= 3)			// 4��\��
	{
		// �X�e�[�W��
		if (m_DrawCount <= 60) {
			DrawGraph(220, 60, phase, TRUE);
			for (int a = 1; a <= 2; a++) {
				DrawGraph((15 * a) + 320, 50, Num[i], TRUE);
			}
		}
	}

	DrawFormatString(400, 300, GetColor(255, 0, 0), "UI_FPS:%d", m_DrawCount);
	
	// ���C�t
	DrawGraph(130, 50, stock, TRUE);



	//DrawFormatString(80, 30, 0xffffff, "%06d", p_score);
	//DrawFormatString(270, 30, 0xffffff, "%06d", p_top);
	//DrawFormatString(350,50, 0xffffff, "%02d", p_phase);
}
