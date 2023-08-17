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
	//SE‚Ì“Ç‚Ýž‚Ý
	(SE = LoadSoundMem("sounds/SE_GameOver.wav"));
	ChangeVolumeSoundMem(70, SE);
	flg = FALSE;
}

End::~End()
{
	//SE‚Ìíœ
	DeleteSoundMem(SE);
}

AbstractScene* End::Update()
{
	if (CheckSoundMem(SE) == 0) {
		PlaySoundMem(SE, DX_PLAYTYPE_BACK, TRUE);
	}
	
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
