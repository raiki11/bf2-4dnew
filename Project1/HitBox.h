#pragma once
#include "Player.h"
#include "Stage.h"

class HitBox
{
private:
	int px0, px1, py0, py1;
public:
	HitBox();
	~HitBox();

	void UpdetaHitBox();
	
	int PlayerAndStage(Player p, Stage s);
};

