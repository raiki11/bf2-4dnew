#include "End.h"
#include <DxLib.h>
#include "PadInput.h"
#include "TitleScene.h"


End::End()
{
    image = LoadGraph("images/UI/UI_GameOver.png");
	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		enemy[i] = new Enemy(i, i);
	}
}

End::~End()
{
}

AbstractScene* End::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return new TitleScene();
	}

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

	for (int i = 0; i <= Stage::EnemyMax[Stage::Snum]; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->EnemyDraw();
		}
	}
}
