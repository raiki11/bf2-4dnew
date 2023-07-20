#pragma once
#include "Player.h"
#include "Stage.h"
#include"Enemy.h"

class HitBox
{
private:
	int px0, px1, py0, py1;
	int ex0, ex1, ey0, ey1;
	int underPx0, underPy0, underPx1, underPy1;	//プレイヤーの接地判定
public:
	HitBox();
	~HitBox();

	void UpdetaHitBox(Player p, Stage s);
	void DrawHitBox() const;
	
	int PlayerAndStageUnder(Player p, Stage s);
	int PlayerAndStageTop(Player p, Stage s);
	int PlayerAndStageRight(Player p, Stage s);
	int PlayerAndStageLeft(Player p, Stage s);


	int EnemyAndStageUnder(Enemy e, Stage s);
	int EnemyAndStageTop(Enemy e, Stage s);
	int EnemyAndStageRight(Enemy e, Stage s);
	int EnemyAndStageLeft(Enemy e, Stage s);
};

