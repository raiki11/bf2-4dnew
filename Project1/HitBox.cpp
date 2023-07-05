#include "HitBox.h"

HitBox::HitBox()
{
}

HitBox::~HitBox()
{
}

void HitBox::UpdetaHitBox()
{
}

int HitBox::PlayerAndStage(Player p, Stage s)
{
	px0 = p.GetPlayerLocationX() - 4;
	px1 = p.GetPlayerLocationX() + 4;
	py0 = p.GetPlayerLocationY() - 4;
	py1 = p.GetPlayerLocationY() + 4;

	
	return 0;
}
