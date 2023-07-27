#pragma once
#include "Player.h"
#include "Stage.h"
#include"Enemy.h"
#include "Thunder.h"

class HitBox
{
private:
	int px0, px1, py0, py1;
	int ex0, ex1, ey0, ey1;
	int tx0, tx1, ty0, ty1;

	int underPx0, underPy0, underPx1, underPy1;	//プレイヤーの接地判定

	int old, now;
	int old1, now1;
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

	int PlayerAndThunder(Player p, Thunder t);

	int PlayerAndEnemy(Player p,Enemy e);
	int PlayerBalloonAndEnemy(Player p,Enemy e);
	int PlayerAndEnemyBalloon(Player p,Enemy e);
};

