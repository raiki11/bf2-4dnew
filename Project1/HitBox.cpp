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
	px0 = p.GetPlayerLocationX() - 10;
	py0 = p.GetPlayerLocationY() + 32;
	px1 = p.GetPlayerLocationX() + 10;
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
	px0 = p.GetPlayerLocationX() - 22;
	py0 = p.GetPlayerLocationY() - 22;
	px1 = p.GetPlayerLocationX() + 22;
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
	py1 = p.GetPlayerLocationY() + 30;

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
	py1 = p.GetPlayerLocationY() + 30;

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

int HitBox::EnemyAndStageUnder(Enemy e, Stage s)
{
	ex0 = e.GetEnemyLocationX() - 15;
	ey0 = e.GetEnemyLocationY() + 32;
	ex1 = e.GetEnemyLocationX() + 15;
	ey1 = e.GetEnemyLocationY() + 32;		//óví≤êÆ

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
			s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

			return TRUE;
		}
	}
	return FALSE;
}

int HitBox::EnemyAndStageTop(Enemy e, Stage s)
{
	ex0 = e.GetEnemyLocationX() - 25;
	ey0 = e.GetEnemyLocationY() - 22;
	ex1 = e.GetEnemyLocationX() + 25;
	ey1 = e.GetEnemyLocationY() - 22;

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
			s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

			return TRUE;
		}
	}

	return FALSE;
}

int HitBox::EnemyAndStageRight(Enemy e, Stage s)
{
	ex0 = e.GetEnemyLocationX() + 20;
	ey0 = e.GetEnemyLocationY() - 15;
	ex1 = e.GetEnemyLocationX() + 20;
	ey1 = e.GetEnemyLocationY() + 25;

	if (e.GetEnemyMoveX() > 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
				s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

				return TRUE;
			}
		}
	}

	return FALSE;
}

int HitBox::EnemyAndStageLeft(Enemy e, Stage s)
{
	ex0 = e.GetEnemyLocationX() - 20;
	ey0 = e.GetEnemyLocationY() - 15;
	ex1 = e.GetEnemyLocationX() - 20;
	ey1 = e.GetEnemyLocationY() + 25;

	if (e.GetEnemyMoveX() < 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
				s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

				return TRUE;
			}
		}
	}

	return FALSE;
}
