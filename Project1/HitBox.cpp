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
	/*DrawFormatString(200, 0, 0xffffff, "x0:%d", px0);
	DrawFormatString(200, 20, 0xffffff, "y0:%d", py0);
	DrawFormatString(200, 40, 0xffffff, "x1:%d", px1);
	DrawFormatString(200, 60, 0xffffff, "y1:%d", py1);*/
}

int HitBox::PlayerAndStageUnder(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() - 15;
	py0 = p.GetPlayerLocationY() + 32;
	px1 = p.GetPlayerLocationX() + 15;
	py1 = p.GetPlayerLocationY() + 32;		//óví≤êÆ

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
	px0 = p.GetPlayerLocationX() - 25;
	py0 = p.GetPlayerLocationY() - 22;
	px1 = p.GetPlayerLocationX() + 25;
	py1 = p.GetPlayerLocationY() - 22;

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
	px0 = p.GetPlayerLocationX() + 20;
	py0 = p.GetPlayerLocationY() - 15;
	px1 = p.GetPlayerLocationX() + 20;
	py1 = p.GetPlayerLocationY() + 25;

	if (p.GetPlayerMoveX() > 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= px1 && s.GetStageXY(0, i + 1, 0) >= px0 &&
				s.GetStageXY(0, i, 1) <= py1 && s.GetStageXY(0, i + 1, 1) >= py0) {

				return TRUE;
			}
		}
	}
	
	return FALSE;
}

int HitBox::PlayerAndStageLeft(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() - 20;
	py0 = p.GetPlayerLocationY() - 15;
	px1 = p.GetPlayerLocationX() - 20;
	py1 = p.GetPlayerLocationY() + 25;

	if (p.GetPlayerMoveX() < 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= px1 && s.GetStageXY(0, i + 1, 0) >= px0 &&
				s.GetStageXY(0, i, 1) <= py1 && s.GetStageXY(0, i + 1, 1) >= py0) {

				return TRUE;
			}
		}
	}

	return FALSE;
}
