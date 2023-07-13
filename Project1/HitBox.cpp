#include "HitBox.h"
#include "DxLib.h"

HitBox::HitBox()
{
}

HitBox::~HitBox()
{
}

void HitBox::UpdetaHitBox(Player p, Stage s)
{
	PlayerAndStageUnder(p, s);
}

void HitBox::DrawHitBox() const
{
	DrawBox(px0, py0, px1, py1, 0xff0000, TRUE);
	DrawFormatString(200, 0, 0xffffff, "x0:%d", underPx0);
	DrawFormatString(200, 20, 0xffffff, "y0:%d", underPy0);
	DrawFormatString(200, 40, 0xffffff, "x1:%d", underPx1);
	DrawFormatString(200, 60, 0xffffff, "y1:%d", underPy1);
}

int HitBox::PlayerAndStageUnder(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() - 32;
	py0 = p.GetPlayerLocationY() + 32;
	px1 = p.GetPlayerLocationX() + 32;
	py1 = p.GetPlayerLocationY() + 40;		//óví≤êÆ

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= px1 && s.GetStageXY(0, i + 1, 0) >= px0 &&
			s.GetStageXY(0, i, 1) <= py1 && s.GetStageXY(0, i + 1, 1) >= py0) {

			return TRUE;
		}
	}
	return FALSE;
}

int HitBox::PlayerAndStageTop(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() - 32;
	py0 = p.GetPlayerLocationY() - 32;
	px1 = p.GetPlayerLocationX() + 32;
	py1 = p.GetPlayerLocationY() - 40;

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= px1 && s.GetStageXY(0, i + 1, 0) >= px0 &&
			s.GetStageXY(0, i, 1) <= py1 && s.GetStageXY(0, i + 1, 1) >= py0) {

			return TRUE;
		}
	}

	return FALSE;
}

int HitBox::PlayerAndStageRight(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() + 32;
	py0 = p.GetPlayerLocationY() - 20;
	px1 = p.GetPlayerLocationX() + 40;
	py1 = p.GetPlayerLocationY() + 30;

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= px1 && s.GetStageXY(0, i + 1, 0) >= px0 &&
			s.GetStageXY(0, i, 1) <= py1 && s.GetStageXY(0, i + 1, 1) >= py0) {

			return TRUE;
		}
	}

	return FALSE;
}

int HitBox::PlayerAndStageLeft(Player p, Stage s)
{
	return 0;
}
