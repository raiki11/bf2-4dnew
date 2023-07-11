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
	DrawBox(underPx0, underPy0, underPx1, underPy1, 0xff0000, TRUE);
	DrawFormatString(200, 0, 0xffffff, "x0:%d", underPx0);
	DrawFormatString(200, 20, 0xffffff, "y0:%d", underPy0);
	DrawFormatString(200, 40, 0xffffff, "x1:%d", underPx1);
	DrawFormatString(200, 60, 0xffffff, "y1:%d", underPy1);
}

int HitBox::PlayerAndStageUnder(Player p, Stage s)
{
	underPx0 = p.GetPlayerLocationX() - 32;
	underPy0 = p.GetPlayerLocationY() + 32;
	underPx1 = p.GetPlayerLocationX() + 32;
	underPy1 = p.GetPlayerLocationY() + 40;		//óví≤êÆ

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= underPx1 && s.GetStageXY(0, i + 1, 0) >= underPx0 &&
			s.GetStageXY(0, i, 1) <= underPy1 && s.GetStageXY(0, i + 1, 1) >= underPy0) {

			return TRUE;
		}
	}
	return FALSE;
}
