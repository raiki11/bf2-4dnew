#include "End.h"
#include <DxLib.h>

End::End()
{
    image = LoadGraph("images/UI/UI_GameOver.png");
}

End::~End()
{
}

AbstractScene* End::Update()
{
    return this;
}

void End::Draw() const
{
    DrawGraph(220, 220, image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	player.PlayerDraw();
	stage.DrawStage();
	UI.DrawUI();
	//enemy.EnemyDraw();
}
