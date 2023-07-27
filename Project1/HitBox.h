#pragma once
#include "Player.h"
#include "Stage.h"
#include"Enemy.h"
#include"Fish.h"
#include"Thunder.h"

class HitBox
{
private:
	int px0, px1, py0, py1;
	int ex0, ex1, ey0, ey1;
	int tx0, tx1, ty0, ty1;
	int fx0, fx1, fy0, fy1;
	
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

	int ThunderAndStageUnder(Thunder th, Stage s);
	int ThunderAndStageTop(Thunder th, Stage s);
	int ThunderAndStageRight(Thunder th, Stage s);
	int ThunderAndStageLeft(Thunder th, Stage s);

	int FishAndPlayer(Fish f, Player p);
};

