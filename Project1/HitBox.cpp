#include "HitBox.h"
#include "DxLib.h"
#include "Enemy.h"
//int Enemy::Eflg = FALSE;
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
	//DrawBox(underPx0, underPy0, underPx1, underPy1, 0xff0000, FALSE);
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

	for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
		if (s.GetStageXY(Stage::Snum, i, 0) <= px1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= px0 &&
			s.GetStageXY(Stage::Snum, i, 1) <= py1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= py0) {

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

	for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
		if (s.GetStageXY(Stage::Snum, i, 0) <= px1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= px0 &&
			s.GetStageXY(Stage::Snum, i, 1) <= py1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= py0) {

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
		for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
			if (s.GetStageXY(Stage::Snum, i, 0) <= px1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= px0 &&
				s.GetStageXY(Stage::Snum, i, 1) <= py1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= py0) {

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
		for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
			if (s.GetStageXY(Stage::Snum, i, 0) <= px1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= px0 &&
				s.GetStageXY(Stage::Snum, i, 1) <= py1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= py0) {

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

	for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
		if (s.GetStageXY(Stage::Snum, i, 0) <= ex1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= ex0 &&
			s.GetStageXY(Stage::Snum, i, 1) <= ey1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= ey0) {

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

	for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
		if (s.GetStageXY(Stage::Snum, i, 0) <= ex1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= ex0 &&
			s.GetStageXY(Stage::Snum, i, 1) <= ey1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= ey0) {

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
		for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
			if (s.GetStageXY(Stage::Snum, i, 0) <= ex1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= ex0 &&
				s.GetStageXY(Stage::Snum, i, 1) <= ey1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= ey0) {

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
		for (int i = 0; i < Stage::MaxCoord[Stage::Snum]; i += 2) {
			if (s.GetStageXY(Stage::Snum, i, 0) <= ex1 && s.GetStageXY(Stage::Snum, i + 1, 0) >= ex0 &&
				s.GetStageXY(Stage::Snum, i, 1) <= ey1 && s.GetStageXY(Stage::Snum, i + 1, 1) >= ey0) {

				return TRUE;
			}
		}
	}

	return FALSE;
}

int HitBox::ThunderAndStageUnder(Thunder th, Stage s) 
{
	tx0 = th.GetThunderX() - 32;
	ty0 = th.GetThunderY() + 32;
	tx1 = th.GetThunderX() + 32;
	ty1 = th.GetThunderY() + 32;

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= tx1 && s.GetStageXY(0, i + 1, 0) >= tx0 &&
			s.GetStageXY(0, i, 1) <= ty1 && s.GetStageXY(0, i + 1, 1) >= ty0) {

			return TRUE;
		}
	}
	return FALSE;
}

int HitBox::ThunderAndStageTop(Thunder th, Stage s)
{
	tx0 = th.GetThunderX() - 32;
	ty0 = th.GetThunderY() - 32;
	tx1 = th.GetThunderX() + 32;
	ty1 = th.GetThunderY() - 32;

	for (int i = 0; i < 6; i += 2) {
		if (s.GetStageXY(0, i, 0) <= tx1 && s.GetStageXY(0, i + 1, 0) >= tx0 &&
			s.GetStageXY(0, i, 1) <= ty1 && s.GetStageXY(0, i + 1, 1) >= ty0) {

			return TRUE;
		}
	}

	return FALSE;
}

int HitBox::ThunderAndStageRight(Thunder th, Stage s)
{
	tx0 = th.GetThunderX() + 32;
	ty0 = th.GetThunderY() - 32;
	tx1 = th.GetThunderX() + 32;
	ty1 = th.GetThunderY() + 32;

	if (th.GetThunderMoveLocationX() > 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
				s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

				return TRUE;
			}
		}
	}
	return FALSE;
}

int HitBox::ThunderAndStageLeft(Thunder th, Stage s)
{
	tx0 = th.GetThunderX() - 32;
	ty0 = th.GetThunderY() - 32;
	tx1 = th.GetThunderX() - 32;
	ty1 = th.GetThunderY() + 32;

	if (th.GetThunderMoveLocationX() < 0) {
		for (int i = 0; i < 6; i += 2) {
			if (s.GetStageXY(0, i, 0) <= ex1 && s.GetStageXY(0, i + 1, 0) >= ex0 &&
				s.GetStageXY(0, i, 1) <= ey1 && s.GetStageXY(0, i + 1, 1) >= ey0) {

				return TRUE;

			}
		}
	}
	return FALSE;
}

//	return FALSE;
//}

int HitBox::PlayerAndThunder(Player p, Thunder t)
{
	px0 = p.GetPlayerLocationX() - 20;
	py0 = p.GetPlayerLocationY() - 20;
	px1 = p.GetPlayerLocationX() + 20;
	py1 = p.GetPlayerLocationY() + 20;

	tx0 = t.GetThunderX() - 10;
	ty0 = t.GetThunderY() - 10;
	tx1 = t.GetThunderX() + 10;
	ty1 = t.GetThunderY() + 10;

	if (tx0 <= px1 && tx1 >= px0 &&
		ty0 <= py1 && ty1 >= py0) {

		return TRUE;
	}


	return 0;
}

int HitBox::PlayerAndEnemy(Player p, Enemy e)
{
	px0 = p.GetPlayerLocationX() - 10;
	py0 = p.GetPlayerLocationY() - 5;
	px1 = p.GetPlayerLocationX() + 15;
	py1 = p.GetPlayerLocationY() + 32;

	ex0 = e.GetEnemyLocationX() - 10;
	ey0 = e.GetEnemyLocationY() - 5;
	ex1 = e.GetEnemyLocationX() + 15;
	ey1 = e.GetEnemyLocationY() + 32;

	if (ex0 <= px1 && ex1 >= px0 &&
		ey0 <= py1 && ey1 >= py0) {
		Enemy::Eflg = TRUE;
		return TRUE;
	}

	return 0;
}

int HitBox::PlayerBalloonAndEnemy(Player p, Enemy e)
{
	px0 = p.GetPlayerLocationX() - 22;
	py0 = p.GetPlayerLocationY() - 20;
	px1 = p.GetPlayerLocationX() + 22;
	py1 = p.GetPlayerLocationY() + 5;

	ex0 = e.GetEnemyLocationX() - 10;
	ey0 = e.GetEnemyLocationY();
	ex1 = e.GetEnemyLocationX() + 15;
	ey1 = e.GetEnemyLocationY() + 32;


	underPx0 = px0;
	underPy0 = py0;
	underPx1 = px1;
	underPy1 = py1;

	old = now;

	if (ex0 <= px1 && ex1 >= px0 &&
		ey0 <= py1 && ey1 >= py0) {

		now = TRUE;

		//if (old == FALSE) {
			return TRUE;
		//}
	}
	else {
		now = FALSE;
	}
	return 0;
}

int HitBox::PlayerAndEnemyBalloon(Player p, Enemy e)
{
	px0 = p.GetPlayerLocationX() - 10;
	py0 = p.GetPlayerLocationY();
	px1 = p.GetPlayerLocationX() + 15;
	py1 = p.GetPlayerLocationY() + 32;

	ex0 = e.GetEnemyLocationX() - 10;
	ey0 = e.GetEnemyLocationY() - 20;
	ex1 = e.GetEnemyLocationX() + 10;
	ey1 = e.GetEnemyLocationY() + 5;

	old1 = now1;

	if (ex0 <= px1 && ex1 >= px0 &&
		ey0 <= py1 && ey1 >= py0) {

		now1 = TRUE;

		//if (old1 == FALSE) {
			return TRUE;
		//}
	}
	else {
		now1 = FALSE;
	}
	return 0;
}

int HitBox::FishAndPlayer(Fish f, Player p)
{
	fx0 = f.FishLocationX() - 20;
	fy0 = f.FishLocationY() - 20;
	fx1 = f.FishLocationX() + 20;
	fy1 = f.FishLocationY() + 20;

	px0 = p.GetPlayerLocationX() - 20;
	py0 = p.GetPlayerLocationY() - 20;
	px1 = p.GetPlayerLocationX() + 20;
	py1 = p.GetPlayerLocationY() + 20;

	if (fx0 <= px1 && fx1 >= px0 &&
		fy0 <= py1 && fy1 >= py0) {
		return TRUE;
	}
	else return FALSE;
}